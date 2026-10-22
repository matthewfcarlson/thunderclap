class Obj {
  public:
    virtual void Add();
    virtual void Release();
};
class Action_1d070 {
  public:
    virtual void v();
    char pad[24];
    Obj* object;
    int val;
    Action_1d070();
};
class CAction : public Action_1d070 {
  public:
    virtual void v();
    CAction(Obj* obj, int n) : Action_1d070() {
        object = 0;
        if (obj)
            obj->Add();
        if (object)
            object->Release();
        object = obj;
        val = n;
    }
};
class CStunAnimationAction : public CAction {
  public:
    virtual void v();
    int extra;
    CStunAnimationAction(int n, Obj* obj);
};
CStunAnimationAction::CStunAnimationAction(int n, Obj* obj) : CAction(obj, n) {
    extra = 0;
}