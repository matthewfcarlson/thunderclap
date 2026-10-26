// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// CInvincibleTrack::vfunc_12 @ 0x0006a0e0
#include "compat/ptr.h"
#include "gen/global.h"

struct Object_6a0e0 { int FUN_0001f4e0(hulk_intptr, int); }; Object_6a0e0* __cdecl FUN_0008d690(int);  
hulk_intptr CInvincibleTrack::vfunc_12(hulk_intptr arg) { Object_6a0e0* p = FUN_0008d690(0x24); if (p) return p->FUN_0001f4e0(arg, this->f_14); return 0; }
