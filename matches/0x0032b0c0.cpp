#include "compat/ptr.h"
extern "C" char DAT_004338f4[];
class Helper_32b0c0 {
  public:
    void Init(void*);
};
class Obj_32b0c0 {
  public:
    virtual void f();
    Obj_32b0c0* Make(void* arg);
    unsigned char pad[0x5c];
};
void Obj_32b0c0::f() {}
Obj_32b0c0* Obj_32b0c0::Make(void* arg) {
    ((Helper_32b0c0*)this)->Init(arg);
    *(unsigned int*)((char*)this + 0x58) = 0xff000000;
    *(unsigned int*)((char*)this + 0x50) = 0xff000000;
    *(unsigned int*)((char*)this + 0x54) = 0xff000000;
    *(hulk_uintptr*)this = ((hulk_intptr)DAT_004338f4);
    *(unsigned char*)((char*)this + 0x48) = 1;
    *(unsigned int*)((char*)this + 0x5c) = 0xffff80ff;
    return this;
}
