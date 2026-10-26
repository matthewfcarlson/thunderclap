#include "decls/data/game/global.h"
// data: gData_1b3360 = DAT_004e1830

extern "C" char* strncpy(char*, const char*, unsigned int);
void FUN_001b3360(int index, char* name, char* description, int value) {
    if (index < 0 || index >= 13)
        return;
    if (name != 0)
        strncpy(((char*)&DAT_004e1830) + index * 0xb4, name, 0x3f);
    int offset = index * 0xb4;
    ((char*)&DAT_004e1830)[offset + 0x3f] = 0;
    if (description != 0)
        strncpy(((char*)&DAT_004e1830) + offset + 0x40, description, 0x3f);
    ((char*)&DAT_004e1830)[offset + 0x7f] = 0;
    *(int*)(((char*)&DAT_004e1830) + offset + 0xb0) = value;
}