#include "compat/ptr.h"
class Obj_247a20 {
  public:
    int Check();
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
extern int Result(Obj_247a20*);
void FUN_00247a20(Owner_247a20* owner, State_247a20* state, Obj_247a20* obj, int flag, int value) {
    state->mFlag = (char)flag;
    state->mValue = value;
    state->mStatus = 1;
    if (obj) {
        if (state->mObj->Check() == 0) {
            state->mObj->Start((hulk_intptr)obj, flag);
            if (Result(obj) == 2) {
                state->mStatus = 3;
                return;
            }
        } else
            owner->mCallback->B(owner, obj);
    }
}