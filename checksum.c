/*
 * checksum.c
 * Image integrity validator for MedRead
 *
 * © 2025 Rohit Kattimani
 * All Rights Reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BUF_SIZE 8192

static uint32_t crc32_table[256];

/* Initialize CRC32 lookup table */
void init_crc32() {
    uint32_t polynomial = 0xEDB88320;
    for (uint32_t i = 0; i < 256; i++) {
        uint32_t c = i;
        for (int j = 0; j < 8; j++) {
            if (c & 1)
                c = polynomial ^ (c >> 1);
            else
                c >>= 1;
        }
        crc32_table[i] = c;
    }
}

/* Compute CRC32 for a file */
uint32_t crc32_file(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror(filename);
        return 0;
    }

    uint8_t buffer[BUF_SIZE];
    uint32_t crc = 0xFFFFFFFF;
    size_t bytes;

    while ((bytes = fread(buffer, 1, BUF_SIZE, fp)) > 0) {
        for (size_t i = 0; i < bytes; i++) {
            crc = crc32_table[(crc ^ buffer[i]) & 0xFF] ^ (crc >> 8);
        }
    }

    fclose(fp);
    return crc ^ 0xFFFFFFFF;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image1> [image2 ...]\n", argv[0]);
        return 1;
    }

    init_crc32();

    for (int i = 1; i < argc; i++) {
        uint32_t checksum = crc32_file(argv[i]);
        if (checksum != 0) {
            printf("%s : %08X\n", argv[i], checksum);
        }
    }

    return 0;
}
