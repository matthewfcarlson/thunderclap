// Same code shape as 0x00048520 (propagated; names are from that function)
#include "compat/ptr.h"
extern int g_vft_48790;
class CButtonValueCondition {
  public:
    hulk_intptr vf;
    int x1;
    int x2;
    int x3;
    int x4;
    int x5;
    int x6;
    int x7;
};
struct ThisCall_00234590 {
    void FUN_00234590(int);
};
CButtonValueCondition* __fastcall FUN_00048790(CButtonValueCondition* self) {
    ((ThisCall_00234590*)(self))->FUN_00234590(0);
    self->x4 = 4;
    self->x6 = 4;
    self->x3 = 0;
    self->x5 = 0;
    self->vf = (hulk_intptr)&g_vft_48790;
    self->x7 = 0;
    return self;
}