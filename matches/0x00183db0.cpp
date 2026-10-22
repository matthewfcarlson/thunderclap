// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_183db0 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_183db0 {
  public:
    Action_183db0();
    virtual void Update();
    char pad[0x18];
};

class PropSetStateByNameAction_183db0 : public Action_183db0 {
  public:
    int mTarget;
    RefObj_183db0* mObj;
    PropSetStateByNameAction_183db0(int target, RefObj_183db0* obj);
    virtual void Execute();
};

PropSetStateByNameAction_183db0::PropSetStateByNameAction_183db0(int target, RefObj_183db0* obj) {
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
