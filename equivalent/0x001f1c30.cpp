// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001f1c30 @ 0x001f1c30
#include "decls/data/game/unknown.h"

struct CSoundCommand_InstallEffect_1f1c30 { int FUN_001f09d0(int, int); }; struct Manager { void FUN_001ef260(int); };  extern CSoundCommand_InstallEffect_1f1c30* __cdecl FUN_0008d710(int,int); void __stdcall FUN_001f1c30(int value, int extra) { if (value != 0) { Manager* manager = (*(Manager**)&DAT_004e3710); if (manager != 0) { CSoundCommand_InstallEffect_1f1c30* item = FUN_0008d710(0x18,6); int result = 0; if (item != 0) result = item->FUN_001f09d0(value,extra); manager->FUN_001ef260(result); } } }