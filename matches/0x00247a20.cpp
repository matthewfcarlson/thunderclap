#include "compat/ptr.h"
#include "gen/owners.h"
class Obj_247a20 {
  public:
    void Start(hulk_intptr, int);
};
class State_247a20 {
  public:
    char pad0[8];
    Obj_247a20* mObj;
    int mStatus;
    char mFlag;
    char pad11[3];
    int mValue;
};
class Callback_247a20 {
  public:
    virtual void A();
    virtual void B(void*, Obj_247a20*);
};
class Owner_247a20 {
  public:
    char pad0[0xac];
    Callback_247a20* mCallback;
};
extern "C" int FUN_0024afe0(Obj_247a20*);
extern "C" void FUN_00247a20(Owner_247a20* owner, State_247a20* state, Obj_247a20* obj, int flag, int value) {
    state->mFlag = (char)flag;
    state->mValue = value;
    state->mStatus = 1;
    if (obj) {
        if (((owners::Object_25d3e0 *)(state->mObj))->FUN_0025d3e0() == 0) {
            state->mObj->Start((hulk_intptr)obj, flag);
            if (FUN_0024afe0(obj) == 2) {
                state->mStatus = 3;
                return;
            }
        } else
            owner->mCallback->B(owner, obj);
    }
}