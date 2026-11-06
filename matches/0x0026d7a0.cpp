#include "decls/data/platform/xbox/core.h"
#include "decls/data/records.h"
// data: gSpecial = DAT_0052a138

extern void __stdcall DeleteFiber(void*);
// a fiber off its thread's fiber list; its XAPI fiber is deleted unless it is a thread's own (the converted thread)
extern "C" void __cdecl FUN_0026d7a0(void * p_) {
    CoreFiber* p = (CoreFiber*)p_;
    if (p != &DAT_0052a130.main && p != &p->thread->main)
        DeleteFiber(p->fiber);
    CoreThread* parent = p->thread;
    if (p->previous == 0)
        parent->first = p->next;
    else
        p->previous->next = p->next;
    if (p->next == 0) {
        parent->last = p->previous;
        return;
    }
    p->next->previous = p->previous;
}
