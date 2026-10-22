// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_1493c0 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_1493c0 {
  public:
    Action_1493c0();
    virtual void Update();
    char pad[0x18];
};

class CivilianAnimationAction_1493c0 : public Action_1493c0 {
  public:
    int mTarget;
    RefObj_1493c0* mObj;
    CivilianAnimationAction_1493c0(int target, RefObj_1493c0* obj);
    virtual void Execute();
};

CivilianAnimationAction_1493c0::CivilianAnimationAction_1493c0(int target, RefObj_1493c0* obj) {
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
