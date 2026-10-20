#include "compat/ptr.h"
extern "C" char DAT_00431de4[];
class Helper_30cbb0 {
  public:
    void Init();
};
class PhysicsJoint {
  public:
    char pad[0x20];
    int m20;
    int m24;
};
extern void __cdecl AddRef(void*);
void __fastcall Target(PhysicsJoint* self) {
    *(hulk_intptr*)self = ((hulk_intptr)DAT_00431de4);
    ((Helper_30cbb0*)((char*)self + 0x64))->Init();
    ((Helper_30cbb0*)((char*)self + 0x48))->Init();
    hulk_intptr value = self->m20;
    self->m24 = value;
    if (value)
        AddRef((void*)value);
}