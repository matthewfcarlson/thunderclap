// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_173380 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_173380 {
  public:
    Action_173380();
    virtual void Update();
    char pad[0x18];
};

class MotionStateAction_173380 : public Action_173380 {
  public:
    int mTarget;
    RefObj_173380* mObj;
    MotionStateAction_173380(int target, RefObj_173380* obj);
    virtual void Execute();
};

MotionStateAction_173380::MotionStateAction_173380(int target, RefObj_173380* obj) {
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
