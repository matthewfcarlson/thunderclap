#include "decls/data/records.h"

typedef unsigned int u32_26db70;
extern "C" void* __stdcall ConvertThreadToFiber(void*);
// a new thread's start routine (0x0026dc50): its own fiber runs the entry
extern "C" int __stdcall FUN_0026db70(CoreThread* p) {
    p->main.state[0] = 0;
    p->main.fiber = ConvertThreadToFiber(0);
    p->result = p->main.entry(p->main.argument);
    p->active = 0;
    p->main.state[2] = 0;
    return 0;
}
