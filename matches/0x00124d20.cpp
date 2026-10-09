class Obj;
class Actor {
  public:
    char pad[0x10];
    char flag;
};
class Obj {
  public:
    Obj* Resolve();
    Obj* Check();
    void Apply(int a, int b);
    char pad[0x32c];
    char flag;
};
class TargetClearAction {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    bool vfunc_3(int a, int b);
    char pad[0x1c - 4];
    Actor* actor;
    Obj* target;
};
bool TargetClearAction::vfunc_3(int a, int b) {
    if (!target)
        return false;
    Obj* r = target->Resolve();
    if (!r)
        return false;
    Obj* r2 = r->Check();
    if (!r2)
        return false;
    if (actor->flag != 0 || r2->flag == 0)
        r2->Apply(0, 0);
    return true;
}
