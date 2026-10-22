// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_183a10 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class Action_183a10 {
  public:
    Action_183a10();
    virtual void Update();
    char pad[0x18];
};

class PropActorThinkingAction_183a10 : public Action_183a10 {
  public:
    int mTarget;
    RefObj_183a10* mObj;
    PropActorThinkingAction_183a10(int target, RefObj_183a10* obj);
    virtual void Execute();
};

PropActorThinkingAction_183a10::PropActorThinkingAction_183a10(int target, RefObj_183a10* obj) {
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
