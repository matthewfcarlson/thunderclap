// Same code shape as 0x001703a0 (propagated; names are from that function)
#include "compat/ptr.h"
extern int vtable_62400;
class Part_62400 {
  public:
    int x[2];
    void Init();
};
class Obj_62400 {
  public:
    hulk_intptr vt;
    char pad[0x14];
    Part_62400 p18;
    Part_62400 p20;
    void Final();
    void Run();
};
void Obj_62400::Run() {
    vt = (hulk_intptr)&vtable_62400;
    p20.Init();
    p18.Init();
    Final();
}