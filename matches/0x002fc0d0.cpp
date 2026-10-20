#include "compat/ptr.h"
extern "C" char DAT_00431840[];
class Base_2fc0d0 {
  public:
    char pad[0x18];
    Base_2fc0d0();
};
class PhysicsJointMatrixModifier : public Base_2fc0d0 {
  public:
    void* member;
    PhysicsJointMatrixModifier(void*);
};
PhysicsJointMatrixModifier::PhysicsJointMatrixModifier(void* arg) {
    member = arg;
    *(void**)this = (void*)((hulk_intptr)DAT_00431840);
}