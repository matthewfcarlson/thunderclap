#include "decls/data/records.h"

// the calling thread's record: the thread list searched by thread id
extern "C" CoreThread* DAT_0052a180 = 0;
extern "C" char DAT_0052a188[8] = {0};
typedef void(__stdcall* LockFn)(void*);
extern "C" LockFn DAT_003f2c8c;
extern "C" LockFn DAT_003f2c88;
extern "C" int __cdecl FUN_0020c14b();
extern "C" CoreThread* __cdecl FUN_0026dbb0() {
    CoreThread* p = DAT_0052a180;
    DAT_003f2c8c(DAT_0052a188);
    while (p != 0 && p->threadId != FUN_0020c14b())
        p = p->next;
    DAT_003f2c88(DAT_0052a188);
    return p;
}
