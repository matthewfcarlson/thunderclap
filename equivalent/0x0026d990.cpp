// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 2/2)
// FUN_0026d990 @ 0x0026d990
// The calling thread becomes a scheduler thread: its record's own fiber is the converted thread.
#include "compat/ptr.h"
#include "decls/data/platform/xbox/core.h"
#include "decls/data/records.h"

extern "C" int FUN_0020c14b();
namespace XAPILIB {
    void* __stdcall ConvertThreadToFiber(void*);
    int __stdcall SetThreadPriority(void*, int);
}
// (class-scope declarations of the TU-mates' C functions: gen_tree gives a merged C definition's other C
// declarations C++ linkage, docs/native-build.md "A gen_tree bug"; bound by the address in the name)
struct ThreadList_26d990 {
    static void __cdecl FUN_0026d8f0(unsigned int *);
};
extern "C" void __cdecl FUN_0026d990(void * self_) {
    CoreThread * self = (CoreThread *)self_;
    self->first = 0;
    self->last = 0;
    self->active = 1;
    int thread = FUN_0020c14b();
    self->threadId = thread;
    self->handle = (void*)(hulk_intptr)-2;
    self->main.state[2] = 0;
    self->main.entry = 0;
    self->main.argument = 0;
    self->main.fiber = XAPILIB::ConvertThreadToFiber(0);
    self->main.thread = self;
    self->main.state[0] = 0;
    self->main.state[1] = 0;
    self->current = &self->main;
    if (!self->first) {
        self->first = &self->main;
        self->main.previous = 0;
    } else {
        self->last->next = &self->main;
        self->main.previous = self->last;
    }
    self->last = &self->main;
    self->main.next = 0;
    ThreadList_26d990::FUN_0026d8f0((unsigned int *)self);
    self->priority = 2;
    XAPILIB::SetThreadPriority(self->handle, DAT_004cd9d8);
}
