#include "compat/ptr.h"
#include "decls/data/platform/xbox/core.h"
#include "decls/data/records.h"

extern "C" void FUN_00272540(void);
// (class-scope declarations of the TU-mates' C functions: gen_tree gives a merged C definition's other C
// declarations C++ linkage, docs/native-build.md "A gen_tree bug"; bound by the address in the name)
struct Thread_26da80 {
    static void __cdecl FUN_0026d990(void *);
};
extern "C" void(__stdcall* DAT_003f2d38)(void*);   // kernel import slot RtlInitializeCriticalSection
extern "C" void FUN_0026da80(int unused) {
    DAT_003f2d38((void*)((hulk_intptr)((char*)&DAT_0052a188)));
    *(volatile unsigned char*)((hulk_intptr)DAT_0052a184) = 1;
    FUN_00272540();
    Thread_26da80::FUN_0026d990(&DAT_0052a130);
}
