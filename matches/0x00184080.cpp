// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_184080 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_184080 {
  public:
    Action_184080();
    virtual void Update();
    char pad[0x18];
};

class PropDestroyAction_184080 : public Action_184080 {
  public:
    int mTarget;
    RefObj_184080* mObj;
    PropDestroyAction_184080(int target, RefObj_184080* obj);
    virtual void Execute();
};

PropDestroyAction_184080::PropDestroyAction_184080(int target, RefObj_184080* obj) {
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
