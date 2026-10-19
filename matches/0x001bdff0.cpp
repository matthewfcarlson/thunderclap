// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001bdff0 @ 0x001bdff0
// cl-flags: /GS
#include "decls/data/game/unknown.h"

void* __cdecl FUN_000f7120(int key);
int __cdecl FUN_000964a0(char* buf, int size, const char* fmt, int a, void* b);
class Console_1bdff0 {
public:
    void FUN_000f7110();
    void FUN_000f7a80(const char* text);
};
class Subtitle {
public:
    char pad0[0x38];
    Console_1bdff0* console;
    char pad3c[0xc];
    int key;
    void FUN_001bdff0(int arg);
};
void Subtitle::FUN_001bdff0(int arg) {
    char buf[0x40];
    void* found = FUN_000f7120(key);
    if (found && console) {
        console->FUN_000f7110();
        FUN_000964a0(buf, 0x40, (*(const char**)&DAT_004c4c68), arg, found);
        console->FUN_000f7a80(buf);
    }
}
