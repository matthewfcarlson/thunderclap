#include "compat/ptr.h"
#include "decls/data/platform/xbox/core.h"
#include "decls/data/records.h"

// (class-scope declarations of the TU-mates' C functions: gen_tree gives a merged C definition's other C
// declarations C++ linkage, docs/native-build.md "A gen_tree bug"; bound by the address in the name)
struct ThreadList_26dad0 {
    static void __cdecl FUN_0026d940(void *);
};
extern "C" void __cdecl FUN_0026d7a0(void *);
extern "C" int __cdecl FUN_0020c14b();
extern "C" void __stdcall FUN_0020bbc2(hulk_intptr);   // CloseHandle
extern "C" void __stdcall FUN_0020c6f7(hulk_intptr, int);   // WaitForSingleObject
namespace XAPILIB {
void __stdcall ExitThread(int);
}
extern "C" void(__stdcall* DAT_003f2c8c)(void*);
extern "C" void(__stdcall* DAT_003f2c88)(void*);
extern "C" void __cdecl FUN_0026dad0(CoreThread* job) {
    ThreadList_26dad0::FUN_0026d940((CoreThread *)job);
    DAT_003f2c8c(((char*)&DAT_0052a188));
    if (job->active) {
        if (job->threadId == FUN_0020c14b()) {
            FUN_0026d7a0(&job->main);
            DAT_003f2c88(((char*)&DAT_0052a188));
            FUN_0020bbc2((hulk_intptr)job->handle);
            XAPILIB::ExitThread(0);
        }
        FUN_0026d7a0(&job->main);
        DAT_003f2c88(((char*)&DAT_0052a188));
        return;
    }
    FUN_0026d7a0(&job->main);
    DAT_003f2c88(((char*)&DAT_0052a188));
    FUN_0020c6f7((hulk_intptr)job->handle, -1);
    FUN_0020bbc2((hulk_intptr)job->handle);
}