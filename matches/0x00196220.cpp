// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_196220 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class ActionBase_196220 {
  public:
    ActionBase_196220();
    virtual void Update();
    char pad[0x18];
};

class FireMissileAction_196220 : public ActionBase_196220 {
  public:
    int mTarget;
    RefObj_196220* mObj;
    FireMissileAction_196220(int target, RefObj_196220* obj);
    virtual void Execute();
};

FireMissileAction_196220::FireMissileAction_196220(int target, RefObj_196220* obj) {
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
