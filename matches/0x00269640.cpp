typedef unsigned int u32;
extern u32 __cdecl FindThing(u32, u32);
class Obj { public: u32 Make(u32, u32); };
void __cdecl Target(u32 a, u32 b) {
    u32 v = b;
    *(volatile u32*)0x4cdbb0 = v;
    u32 x = FindThing(v, 0x12a8);
    if (x) *(volatile u32*)0x528398 = ((Obj*)x)->Make(a, v);
    else *(volatile u32*)0x528398 = 0;
}