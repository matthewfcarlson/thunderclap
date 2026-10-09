class CAction {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
};
struct Inner {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void set(int, int);
};
struct Obj {
    char pad[0x128];
    Inner* p;
};
struct Actor {
    Obj* get();
};
struct Obj2 {
    Obj* get();
};
class CPropActorSetStateAction : public CAction {
  public:
    char pad[0x1c - 4];
    Actor* actor;
    struct State* state;
    bool vfunc_7(int);
};
struct State {
    char pad[0x10];
    int value;
};
bool CPropActorSetStateAction::vfunc_7(int) {
    Obj* o = actor->get();
    o = ((Obj2*)o)->get();
    if (o->p)
        o->p->set(state->value, 1);
    return false;
}