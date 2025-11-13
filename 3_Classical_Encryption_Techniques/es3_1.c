/* Write a program that can encrypt and decrypt using the general   *
 * Caesa cipher                                                     */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void caesar(int key, char *str);

int main(int argc, char *argv[]){
    if(argc < 2){
        fprintf(stderr, "usage: %s <string>\n", argv[0]);
        return EXIT_FAILURE;
    }
    char str[100];
    strncpy(str, argv[1], 99);

    caesar(3, str);

    printf("encrypter string: %s\n", str);

    caesar(-3, str);
    printf("decrypter string: %s\n", str);

    return EXIT_SUCCESS;
}
void caesar(int key, char *str){
    
    for(int i = 0; *(str + i); i++){
        if(*(str + i) >= 'a' && *(str + i) <= 'z'){
            *(str + i) = 'a' +( (*(str + i) - 'a' + key) % 26 + 26) % 26;
        } else if(*(str + i) >= 'A' && *(str + i) <= 'Z') {
            *(str + i) = 'A' +( (*(str + i) - 'A' + key) % 26 + 26) % 26;
        }
    }
}
