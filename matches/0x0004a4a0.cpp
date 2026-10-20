#include "compat/ptr.h"
#include "gen/global.h"
extern "C" char DAT_003f7404[];
class CAlertStatusCondition_4a4a0 {
  public:
    int vptr;
    int pad4;
    int pad8;
    int mC;
    int m10;
};
struct CAlertStatusCondition_nv_4a4a0 {
    void Init(int);
};
CAlertStatusCondition_4a4a0* __fastcall FUN_0004a4a0(CAlertStatusCondition_4a4a0* self, void*) {
    ((CAlertStatusCondition_nv_4a4a0*)(((CAlertStatusCondition*)(self))))->Init(0);
    self->vptr = ((hulk_intptr)DAT_003f7404);
    self->mC = 0;
    self->m10 = 0;
    return self;
}