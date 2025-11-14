/* Write a program that can encrypt and decrypt using the general   *
 * Caesa cipher                                                     */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void affine(int key, char *str);

int main(int argc, char *argv[]){
    if(argc < 3){
        fprintf(stderr, "usage: %s <string> <key>\n", argv[0]);
        return EXIT_FAILURE;
    }
    char str[100];
    int key = atoi(argv[2]);
    strncpy(str, argv[1], 99);

    affine(key, str);

    printf("encrypter string: %s\n", str);

    affine(-key, str);
    printf("decrypter string: %s\n", str);

    return EXIT_SUCCESS;
}
void affine(int key, char *str){
    
    for(int i = 0; *(str + i); i++){
        if(*(str + i) >= 'a' && *(str + i) <= 'z'){
            *(str + i) = 'a' +( (*(str + i) - 'a' + key) % 26 + 26) % 26;
        } else if(*(str + i) >= 'A' && *(str + i) <= 'Z') {
            *(str + i) = 'A' +( (*(str + i) - 'A' + key) % 26 + 26) % 26;
        }
    }
}
