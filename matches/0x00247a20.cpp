class Obj {
  public:
    int Check();
    void Start(int, int);
};
class State {
  public:
    char pad0[8];
    Obj* mObj;
    int mStatus;
    char mFlag;
    char pad11[3];
    int mValue;
};
class Callback {
  public:
    virtual void A();
    virtual void B(void*, Obj*);
};
class Owner {
  public:
    char pad0[0xac];
    Callback* mCallback;
};
extern int Result(Obj*);
void FUN_00247a20(Owner* owner, State* state, Obj* obj, int flag, int value) {
    state->mFlag = (char)flag;
    state->mValue = value;
    state->mStatus = 1;
    if (obj) {
        if (state->mObj->Check() == 0) {
            state->mObj->Start((int)obj, flag);
            if (Result(obj) == 2) {
                state->mStatus = 3;
                return;
            }
        } else
            owner->mCallback->B(owner, obj);
    }
}