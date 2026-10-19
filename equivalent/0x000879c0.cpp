// STATUS: equivalent (tools/equiv.py level 3: 99 inputs, branch coverage 12/12)
// FUN_000879c0 @ 0x000879c0
// cl-flags: /GS
// FUN_000879c0 @ 0x000879c0
#include "decls/address.h"
#include "decls/data/game/unknown.h"
struct Screen_879c0 { void FUN_00086da0(); };
struct World { char pad0[0x54]; Screen_879c0* screen; char pad1[0x45]; unsigned char active; };
extern unsigned int __cdecl FUN_00267f80();
extern void __cdecl thunk_FUN_00270a50();
extern void __cdecl FUN_002656a0();
extern int __cdecl _sprintf(char*, const char*, ...);
extern void __cdecl FUN_001bc0c0(const char*,int,int);
void __cdecl FUN_000879c0() {
 char buffer[128];
 unsigned int start = FUN_00267f80();
 while (start + 3000u > FUN_00267f80()) {
  unsigned int before = FUN_00267f80();
  World* state = DAT_004dd700;
  if (state && state->active && state->screen) state->screen->FUN_00086da0();
  else { thunk_FUN_00270a50(); FUN_002656a0(); }
  _sprintf(buffer, "copyright-%s", DAT_004dd8d4);
  FUN_001bc0c0(buffer,2,0);
  unsigned int elapsed = FUN_00267f80() - before;
  if (elapsed > 250u) start += elapsed - 250u;
 }
}
