// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_10f9d0 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class ActionBase_10f9d0 {
  public:
    ActionBase_10f9d0();
    virtual void Update();
    char pad[0x18];
};

class SemaphoreClearAction_10f9d0 : public ActionBase_10f9d0 {
  public:
    int mTarget;
    RefObj_10f9d0* mObj;
    SemaphoreClearAction_10f9d0(int target, RefObj_10f9d0* obj);
    virtual void Execute();
};

SemaphoreClearAction_10f9d0::SemaphoreClearAction_10f9d0(int target, RefObj_10f9d0* obj) {
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
