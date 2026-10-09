typedef unsigned char byte; typedef unsigned int u32; extern void __cdecl FUN_00267090(u32); extern void __cdecl FUN_00266f00(u32,void*); extern u32 global; extern int vtMain,vt4,vtBase,vtRef;
struct Helper { virtual void f0(); virtual void f1(); };
class TimerList { public: virtual void v0(); virtual void v1(); virtual TimerList* v2(byte); virtual void v3(); virtual void v4(); virtual void v5(); char p0[4]; u32 field8; char pad[12]; Helper* helper; u32 pad1; u32 field20; };
TimerList* TimerList::v2(byte p){ u32 x=field20; *(u32*)this=(u32)&vtMain; *((u32*)this+1)=(u32)&vt4; FUN_00267090(x); helper->f1(); global=field8; *((u32*)this+1)=(u32)&vtBase; *(u32*)this=(u32)&vtRef; if(p&1) FUN_00266f00(global,this); return this; }
