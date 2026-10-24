#include "gen/hulkfight.h"

#include "compat/ptr.h"
extern "C" char DAT_00411110[];
extern "C" void _ReadWriteBarrier();
class Ref_12dba0 {
  public:
    virtual void f();
    virtual void Release();
};
class Action_12dba0 {
  public:
    virtual void Dummy();
    void Finish();
};
struct PostEvent_StringAction_nv_12dba0 {
    void Finish();
};

void hulkfight::PostEvent_StringAction::FUN_0012dba0() {
    *(void**)this = (void*)((hulk_intptr)DAT_00411110);
    _ReadWriteBarrier();
    if ((*(Ref_12dba0 * *)&this->f_20)) {
        (*(Ref_12dba0 * *)&this->f_20)->Release();
        (*(Ref_12dba0 * *)&this->f_20) = 0;
    }
    ((PostEvent_StringAction_nv_12dba0*)this)->Finish();
}
