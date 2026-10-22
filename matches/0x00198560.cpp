// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_198560 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_198560 {
  public:
    Action_198560();
    virtual void Update();
    char pad[0x18];
};

class MissileThrowAction_198560 : public Action_198560 {
  public:
    int mTarget;
    RefObj_198560* mObj;
    MissileThrowAction_198560(int target, RefObj_198560* obj);
    virtual void Execute();
};

MissileThrowAction_198560::MissileThrowAction_198560(int target, RefObj_198560* obj) {
    int* p = &mTarget;
    *p = 0;
    mObj = 0;
    mTarget = target;
    if (obj) {
        obj->AddRef();
    }
    if (mObj) {
        mObj->Release();
    }
    mObj = obj;
}
