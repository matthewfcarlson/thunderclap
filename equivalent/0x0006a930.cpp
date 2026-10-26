// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// CUninterruptibleTrack::vfunc_12 @ 0x0006a930
#include "compat/ptr.h"
#include "gen/global.h"

 void* __cdecl FUN_0008d690(int); struct CUninterruptibleAction_6a930 { void* FUN_00020020(int arg, int value); }; 
hulk_intptr CUninterruptibleTrack::vfunc_12(hulk_intptr arg) { CUninterruptibleAction_6a930* item = (CUninterruptibleAction_6a930*)FUN_0008d690(0x24); if (!item) return (int)(0); return (hulk_intptr)(item->FUN_00020020(arg, this->f_14)); }
