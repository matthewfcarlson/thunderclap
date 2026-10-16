// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_0026e650 @ 0x0026e650
#include "decls/data/engine/core.h"

namespace core {
struct IRefCount { virtual void dummy(); ~IRefCount() throw() {} };
struct BaseObject { virtual void dummy(); ~BaseObject() throw() {} };
struct Handler_26e650 { virtual void slot0(); virtual void slot1(); char pad[0x60]; char data[8]; void FUN_0026e140(void *, int); void FUN_0026e3c0(void *); };
struct DebugConsole : IRefCount, BaseObject { int value; char pad[0x98]; Handler_26e650 *handler; ~DebugConsole() throw(); };
}
struct Registration_26e650 { int size; core::DebugConsole *object; };
void __cdecl FUN_0026ef40(void *, Registration_26e650 *, int, int);
core::DebugConsole::~DebugConsole() throw() {
    core::Handler_26e650 *h = handler;
    Registration_26e650 reg = { 8, this };
    FUN_0026ef40(h->data, &reg, 8, 0);
    h->FUN_0026e140(&reg, 8);
    handler->FUN_0026e3c0(this);
    handler->slot1();
    DAT_004cdbb0 = value;
}
