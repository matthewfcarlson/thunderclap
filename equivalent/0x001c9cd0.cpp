// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001c9cd0 @ 0x001c9cd0
#include "compat/ptr.h"
struct Item { hulk_uintptr size, kind, a, b, c, d, first, second; Item* FUN_001c9cd0(unsigned int x, unsigned int y); }; struct Args { unsigned int x,y; void FUN_0027af50(); }; Item* Item::FUN_001c9cd0(unsigned int x,unsigned int y) { size=0; kind=0; a=0; b=0; c=0; d=0; first=0; second=0; size=32; kind=7; first=x; second=y; ((Args*)&x)->FUN_0027af50(); return this; }