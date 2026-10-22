// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_183ca0 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_183ca0 {
  public:
    Action_183ca0();
    virtual void Update();
    char pad[0x18];
};

class PropSetStateByIndexAction_183ca0 : public Action_183ca0 {
  public:
    int mTarget;
    RefObj_183ca0* mObj;
    PropSetStateByIndexAction_183ca0(int target, RefObj_183ca0* obj);
    virtual void Execute();
};

PropSetStateByIndexAction_183ca0::PropSetStateByIndexAction_183ca0(int target, RefObj_183ca0* obj) {
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
