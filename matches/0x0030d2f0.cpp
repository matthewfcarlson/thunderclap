#include "compat/ptr.h"
extern "C" char DAT_00431de4[];
// Same code shape as 0x0030cbb0 (propagated; names are from that function)
class SymMatrix_30d2f0 {
  public:
    void Init();
};
class PhysicsJoint {
  public:
    char pad[0x20];
    int m20;
    hulk_intptr m24;
};
extern void __cdecl AddRef(void*);
void __fastcall Target(PhysicsJoint* self) {
    *(hulk_intptr*)self = ((hulk_intptr)DAT_00431de4);
    ((SymMatrix_30d2f0*)((char*)self + 0x64))->Init();
    ((SymMatrix_30d2f0*)((char*)self + 0x48))->Init();
    hulk_intptr value = self->m20;
    self->m24 = value;
    if (value)
        AddRef((void*)value);
}