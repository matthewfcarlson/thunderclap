#include "compat/ptr.h"
struct Local {
    char data[12];
    void FUN_0023fd20(int);
    void FUN_00240060();
};
struct Result {
    unsigned char FUN_00240310(int);
};
extern "C" void * __cdecl FUN_00262400(void *, void *);
unsigned char __cdecl FUN_00262550(int first, int second) {
    Local local;
    local.FUN_0023fd20(0x100);
    unsigned char value = ((Result *)FUN_00262400((void *)(hulk_uintptr)(int)first, (Local *)(&local)))->FUN_00240310(second);
    local.FUN_00240060();
    return value;
}