/*  Write a program that can perform a letter frequency attack on an    *
 *  additive cipher without human intervention.                         *
 *  The software shoul produce possible plaintexts in rough order of    *
 *  likelihood.                                                         *
 *  Specify the top N possible plaintexts                               */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char modulo_sum(char c, int key);
void en_de(int key, char *str);
void freq_count(FILE *c_text, int *letters);
void print_possible_plaintext(int n, int *letters, FILE *c_text);
int try(int *freq, int *used);

int main(int argc, char *argv[]){
    if(argc < 4){
        fprintf(stderr, "usage: %s <file.txt> <single_key> <N_possible_plaintext>\n", argv[0]);
        return EXIT_FAILURE;
    }
    FILE *plain_f, *cipher_f;
    char buffer[1024];
    int key = atoi(argv[2]), n = atoi(argv[3]), i;
    int letters[26] = {0};

    if((plain_f = fopen(argv[1], "r"))== NULL){
        fprintf(stderr, "error: fopen()");
        return EXIT_FAILURE;
    }
    if((cipher_f = fopen("c.txt", "w+")) == NULL){
        fprintf(stderr, "error: fopen()");
        return EXIT_FAILURE;
    }

    while(fgets(buffer, sizeof(buffer), plain_f) != NULL){
        en_de(key, buffer);
        fputs(buffer, cipher_f);
    }

    freq_count(cipher_f, letters);

    printf("The letters frequency are:\n");
    for(i = 0; i < 26; i++){
        printf("%c\t%d\n", i+65, letters[i]);
    }

    print_possible_plaintext(n, letters, cipher_f);

    if(fclose(plain_f) == EOF){
        fprintf(stderr, "error: fclose()");
        return EXIT_FAILURE;
    }
    if(fclose(cipher_f) == EOF){
        fprintf(stderr, "error: fclose()");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
char modulo_sum(char c, int key){
    if(c >= 'A' && c <= 'Z'){
        c = 'A' + ((c - 'A' + key) % 26 + 26) % 26;
    } else if (c >= 'a' && c <= 'z'){
        c = 'a' + ((c - 'a' + key) % 26 + 26) % 26;
    }
    return c;
}
void en_de(int key, char *str){
    for(int i = 0; *(str + i); i++){
        *(str + i) = modulo_sum(*(str + i), key);
    }
}
void freq_count(FILE *c_text, int *letters){
    int letters_count = 0;
    char buf[1024];

    fseek(c_text, 0, SEEK_SET);
    while((fgets(buf, sizeof(buf), c_text)) != NULL){
        for(int i = 0; buf[i] != '\0'; i++){
            if(buf[i] >= 'A' && buf[i] <= 'Z'){
                buf[i] += 32;
            }
            if(buf[i] >= 'a' && buf[i] <= 'z'){
                letters_count++;
                letters[buf[i] - 97]++;
            }
        }
    }

    printf("There are %d letters\n", letters_count);  
}
void print_possible_plaintext(int n, int *letters, FILE *c_text){
    int used[26] = {0};
    int shift, max_i;
    char buf[1024]; 
    
    for(int k = 1; k <= n; k++){
        max_i = try(letters, used);
        if(max_i < 0){
            return;
        } 
        used[max_i] = 1;
        shift = (('E' - 'A' - max_i + 26) % 26);

        printf("Try n.%d (assuming '%c' -> 'e', shift = %d):\n", k, 'a' + max_i, shift);

        fseek(c_text, 0, SEEK_SET);
        while(fgets(buf, sizeof(buf), c_text) != NULL){
            en_de(shift, buf);
            printf("%s\n", buf);
        }

        printf("\n\n");
    }
}
int try(int *freq, int *used){
    int max_i = -1, max_v = -1;

    for(int i = 0; i < 26; i++){
        if(!used[i] && freq[i] > max_v){
            max_v = freq[i];
            max_i = i;
        }
    }

    return max_i;
}
