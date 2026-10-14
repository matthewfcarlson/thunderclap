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
    virtual void vfunc_14(int);
};
class Inner_2fe270 {
  public:
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
};
class Owner_2fe270 {
  public:
    char pad[0x20];
    Inner_2fe270* inner;
    char pad2[0x50 - 0x24];
    char flag;
    void Helper(int);
};
class SimStateHairclub : public SimState {
  public:
    char pad[0x74 - sizeof(SimState)];
    Owner_2fe270* owner;
    void vfunc_14(int);
};
void SimStateHairclub::vfunc_14(int x) {
    SimState::vfunc_14(x);
    Owner_2fe270* o = owner;
    if (o->flag) {
        owner->Helper(0);
        owner->inner->f10();
        owner->Helper(1);
    } else {
        o->inner->f10();
    }
}
