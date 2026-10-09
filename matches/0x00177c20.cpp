typedef unsigned int u32;
struct C { bool go(u32,u32); };
class Param { public: char pad[0xc]; u32 fn; virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); bool vfunc_6(u32 a,u32 b,u32 c); };
bool Param::vfunc_6(u32 a,u32 b,u32 c) { if(!fn) return false; typedef bool (C::*Fn)(u32,u32); Fn p=*(Fn*)&fn; return ((C*)a->*p)(b,c); }