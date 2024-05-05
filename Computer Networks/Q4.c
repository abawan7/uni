#include <stdio.h>

int main() {
    short int n = 0x3412;
    char *byte_p = (char*)&n;

    printf("memory representation: ");
    for(int i = 0; i < sizeof(n); i++) {
        printf("Byte[%d]: %02X\n ", i, byte_p[i]);
    }

    if (byte_p[0] != 0x12) {
        printf("Big Endian.\n");
        
    } else {
        printf("Little Endian.\n");
    }

    return 0;
}
