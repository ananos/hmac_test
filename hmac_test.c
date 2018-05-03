#include <stdio.h>

#include "sha.h"
#define SHATYPE SHA256
int main(int argc, char **argv)
{
    int ret = 0;
    uint8_t digest[USHAHashSize(SHATYPE)];
    char *key;
    uint8_t key_len, message_len;
    char *message;

    if (argc > 1) {
        message_len = strlen(argv[1]);
        message = malloc(message_len);
        sprintf(message, "%s", argv[1]);
        if (argc > 2) {
            key_len = strlen(argv[2]);
            key = malloc(key_len);
            sprintf(key, "%s", argv[2]);
        }
    }

    hmac(SHATYPE, message, message_len, key, key_len, digest);
    for (int i = 0; i < USHAHashSize(SHATYPE); i++) {
        printf("%.2x", (uint8_t) digest[i]);
    }
    printf("\n");



    return 0;
}
