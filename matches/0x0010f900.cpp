#include "gen/hulkfight.h"

extern "C" void _ReadWriteBarrier();
class Ref_10f900 {
  public:
    virtual void A();
    virtual void Release();
};
class Action_10f900 {
  public:
    virtual void A();
    virtual void B();
    void Finish();
};
extern void* vtable_10f900[];
struct AIHistorySetAction_nv_10f900 {
    void Finish();
};

void hulkfight::ai::AIHistorySetAction::FUN_0010f900() {
    *(void**)this = vtable_10f900;
    _ReadWriteBarrier();
    if ((*(Ref_10f900 * *)&this->f_20)) {
        (*(Ref_10f900 * *)&this->f_20)->Release();
        (*(Ref_10f900 * *)&this->f_20) = 0;
    }
    if ((*(Ref_10f900 * *)&this->f_1c))
        (*(Ref_10f900 * *)&this->f_1c) = 0;
    ((AIHistorySetAction_nv_10f900*)(((Action_10f900*)this)))->Finish();
}
