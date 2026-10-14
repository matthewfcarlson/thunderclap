class Obj_2ef3f0 {
  public:
    virtual void f();
};
class Old_2ef3f0 {
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
    virtual void vfunc_14(Obj_2ef3f0*);
    char pad[0x70];
    Obj_2ef3f0* member;
};
void SimState::vfunc_14(Obj_2ef3f0* p) {
    if (p)
        p->f();
    if (member)
        ((Old_2ef3f0*)member)->cleanup();
    member = p;
}
