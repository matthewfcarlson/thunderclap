// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00266be0 @ 0x00266be0
#include "gen/owners.h"
struct Context { int FUN_00263fc0();  }; struct State { char pad[0x88]; struct Entry { int first; int second; char rest[8]; } entries[31]; char spare[8]; int index; Context* context; void FUN_00266be0(); }; void State::FUN_00266be0() { int first = entries[index].first; int second = entries[index].second; int used = context->FUN_00263fc0(); ((owners::S_264510 *)context)->FUN_00264510((unsigned)(first + second - used)); --index; }