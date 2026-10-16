// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_0026ed80 @ 0x0026ed80
#include "decls/data/engine/core.h"

void FUN_002705f0();
void FUN_0026e9e0(void *, void *, unsigned int);
namespace core {
struct Object { virtual void obj(); int initialValue; };
struct RefCount : Object { virtual void obj(); int enabled; };
struct IDebugConsole { virtual void debug(); };
struct ConsoleOwner { char pad[0x1d4]; void *console; void FUN_0026e030(); };
struct DebugConsole : IDebugConsole, RefCount {
void debug(); void obj();
void *previous;
unsigned char state; char pad15[0x87];
int value9c; int valuea0; ConsoleOwner *owner;
unsigned char mode; char padA9[0x1c03];
int value1cac; int value1cb0;
DebugConsole *FUN_0026ed80(void *, unsigned char);
};
}
core::DebugConsole *core::DebugConsole::FUN_0026ed80(void *arg, unsigned char flag) {
this->IDebugConsole::IDebugConsole();
this->Object::Object();
initialValue = DAT_004cdbb0;
FUN_002705f0();
this->RefCount::RefCount();
enabled = 1;
FUN_002705f0();
this->DebugConsole::DebugConsole();
value9c = 0; valuea0 = 0; mode = flag;
value1cac = 0; value1cb0 = 0; state = 0;
FUN_002705f0();
FUN_0026e9e0(&owner, arg, mode);
previous = owner->console;
owner->console = this;
owner->FUN_0026e030();
return this;
}