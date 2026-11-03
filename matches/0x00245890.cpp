#include "compat/ptr.h"
int FUN_00245890(hulk_intptr digits, hulk_intptr length) {
    int value = 0;
    int place = 1;
    char* p = (char*)(digits + 1);
    char* q = (char*)(digits + length - 1);
    while (q >= p) {
        value += (*q - 0x30) * place;
        place *= 10;
        --q;
    }
    return -value;
}