// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_184110 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class ActionBase_184110 {
  public:
    ActionBase_184110();
    virtual void Update();
    char pad[0x18];
};

class PropThrowAction_184110 : public ActionBase_184110 {
  public:
    int mTarget;
    RefObj_184110* mObj;
    PropThrowAction_184110(int target, RefObj_184110* obj);
    virtual void Execute();
};

PropThrowAction_184110::PropThrowAction_184110(int target, RefObj_184110* obj) {
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
