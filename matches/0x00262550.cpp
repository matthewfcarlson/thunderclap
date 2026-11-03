#include "compat/ptr.h"
#include "gen/owners.h"
struct Local {
    char data[12];
};
struct Result {
    unsigned char FUN_00240310(int);
};
extern "C" void * __cdecl FUN_00262400(void *, void *);
unsigned char __cdecl FUN_00262550(int first, int second) {
    Local local;
    ((owners::Thing_23fd20 *)&local)->FUN_0023fd20(0x100);
    unsigned char value = ((Result *)FUN_00262400((void *)(hulk_uintptr)(int)first, (Local *)(&local)))->FUN_00240310(second);
    ((owners::Str_240060 *)&local)->FUN_00240060();
    return value;
}