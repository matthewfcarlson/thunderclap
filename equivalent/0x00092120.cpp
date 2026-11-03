// STATUS: equivalent (tools/equiv.py level 3: 2987 inputs, branch coverage 8/8)
// FUN_00092120 @ 0x00092120
#include "gen/owners.h"
extern "C" void __cdecl FUN_0008d340(void *);
extern "C" void * __cdecl FUN_0008d6d0(unsigned int);
void owners::TextOwner_92120::FUN_00092120(const char *source) {
    if (text) {
        FUN_0008d340(text);
        text = 0;
    }
    if (source) {
        const char *end = source;
        while (*end) ++end;
        char *destination = (char *)FUN_0008d6d0((unsigned int)(end - source + 1));
        text = destination;
        do {
            *destination++ = *source;
        } while (*source++);
    }
}