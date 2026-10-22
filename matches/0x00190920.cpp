// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_190920 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_190920 {
  public:
    Action_190920();
    virtual void Update();
    char pad[0x18];
};

class SimulationAction_190920 : public Action_190920 {
  public:
    int mTarget;
    RefObj_190920* mObj;
    SimulationAction_190920(int target, RefObj_190920* obj);
    virtual void Execute();
};

SimulationAction_190920::SimulationAction_190920(int target, RefObj_190920* obj) {
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
