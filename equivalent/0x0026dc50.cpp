// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 0/0)
// FUN_0026dc50 @ 0x0026dc50
// A new scheduler thread: its record's own fiber runs entry(argument) on a thread 0x0026db70 starts.
#include "compat/ptr.h"
#include "decls/data/platform/xbox/core.h"
#include "decls/data/records.h"

// (class-scope declarations of the TU-mates' C functions: gen_tree gives a merged C definition's other C
// declarations C++ linkage, docs/native-build.md "A gen_tree bug"; bound by the address in the name)
struct Thread_26dc50 {
    static void __cdecl FUN_0026d8f0(unsigned int *);
    static int __stdcall FUN_0026db70(CoreThread *);
};
namespace XAPILIB {
void * __stdcall CreateThread(void *, unsigned long, unsigned long (__stdcall *)(void *), void *, unsigned long, unsigned long *);
int __stdcall SetThreadPriority(void *, int);
}
int __stdcall FUN_0020bd91(void *);
int __cdecl FUN_0026dc50(CoreThread *worker, int (__cdecl *entry)(hulk_intptr), hulk_intptr argument, int priority, unsigned long stackSize) {
    worker->active = 1;
    worker->current = &worker->main;
    worker->main.state[2] = 0;
    worker->main.entry = entry;
    worker->main.argument = argument;
    worker->main.thread = worker;
    worker->main.fiber = 0;
    worker->main.state[0] = 0;
    worker->main.state[1] = 0;
    worker->first = &worker->main;
    worker->main.previous = 0;
    worker->last = &worker->main;
    worker->main.next = 0;
    Thread_26dc50::FUN_0026d8f0((unsigned int *)worker);
    worker->handle = XAPILIB::CreateThread(0, stackSize, (unsigned long (__stdcall *)(void *))Thread_26dc50::FUN_0026db70, worker, 4, (unsigned long *)&worker->threadId);
    worker->main.state[1] = 0;
    worker->priority = priority;
    XAPILIB::SetThreadPriority(worker->handle, DAT_004cd9d0[priority]);
    return FUN_0020bd91(worker->handle);
}
