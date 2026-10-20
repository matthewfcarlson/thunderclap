// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_149330 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class ActionBase_149330 {
  public:
    ActionBase_149330();
    virtual void Update();
    char pad[0x18];
};

class CivilianDetachAction_149330 : public ActionBase_149330 {
  public:
    int mTarget;
    RefObj_149330* mObj;
    CivilianDetachAction_149330(int target, RefObj_149330* obj);
    virtual void Execute();
};

CivilianDetachAction_149330::CivilianDetachAction_149330(int target, RefObj_149330* obj) {
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
