typedef unsigned char u8; typedef unsigned int u32;
void __cdecl thunk_FUN_00267090(void*);
struct Obj { char pad[0x30]; u32 b; u32 b2; char gap[8]; u32 a; u32 a2; Obj* f(u8); };
Obj* Obj::f(u8 flag) { u32 x=a; a2=x; if(x) thunk_FUN_00267090((void*)x); x=b; b2=x; if(x) thunk_FUN_00267090((void*)x); if(flag&1) thunk_FUN_00267090(this); return this; }