#include <stdio.h>

#include "sha.h"
//#include "aes_ni.h"
#define SHATYPE SHA1
int main(int argc, char ** argv)
{
    int ret = 0;
    uint8_t digest[USHAHashSize(SHATYPE)];
    char *key;
    uint8_t key_len,message_len;
    char * message;
    if (argc > 1) {
        printf("param given: %s\n", argv[1]);
        message_len = strlen(argv[1]);
        message = malloc(message_len);
        sprintf(message, "%s", argv[1]);
        if (argc > 2) {
            printf("second param: %s\n", argv[2]);
            key_len = strlen(argv[2]);
            key = malloc(key_len);
            sprintf(key, "%s", argv[2]);
        }
    }
    
    printf ("message: %s\n", message);
    printf ("key: %s\n", key);
    printf ("ret: %d\n", ret);
    hmac(SHATYPE, message, message_len, key, key_len, digest); 
    printf ("digest: ");
    for (int i=0;i<USHAHashSize(SHATYPE);i++) {
        printf("%.2x", (uint8_t)digest[i]);
    }
    printf ("\n");



    return 0;
}

