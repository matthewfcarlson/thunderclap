// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000c7a10 @ 0x000c7a10
struct Sub { void FUN_0027af00(); char data[8]; }; struct Obj { int a,b,c,d; Sub sub; int f18,f1c,f20,f24,f28,f2c,f30,f34; Obj* FUN_000c7a10(); }; Obj* Obj::FUN_000c7a10() { a=b=c=d=0; sub.FUN_0027af00(); f18=f1c=f20=f24=f28=f2c=0; f30=f34=-1; return this; }