// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_126810 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_126810 {
  public:
    Action_126810();
    virtual void Update();
    char pad[0x18];
};

class ClearProjectileDistanceAction_126810 : public Action_126810 {
  public:
    int mTarget;
    RefObj_126810* mObj;
    ClearProjectileDistanceAction_126810(int target, RefObj_126810* obj);
    virtual void Execute();
};

ClearProjectileDistanceAction_126810::ClearProjectileDistanceAction_126810(int target, RefObj_126810* obj) {
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
