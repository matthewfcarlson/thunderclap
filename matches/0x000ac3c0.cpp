#include "compat/ptr.h"
extern "C" char DAT_00405b2c[];
typedef unsigned int u32_ac3c0;
extern void* gNisCam;
class Base_ac3c0 {
  public:
    void BaseInit();
};
class Sub_ac3c0 {
  public:
    void Init(void* p);
};
class CNISCamera {
  public:
    char pad[0x174];
};
CNISCamera* __fastcall target(CNISCamera* self) {
    ((Base_ac3c0*)self)->BaseInit();
    void* p = gNisCam;
    *(hulk_uintptr*)self = ((hulk_intptr)DAT_00405b2c);
    *(u32_ac3c0*)((char*)self + 0xd0) = 3;
    ((Sub_ac3c0*)((char*)self + 8))->Init(p);
    *(u32_ac3c0*)((char*)self + 0x170) = 0;
    return self;
}
