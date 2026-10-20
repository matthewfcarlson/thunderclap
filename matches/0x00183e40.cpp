// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_183e40 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class ActionBase_183e40 {
  public:
    ActionBase_183e40();
    virtual void Update();
    char pad[0x18];
};

class PropSpawnAction_183e40 : public ActionBase_183e40 {
  public:
    int mTarget;
    RefObj_183e40* mObj;
    PropSpawnAction_183e40(int target, RefObj_183e40* obj);
    virtual void Execute();
};

PropSpawnAction_183e40::PropSpawnAction_183e40(int target, RefObj_183e40* obj) {
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
