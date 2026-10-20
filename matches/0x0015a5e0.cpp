#include "compat/ptr.h"
extern "C" char DAT_00414170[];
class Obj_15a5e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
extern "C" void* __cdecl alloc(unsigned int);
class Temp_15a5e0 {
  public:
    void Init(int);
};
class Tail_15a5e0 {
  public:
    void Init();
};
void* Factory_vfunc5(Obj_15a5e0* self) {
    Obj_15a5e0* p = (Obj_15a5e0*)alloc(0x18);
    if (p) {
        ((Temp_15a5e0*)p)->Init(0);
        *(hulk_intptr*)p = ((hulk_intptr)DAT_00414170);
        *(int*)((char*)p + 0xc) = 0;
        ((Tail_15a5e0*)((char*)p + 0x10))->Init();
        return p;
    }
    return 0;
}