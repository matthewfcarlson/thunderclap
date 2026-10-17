// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001c9e70 @ 0x001c9e70
struct Obj { unsigned a,b,c,d,e,f,g,h; Obj* FUN_001c9e70(unsigned x,unsigned y); }; struct Arg { unsigned x,y; void FUN_0027af50(); }; Obj* Obj::FUN_001c9e70(unsigned x,unsigned y) { a=0; b=0; c=0; d=0; e=0; f=0; g=0; h=0; a=32; b=9; g=x; h=y; ((Arg*)&x)->FUN_0027af50(); return this; }