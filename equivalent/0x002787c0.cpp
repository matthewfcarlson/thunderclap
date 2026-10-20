// STATUS: equivalent (tools/equiv.py level 3: 20018 inputs, branch coverage 25/25)
// FUN_002787c0 @ 0x002787c0
#include "decls/data/platform/xbox/core.h"

struct Service_2787c0 { void FUN_00278060(); bool FUN_002780c0(unsigned int, unsigned int); }; 
struct Object { void FUN_002783d0(unsigned int*,unsigned int*); int FUN_002787c0(unsigned int); };
int Object::FUN_002787c0(unsigned int value) { if(value<=0x11) { switch(value) {case 0:return 0;case 2:case 3:case 15:return 1;case 11:return 5;case 14:return 7;case 17:return 3;default:return 8;} } switch(value) { case 0x1a:return 11; case 0x1b:case 0x3ed:return 5; case 0x22:return 3; case 0x55:return 0; case 0x70:return 7; case 0x48f: { (*(Service_2787c0*)&DAT_0052a228).FUN_00278060(); unsigned int first; FUN_002783d0(&first,&value); return (*(Service_2787c0*)&DAT_0052a228).FUN_002780c0(first,value)?3:4; } default:return 8; } }