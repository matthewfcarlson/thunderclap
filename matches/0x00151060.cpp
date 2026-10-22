// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_151060 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_151060 {
  public:
    Action_151060();
    virtual void Update();
    char pad[0x18];
};

class InterruptPriorityAction_151060 : public Action_151060 {
  public:
    int mTarget;
    RefObj_151060* mObj;
    InterruptPriorityAction_151060(int target, RefObj_151060* obj);
    virtual void Execute();
};

InterruptPriorityAction_151060::InterruptPriorityAction_151060(int target, RefObj_151060* obj) {
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
