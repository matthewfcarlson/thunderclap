#include "decls/data/records.h"

extern "C" CoreThread* __cdecl FUN_0026dbb0();
// the fiber running on the calling thread
extern "C" CoreFiber* __cdecl FUN_0026dbf0() {
    CoreThread* p = FUN_0026dbb0();
    if (!p)
        return 0;
    return p->current;
}
