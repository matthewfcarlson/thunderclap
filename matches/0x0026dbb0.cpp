#include "decls/data/platform/xbox/core.h"
#include "decls/data/records.h"

// the calling thread's record: the thread list (0x0052a180, 0x0026d8f0 appends) searched by thread id, under the
// list's critical section (0x0052a188)
typedef void(__stdcall* LockFn)(void*);
extern "C" LockFn DAT_003f2c8c;
extern "C" LockFn DAT_003f2c88;
extern "C" int __cdecl FUN_0020c14b();
extern "C" CoreThread* __cdecl FUN_0026dbb0() {
    CoreThread* p = *(CoreThread**)&DAT_0052a180;
    DAT_003f2c8c(DAT_0052a188);
    while (p != 0 && p->threadId != FUN_0020c14b())
        p = p->next;
    DAT_003f2c88(DAT_0052a188);
    return p;
}
