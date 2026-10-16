// STATUS: equivalent (tools/equiv.py level 3: 99 inputs, branch coverage 26/26)
// FUN_002722b0 @ 0x002722b0
// equiv-conv: FUN_002721c0 eax
#include "decls/data/engine/core.h"

unsigned int FUN_002721c0(unsigned int value);
unsigned char __cdecl FUN_00271a30(unsigned int value, unsigned int *converted);
int __cdecl FUN_002722b0(unsigned int, unsigned char *, unsigned int, unsigned int, unsigned int *, unsigned int);
int __cdecl target(unsigned int character, unsigned char *destination, unsigned int capacity, unsigned int fallback, unsigned int *written, unsigned int mode)
{
    unsigned int length;
    unsigned char first = (unsigned char)character;
    unsigned char second = 0;
    bool invalid = false;
    if (character <= 0x7f) {
        if (mode == 1) {
            length = 2;
            if (character != 0) {
                unsigned int bytes = FUN_002721c0(character);
                if ((bytes & 0xffff) == 0) invalid = true;
                else {
                    first = (unsigned char)(bytes >> 8);
                    second = (unsigned char)bytes;
                }
            } else first = 0;
        } else length = 1;
    } else if (character >= 0xff61 && character <= 0xff9f) {
        if (mode == 1) {
            unsigned int original = character;
            character = 0;
            if (FUN_00271a30(original, &character))
                return FUN_002722b0(character, destination, capacity, fallback, written, mode);
            invalid = true;
        } else {
            length = 1;
            first = (unsigned char)(character + 0x40);
        }
    } else {
        length = 2;
        if (character & 0xffff0000) invalid = true;
        else {
            unsigned int bytes = (*(unsigned int*)&DAT_004cdca8);
            first = (unsigned char)(bytes >> 8);
            second = (unsigned char)bytes;
        }
    }
    if (invalid) {
        if (!fallback) return -4;
        int result = FUN_002722b0(fallback, destination, capacity, 0, written, mode);
        return result == -2 ? -6 : result;
    }
    if (capacity < length) return -1;
    destination[0] = first;
    if (length == 2) destination[1] = second;
    *written = length;
    return 0;
}