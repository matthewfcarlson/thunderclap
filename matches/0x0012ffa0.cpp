// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_12ffa0 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_12ffa0 {
  public:
    Action_12ffa0();
    virtual void Update();
    char pad[0x18];
};

class NISSoundAction_12ffa0 : public Action_12ffa0 {
  public:
    int mTarget;
    RefObj_12ffa0* mObj;
    NISSoundAction_12ffa0(int target, RefObj_12ffa0* obj);
    virtual void Execute();
};

NISSoundAction_12ffa0::NISSoundAction_12ffa0(int target, RefObj_12ffa0* obj) {
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
