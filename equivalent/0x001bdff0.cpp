// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001bdff0 @ 0x001bdff0
#include "decls/data/game/unknown.h"

extern "C" void __fastcall __security_check_cookie(unsigned int);
extern unsigned int DAT_004d9968;
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
    unsigned int cookie = DAT_004d9968;
    char buf[0x40];
    void* found = FUN_000f7120(key);
    if (found && console) {
        console->FUN_000f7110();
        FUN_000964a0(buf, 0x40, (*(const char**)&DAT_004c4c68), arg, found);
        console->FUN_000f7a80(buf);
    }
    __security_check_cookie(cookie);
}
