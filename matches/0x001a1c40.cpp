typedef unsigned int u32;
struct Track { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); };
struct Param {};
struct LuaTrack : Track, Param { virtual u32 f10(u32,u32,u32); };
struct Helper { u32 call(u32,u32,u32); };
extern "C" void* __cdecl FUN_0008d690(int);
u32 LuaTrack::f10(u32 a,u32 b,u32 c) { Helper* p=(Helper*)FUN_0008d690(0x108); if(p) return p->call(a,(u32)this,c); return 0; }
