// STATUS: equivalent (tools/equiv.py level 3: 3025 inputs, branch coverage 10/10)
// FUN_0023fbb0 @ 0x0023fbb0
#include "decls/data/engine/audio.h"
#include "gen/owners.h"

struct StringHeader_23fbb0 { unsigned int capacity; unsigned short references; unsigned short reserved; };
extern void __cdecl FUN_00247570(StringHeader_23fbb0*);
extern "C" void __cdecl FUN_0023fa40(int *, char *, unsigned int, int);


// Makes the text private to this string (copy on write) and returns it.
char* owners::String_23fbb0::FUN_0023fbb0()
{
    int fresh;
    if (kind == 0) {
        FUN_0023fa40(&fresh, data, (int)length, length);
        data = (char*)fresh;
        return data;
    }
    StringHeader_23fbb0* header = reinterpret_cast<StringHeader_23fbb0*>(data) - 1;
    if (header->references > 1) {
        FUN_0023fa40(&fresh, data, (int)length, length);
        if (kind == 2) {
            header = reinterpret_cast<StringHeader_23fbb0*>(data) - 1;
            if (header->references == 1) {
                if (data != (*(char**)&DAT_004cc02c))
                    FUN_00247570(header);
            } else {
                --header->references;
            }
        }
        data = (char*)fresh;
    }
    return data;
}
