#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static size_t code_to_utf8(unsigned char* buffer, const unsigned int code)
{
    if (code <= 0x7F) {
        buffer[0] = code;
        return 1;
    }
    if (code <= 0x7FF) {
        buffer[0] = 0xC0 | (code >> 6);            /* 110xxxxx */
        buffer[1] = 0x80 | (code & 0x3F);          /* 10xxxxxx */
        return 2;
    }
    if (code <= 0xFFFF) {
        buffer[0] = 0xE0 | (code >> 12);           /* 1110xxxx */
        buffer[1] = 0x80 | ((code >> 6) & 0x3F);   /* 10xxxxxx */
        buffer[2] = 0x80 | (code & 0x3F);          /* 10xxxxxx */
        return 3;
    }
    if (code <= 0x10FFFF) {
        buffer[0] = 0xF0 | (code >> 18);           /* 11110xxx */
        buffer[1] = 0x80 | ((code >> 12) & 0x3F);  /* 10xxxxxx */
        buffer[2] = 0x80 | ((code >> 6) & 0x3F);   /* 10xxxxxx */
        buffer[3] = 0x80 | (code & 0x3F);          /* 10xxxxxx */
        return 4;
    }
    return 0;
}

static void print_utf8_and_bytes(const unsigned int code)
{
    size_t result;
    unsigned char buffer[4];
    buffer[3] = 0;
    result = code_to_utf8((unsigned char*)buffer, code);
    if(result == 3)
        printf("text: %s   code:%04x bytes: %u %u %u\n", (const char*)buffer, code, buffer[0], buffer[1], buffer[2]);
    else
        puts("Not a 3 byte utf8~~");
}

static void print_all_thai_utf8_bytes(void)
{
    unsigned start_val = 0x0e01;
    const unsigned end_Val = 0x0e5b;
    while(start_val <= end_Val) {
        if(start_val != 0x0e3b && start_val != 0x0e3c && start_val != 0x0e3d && start_val != 0x0e3e) {
            print_utf8_and_bytes(start_val);
        }
        start_val++;
    }
}

int main(void) {
  puts("----Thai tis620 -> utf-8 codes ------");
  print_all_thai_utf8_bytes();
  puts("-------------------------------------");
  return 0;
}
