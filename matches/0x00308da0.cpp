#include "compat/ptr.h"
extern "C" char DAT_00431d1c[];
class HairclubPhysicsObject {
  public:
    hulk_intptr vftable;
    char pad4[0x20];
    int field24;
    char pad28[0x1d0];
    int field1f8;
};
struct ThisCall_002f5480 {
    void BaseCtor();
};
HairclubPhysicsObject* __fastcall FUN_00308da0(HairclubPhysicsObject* self) {
    ((ThisCall_002f5480*)(self))->BaseCtor();
    self->vftable = ((hulk_intptr)DAT_00431d1c);
    self->field1f8 = 0;
    self->field24 = 2;
    return self;
}