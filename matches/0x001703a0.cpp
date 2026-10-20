#include "compat/ptr.h"
extern int vtable_1703a0;
class Part_1703a0 {
  public:
    int x[2];
    void Init();
};
class Obj_1703a0 {
  public:
    hulk_intptr vt;
    char pad[0x14];
    Part_1703a0 p18;
    Part_1703a0 p20;
    void Final();
    void Run();
};
void Obj_1703a0::Run() {
    vt = (hulk_intptr)&vtable_1703a0;
    p20.Init();
    p18.Init();
    Final();
}