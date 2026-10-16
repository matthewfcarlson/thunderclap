// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_00327c20 @ 0x00327c20
#include "decls/data/engine/pure3d.h"

struct Entry_327c20 { char text[64]; unsigned int value1; unsigned int value2; };
void __cdecl FUN_00327c20(const char* text, unsigned int value1, unsigned int value2)
{
    unsigned int index = (*(unsigned int*)&DAT_005555c0);
    char* out = ((Entry_327c20*)&DAT_005555c8)[index].text;
    char c;
    do { c = *text++; *out++ = c; } while (c != 0);
    (*(unsigned int*)&DAT_005555c0) = index + 1;
    ((Entry_327c20*)&DAT_005555c8)[index].value1 = value1;
    ((Entry_327c20*)&DAT_005555c8)[index].value2 = value2;
}
