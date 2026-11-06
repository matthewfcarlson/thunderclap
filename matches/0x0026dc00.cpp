#include "decls/data/records.h"

extern CoreThread* FUN_0026dbb0();
namespace XAPILIB {
void __stdcall SwitchToFiber(void*);
}
extern "C" void __cdecl FUN_0026dc00(CoreFiber* target) {
    CoreThread* p = FUN_0026dbb0();
    p->current = target;
    XAPILIB::SwitchToFiber(target->fiber);
}
