#include "compat/ptr.h"
#include "gen/core.h"

extern "C" int __cdecl FUN_0026d8a0(hulk_uintptr*);

// releases the semaphore the requester waits on (0x00274ba0 stores its address at +8)
int core::CompletionEventRequest::vfunc_1() {
    FUN_0026d8a0((hulk_uintptr*)this->f_08);
    return 1;
}
