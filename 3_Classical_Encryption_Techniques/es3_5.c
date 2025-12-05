/* Create a software that can emcrypt and decrypt using a 2x2 Hill cipher */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void matrix_check(int *matrix);
void hill(char *str, int *key);
int num_from_char(char c);
void invert_key(int *key);
int compute_det(int *matrix);

int main(int argc, char *argv[]){
    if(argc != 3){
        fprintf(stderr, "usage: %s <string> <key>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char str[100], temp[5];
    int key[4];
    
    strncpy(str, argv[1], 99);
    strncpy(temp, argv[2], 4);
    for(int i = 0; i < 4; i++){
        key[i] = temp[i];
    }

    matrix_check(key);

    hill(str, key);
    printf("Cipher: %s\n", str);

    invert_key(key);

    hill(str, key);
    printf("Plaintext: %s\n", str);

    return EXIT_SUCCESS;
}
void matrix_check(int *matrix){
    int det = compute_det(matrix);

    if(det % 2 == 0 || det % 13 == 0){
        printf("Matrix not invertible!\n");
        exit(EXIT_FAILURE);
    }

}
void hill(char *str, int *key){
    int p[2], c[2];

    if(strlen(str) % 2 != 0){
        strcat(str, "X");
    }

    for(char *block = str; *block != '\0'; block += 2){
        for(int i = 0; i < 2; i++){
            p[i] = num_from_char(block[i]);
        }

        for(int r = 0; r < 2; r++){
            int sum = 0;
            for(int col = 0; col < 2; col++){
                sum += key[r * 2 + col] *p[col];
            }
            c[r] = sum % 26;
            if(c[r] < 0)
                c[r] += 26;
        }
        
        for(int i = 0; i < 2; i++){
            block[i] = c[i] + 'a';
        }
    }
}
int num_from_char(char c){
    if(c >= 'a' && c <= 'z')
        return c - 'a';
    if(c >= 'A' && c <= 'Z')
        return c - 'A';
    exit(EXIT_FAILURE);
}
void invert_key(int *key){
    int det = compute_det(key);
    int det_inv = 0;

    for(int x = 1; x < 26; x++){
        if((det * x) % 26 == 1){
            det_inv = x;
            break;
        }
    }

    int a = key[0], b = key[1], c = key[2], d = key[3];

    key[0] = (det_inv * d) % 26;
    key[1] = (det_inv * -b) % 26;
    key[2] = (det_inv * -c) % 26;
    key[3] = (det_inv * a) % 26;

    for(int i = 0; i < 4; i++){
        if(key[i] < 0){
            key[i] += 26;
        }
    }
}
int compute_det(int *matrix){
    int det;

    det = matrix[0] * matrix[3] - matrix[1] * matrix[2];
    det = det % 26;

    if(det < 0)
        det += 26;

    return det;
}
