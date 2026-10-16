// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 10/10)
// FUN_0023fd60 @ 0x0023fd60
#include "decls/data/engine/audio.h"

void __cdecl FUN_00247570(void* p);

class SharedStr;
void __cdecl FUN_0023fa40(char** data, char* src, int len, int len2);

class SharedStr {
public:
    char* data;                 // 0x0
    unsigned short mode;        // 0x4
    unsigned short pad6;
    unsigned short len;         // 0x8
    SharedStr* FUN_0023fd60(char* src, int length, int newMode);
};

// Releases the old buffer reference, then takes the new data in the given mode.
SharedStr* SharedStr::FUN_0023fd60(char* src, int length, int newMode)
{
    if (mode == 2) {
        char* old = data;
        if (*(short*)(old - 4) == 1) {
            if (old != (*(char**)&DAT_004cc02c))
                FUN_00247570(old - 8);
        } else {
            (*(short*)(old - 4))--;
        }
    }
    mode = (unsigned short)newMode;
    len = (unsigned short)length;
    if (newMode != 0 && newMode != 1)
        FUN_0023fa40(&src, src, length, length);
    data = src;
    return this;
}
