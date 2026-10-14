// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0033cdb0 @ 0x0033cdb0
typedef unsigned int uint;
extern uint __cdecl FUN_00213190(uint, int);
extern uint __cdecl FUN_002131f0(uint, int);
extern uint __cdecl FUN_00213120(uint, int);
extern void __cdecl FUN_00213360(uint, uint);
extern void __cdecl FUN_00212e60(uint, int);
struct SearchState { uint base; uint end; uint owner; uint status; char rest[256]; };
extern uint __cdecl FUN_0033c7e0(SearchState*, uint, uint);
// equiv-conv: FUN_0033cb70 esi ecx eax
extern uint __cdecl FUN_0033cb70(SearchState*, uint, uint);
uint __cdecl FUN_0033cdb0(uint owner) {
 uint base = FUN_00213190(owner, -10002);
 uint length = FUN_002131f0(owner, -10002);
 uint kind = FUN_00213190(owner, -10003);
 SearchState state;
 state.owner = owner;
 state.base = base;
 state.end = length + base;
 uint current = FUN_00213120(owner, -10004) + base;
 if (current > state.end) return 0;
 uint found;
 for (;;) {
  state.status = 0;
  found = FUN_0033c7e0(&state, current, kind);
  if (found) break;
  ++current;
  if (current > state.end) return 0;
 }
 uint offset = found - base;
 if (found == current) ++offset;
 FUN_00213360(owner, offset);
 FUN_00212e60(owner, -10004);
 return FUN_0033cb70(&state, current, found);
}