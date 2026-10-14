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
struct Inner_185f0 {
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
struct Obj_185f0 {
    char pad[0x128];
    Inner_185f0* p;
};
struct Actor_185f0 {
    Obj_185f0* get();
};
struct Obj2_185f0 {
    Obj_185f0* get();
};
class CPropActorSetStateAction : public CAction {
  public:
    char pad[0x1c - 4];
    Actor_185f0* actor;
    struct State_185f0* state;
    bool vfunc_7(int);
};
struct State_185f0 {
    char pad[0x10];
    int value;
};
bool CPropActorSetStateAction::vfunc_7(int) {
    Obj_185f0* o = actor->get();
    o = ((Obj2_185f0*)o)->get();
    if (o->p)
        o->p->set(state->value, 1);
    return false;
}