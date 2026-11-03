// STATUS: equivalent (tools/equiv.py level 3: 20020 inputs, branch coverage 26/26)
// FUN_002787c0 @ 0x002787c0
#include "decls/data/platform/xbox/core.h"
#include "gen/owners.h"

struct Service_2787c0 { void FUN_00278060();  }; 
struct XboxSaveDrive_2787c0 {  int FUN_002787c0(unsigned int); };
int XboxSaveDrive_2787c0::FUN_002787c0(unsigned int value) { if(value<=0x11) { switch(value) {case 0:return 0;case 2:case 3:case 15:return 1;case 11:return 5;case 17:return 3;default:return 8;} } switch(value) { case 0x1a:return 11; case 0x1b:case 0x3ed:return 5; case 0x22:return 3; case 0x55:return 0; case 0x70:return 7; case 0x48f: { (*(Service_2787c0*)&DAT_0052a228).FUN_00278060(); unsigned int first; ((owners::Obj_2783d0 *)this)->FUN_002783d0((int *)(&first), (int *)(&value)); return ((owners::Bits_2780c0 *)&((*(Service_2787c0*)&DAT_0052a228)))->FUN_002780c0((int)first, (int)value)?3:4; } default:return 8; } }