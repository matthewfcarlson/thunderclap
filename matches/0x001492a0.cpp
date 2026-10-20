// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_1492a0 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class ActionBase_1492a0 {
  public:
    ActionBase_1492a0();
    virtual void Update();
    char pad[0x18];
};

class CivilianAttachAction_1492a0 : public ActionBase_1492a0 {
  public:
    int mTarget;
    RefObj_1492a0* mObj;
    CivilianAttachAction_1492a0(int target, RefObj_1492a0* obj);
    virtual void Execute();
};

CivilianAttachAction_1492a0::CivilianAttachAction_1492a0(int target, RefObj_1492a0* obj) {
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
