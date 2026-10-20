// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_183f60 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class ActionBase_183f60 {
  public:
    ActionBase_183f60();
    virtual void Update();
    char pad[0x18];
};

class PropDamageAction_183f60 : public ActionBase_183f60 {
  public:
    int mTarget;
    RefObj_183f60* mObj;
    PropDamageAction_183f60(int target, RefObj_183f60* obj);
    virtual void Execute();
};

PropDamageAction_183f60::PropDamageAction_183f60(int target, RefObj_183f60* obj) {
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
