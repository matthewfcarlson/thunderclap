// A new scheduler thread (0x0026dc50 starts it: the record, its fiber's entry and argument, the priority, the stack)
#include "compat/ptr.h"
#include "decls/data/records.h"
extern "C" void _ReadWriteBarrier(void);
int __cdecl FUN_0026dc50(CoreThread *worker, int (__cdecl *entry)(hulk_intptr), hulk_intptr argument, int priority, unsigned long stackSize);
extern "C" void __cdecl FUN_0026dce0(CoreThread *worker, int (__cdecl *entry)(hulk_intptr), hulk_intptr argument, int priority, unsigned long stackSize) {
    FUN_0026dc50(worker, entry, argument, priority, stackSize);
    _ReadWriteBarrier();
}
