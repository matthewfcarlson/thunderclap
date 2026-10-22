// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_1775e0 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_1775e0 {
  public:
    Action_1775e0();
    virtual void Update();
    char pad[0x18];
};

class SnapToGroundAction_1775e0 : public Action_1775e0 {
  public:
    int mTarget;
    RefObj_1775e0* mObj;
    SnapToGroundAction_1775e0(int target, RefObj_1775e0* obj);
    virtual void Execute();
};

SnapToGroundAction_1775e0::SnapToGroundAction_1775e0(int target, RefObj_1775e0* obj) {
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
