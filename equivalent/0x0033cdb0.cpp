// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0033cdb0 @ 0x0033cdb0
typedef unsigned int uint_33cdb0;
extern uint_33cdb0 __cdecl FUN_00213190(uint_33cdb0, int);
extern uint_33cdb0 __cdecl FUN_002131f0(uint_33cdb0, int);
extern uint_33cdb0 __cdecl FUN_00213120(uint_33cdb0, int);
extern void __cdecl FUN_00213360(uint_33cdb0, uint_33cdb0);
extern void __cdecl FUN_00212e60(uint_33cdb0, int);
struct SearchState { uint_33cdb0 base; uint_33cdb0 end; uint_33cdb0 owner; uint_33cdb0 status; char rest[256]; };
extern uint_33cdb0 __cdecl FUN_0033c7e0(SearchState*, uint_33cdb0, uint_33cdb0);
// equiv-conv: FUN_0033cb70 esi ecx eax
extern uint_33cdb0 __cdecl FUN_0033cb70(SearchState*, uint_33cdb0, uint_33cdb0);
uint_33cdb0 __cdecl FUN_0033cdb0(uint_33cdb0 owner) {
 uint_33cdb0 base = FUN_00213190(owner, -10002);
 uint_33cdb0 length = FUN_002131f0(owner, -10002);
 uint_33cdb0 kind = FUN_00213190(owner, -10003);
 SearchState state;
 state.owner = owner;
 state.base = base;
 state.end = length + base;
 uint_33cdb0 current = FUN_00213120(owner, -10004) + base;
 if (current > state.end) return 0;
 uint_33cdb0 found;
 for (;;) {
  state.status = 0;
  found = FUN_0033c7e0(&state, current, kind);
  if (found) break;
  ++current;
  if (current > state.end) return 0;
 }
 uint_33cdb0 offset = found - base;
 if (found == current) ++offset;
 FUN_00213360(owner, offset);
 FUN_00212e60(owner, -10004);
 return FUN_0033cb70(&state, current, found);
}