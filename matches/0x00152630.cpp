// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_152630 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_152630 {
  public:
    Action_152630();
    virtual void Update();
    char pad[0x18];
};

class HealthAction_152630 : public Action_152630 {
  public:
    int mTarget;
    RefObj_152630* mObj;
    HealthAction_152630(int target, RefObj_152630* obj);
    virtual void Execute();
};

HealthAction_152630::HealthAction_152630(int target, RefObj_152630* obj) {
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
