// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_183ff0 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_183ff0 {
  public:
    Action_183ff0();
    virtual void Update();
    char pad[0x18];
};

class GrapplePropDamageAction_183ff0 : public Action_183ff0 {
  public:
    int mTarget;
    RefObj_183ff0* mObj;
    GrapplePropDamageAction_183ff0(int target, RefObj_183ff0* obj);
    virtual void Execute();
};

GrapplePropDamageAction_183ff0::GrapplePropDamageAction_183ff0(int target, RefObj_183ff0* obj) {
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
