// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_177430 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class ActionBase_177430 {
  public:
    ActionBase_177430();
    virtual void Update();
    char pad[0x18];
};

class CriticalMassDrainAction_177430 : public ActionBase_177430 {
  public:
    int mTarget;
    RefObj_177430* mObj;
    CriticalMassDrainAction_177430(int target, RefObj_177430* obj);
    virtual void Execute();
};

CriticalMassDrainAction_177430::CriticalMassDrainAction_177430(int target, RefObj_177430* obj) {
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
