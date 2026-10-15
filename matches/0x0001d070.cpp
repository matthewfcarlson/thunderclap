class Obj {
  public:
    virtual void Add();
    virtual void Release();
};
class Root {
  public:
    virtual void v();
    char pad[24];
    Obj* object;
    int val;
    Root();
};
class CAction : public Root {
  public:
    virtual void v();
    CAction(Obj* obj, int n) : Root() {
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