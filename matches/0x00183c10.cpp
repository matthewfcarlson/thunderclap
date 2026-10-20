// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_183c10 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class ActionBase_183c10 {
  public:
    ActionBase_183c10();
    virtual void Update();
    char pad[0x18];
};

class PropAddToCollisionAction_183c10 : public ActionBase_183c10 {
  public:
    int mTarget;
    RefObj_183c10* mObj;
    PropAddToCollisionAction_183c10(int target, RefObj_183c10* obj);
    virtual void Execute();
};

PropAddToCollisionAction_183c10::PropAddToCollisionAction_183c10(int target, RefObj_183c10* obj) {
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
