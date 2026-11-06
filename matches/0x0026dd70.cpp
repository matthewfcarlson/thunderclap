#include "compat/ptr.h"
#include "decls/data/records.h"

// (a class-scope declaration of the TU-mate 0x0026dd10: bound by the address in the name)
struct Fiber_26dd70 {
    static void __cdecl FUN_0026dd10(CoreFiber*, void*, void*, unsigned int, unsigned int, unsigned int);
};
// a fiber on the calling thread: 0x0026dd10 with an unused fourth argument
extern "C" void FUN_0026dd70(CoreFiber* fiber, void* entry, void* argument, unsigned int stack, unsigned int unused) {
    Fiber_26dd70::FUN_0026dd10(fiber, entry, argument, 0, stack, unused);
}
