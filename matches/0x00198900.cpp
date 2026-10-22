// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_198900 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_198900 {
  public:
    Action_198900();
    virtual void Update();
    char pad[0x18];
};

class FireGroundShockwaveAction_198900 : public Action_198900 {
  public:
    int mTarget;
    RefObj_198900* mObj;
    FireGroundShockwaveAction_198900(int target, RefObj_198900* obj);
    virtual void Execute();
};

FireGroundShockwaveAction_198900::FireGroundShockwaveAction_198900(int target, RefObj_198900* obj) {
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
