#include "compat/ptr.h"
extern "C" char DAT_004315dc[];
class Big_2f5640 {
  public:
    void Init();
};
class SymMatrix_2f5640 {
  public:
    void Init();
};
class Base_2f5640 {
  public:
    void Init();
};
class PhysicsObject {
  public:
    void* vt;
    char pad[0x168 - 4];
    void Finish();
    void Setup();
};
void PhysicsObject::Setup() {
    vt = (void*)((hulk_intptr)DAT_004315dc);
    ((Big_2f5640*)((char*)this + 0x168))->Init();
    ((SymMatrix_2f5640*)((char*)this + 0x114))->Init();
    ((SymMatrix_2f5640*)((char*)this + 0xf8))->Init();
    ((SymMatrix_2f5640*)((char*)this + 0xdc))->Init();
    ((Base_2f5640*)((char*)this + 0x30))->Init();
    Finish();
}
