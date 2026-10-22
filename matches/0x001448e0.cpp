// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_1448e0 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_1448e0 {
  public:
    Action_1448e0();
    virtual void Update();
    char pad[0x18];
};

class WorldDamageAction_1448e0 : public Action_1448e0 {
  public:
    int mTarget;
    RefObj_1448e0* mObj;
    WorldDamageAction_1448e0(int target, RefObj_1448e0* obj);
    virtual void Execute();
};

WorldDamageAction_1448e0::WorldDamageAction_1448e0(int target, RefObj_1448e0* obj) {
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
