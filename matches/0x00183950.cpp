// Same code shape as 0x0010b980 (propagated; names are from that function)
class RefObj_183950 {
  public:
    virtual void AddRef();
    virtual void Release();
};

class ActionBase_183950 {
  public:
    ActionBase_183950();
    virtual void Update();
    char pad[0x18];
};

class PropActorToPropAction_183950 : public ActionBase_183950 {
  public:
    int mTarget;
    RefObj_183950* mObj;
    PropActorToPropAction_183950(int target, RefObj_183950* obj);
    virtual void Execute();
};

PropActorToPropAction_183950::PropActorToPropAction_183950(int target, RefObj_183950* obj) {
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
