extern "C" char DAT_004cdbb0[];
extern "C" char DAT_00528398[];
typedef unsigned int u32;
extern u32 __cdecl FindThing(u32, u32);
class Obj {
  public:
    u32 Make(u32, u32);
};
void __cdecl Target(u32 a, u32 b) {
    u32 v = b;
    *(volatile u32*)((int)DAT_004cdbb0) = v;
    u32 x = FindThing(v, 0x12a8);
    if (x)
        *(volatile u32*)((int)DAT_00528398) = ((Obj*)x)->Make(a, v);
    else
        *(volatile u32*)((int)DAT_00528398) = 0;
}