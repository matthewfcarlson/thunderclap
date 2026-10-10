// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_0026e650 @ 0x0026e650
namespace core {
struct IRefCount { virtual void dummy(); ~IRefCount() throw() {} };
struct BaseObject { virtual void dummy(); ~BaseObject() throw() {} };
struct Handler { virtual void slot0(); virtual void slot1(); char pad[0x60]; char data[8]; void FUN_0026e140(void *, int); void FUN_0026e3c0(void *); };
struct DebugConsole : IRefCount, BaseObject { int value; char pad[0x98]; Handler *handler; ~DebugConsole() throw(); };
}
struct Registration { int size; core::DebugConsole *object; };
void __cdecl FUN_0026ef40(void *, Registration *, int, int);
extern int DAT_004cdbb0;
core::DebugConsole::~DebugConsole() throw() {
    core::Handler *h = handler;
    Registration reg = { 8, this };
    FUN_0026ef40(h->data, &reg, 8, 0);
    h->FUN_0026e140(&reg, 8);
    handler->FUN_0026e3c0(this);
    handler->slot1();
    DAT_004cdbb0 = value;
}
