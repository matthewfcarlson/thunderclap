// STATUS: equivalent (tools/equiv.py level 3: 76 inputs, branch coverage 9/10, incomplete)
// FUN_0023fe50 @ 0x0023fe50
#include "decls/data/engine/audio.h"
#include "gen/owners.h"

struct StringHeader_23fe50 { unsigned int capacity; unsigned short references; unsigned short reserved; };
extern void __cdecl FUN_00247570(StringHeader_23fe50*);
extern "C" void __cdecl FUN_0023fa40(int *, char *, unsigned int, int);
owners::String_23fe50* owners::String_23fe50::FUN_0023fe50(const char* source) {
    if (kind == 2) {
        StringHeader_23fe50* header = reinterpret_cast<StringHeader_23fe50*>(data) - 1;
        if (header->references == 1) {
            if (data != (*(char**)&DAT_004cc02c)) FUN_00247570(header);
        } else {
            --header->references;
        }
    }
    if (source) {
        unsigned int count = 0;
        while (source[count]) ++count;
        length = (unsigned short)count;
        kind = 2;
        FUN_0023fa40((int *)(const char * *)(&source), (char *)(const char *)source, count, (unsigned int)count);
        data = const_cast<char*>(source);
    } else {
        data = (*(char**)&DAT_004cc02c);
        ++(reinterpret_cast<StringHeader_23fe50*>((*(char**)&DAT_004cc02c)) - 1)->references;
        length = 0;
        kind = 2;
    }
    return this;
}
