class Obj {
  public:
    virtual void f();
};
class Old {
  public:
    void cleanup();
};
class SimState {
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
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void vfunc_14(Obj*);
    char pad[0x70];
    Obj* member;
};
void SimState::vfunc_14(Obj* p) {
    if (p)
        p->f();
    if (member)
        ((Old*)member)->cleanup();
    member = p;
}
