#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "sha.h"
#define SHATYPE SHA256
int main(int argc, char **argv)
{
    int ret = 0;
    uint8_t digest[USHAHashSize(SHATYPE)];
    char *key = "My secret key";
    uint8_t key_len = strlen(key);
    char *message = "This is my message";
    uint8_t message_len = strlen(message);

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

    if ((ret = hmac(SHATYPE, (const unsigned char*) message, message_len, (const unsigned char*) key, key_len, digest) != 0)) {
        printf("Error, ret: %d\n", ret);
    }

    for (int i = 0; i < USHAHashSize(SHATYPE); i++) {
        printf("%.2x", (uint8_t) digest[i]);
    }
    printf("\n");

    return ret;
}
