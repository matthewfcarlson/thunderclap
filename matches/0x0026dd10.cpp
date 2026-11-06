#include "compat/ptr.h"
#include "decls/data/records.h"

extern "C" void __cdecl FUN_0026dc20();
extern CoreThread* FUN_0026dbb0();
extern "C" void* __stdcall CreateFiber(unsigned int, void*, void*);
// a fiber on the calling thread (appended to its fiber list), started at 0x0026dc20: entry(argument)
void __cdecl FUN_0026dd10(CoreFiber* p, void* entry, void* argument, unsigned int unused, unsigned int stack, unsigned int unused2) {
    p->state[2] = 0;
    p->entry = (int(__cdecl*)(hulk_intptr))entry;
    p->argument = (hulk_intptr)argument;
    CoreThread* l = FUN_0026dbb0();
    p->thread = l;
    if (!l->first) {
        l->first = p;
        p->previous = 0;
    } else {
        l->last->next = p;
        p->previous = l->last;
    }
    l->last = p;
    p->next = 0;
    void* r = CreateFiber(stack, (void*)((hulk_intptr)(void (__cdecl*)())&FUN_0026dc20), p);
    p->state[1] = 0;
    p->state[0] = 0;
    p->fiber = r;
}
