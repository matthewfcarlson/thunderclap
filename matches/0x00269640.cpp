extern "C" char DAT_004cdbb0[];
extern "C" char DAT_00528398[];
typedef unsigned int u32_269640;
extern u32_269640 __cdecl FindThing(u32_269640, u32_269640);
class Obj_269640 {
  public:
    u32_269640 Make(u32_269640, u32_269640);
};
void __cdecl Target(u32_269640 a, u32_269640 b) {
    u32_269640 v = b;
    *(volatile u32_269640*)((int)DAT_004cdbb0) = v;
    u32_269640 x = FindThing(v, 0x12a8);
    if (x)
        *(volatile u32_269640*)((int)DAT_00528398) = ((Obj_269640*)x)->Make(a, v);
    else
        *(volatile u32_269640*)((int)DAT_00528398) = 0;
}