// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_10f310 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_10f310 {
  public:
    Action_10f310();
    virtual void Update();
    char pad[0x18];
};

class HulkAction_10f310 : public Action_10f310 {
  public:
    int mTarget;
    RefObj_10f310* mObj;
    HulkAction_10f310(int target, RefObj_10f310* obj);
    virtual void Execute();
};

HulkAction_10f310::HulkAction_10f310(int target, RefObj_10f310* obj) {
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
