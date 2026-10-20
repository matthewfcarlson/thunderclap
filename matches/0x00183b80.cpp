// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_183b80 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class ActionBase_183b80 {
  public:
    ActionBase_183b80();
    virtual void Update();
    char pad[0x18];
};

class PropAddToMissileCountAction_183b80 : public ActionBase_183b80 {
  public:
    int mTarget;
    RefObj_183b80* mObj;
    PropAddToMissileCountAction_183b80(int target, RefObj_183b80* obj);
    virtual void Execute();
};

PropAddToMissileCountAction_183b80::PropAddToMissileCountAction_183b80(int target, RefObj_183b80* obj) {
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
