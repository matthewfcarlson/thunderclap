struct Small {
    unsigned int x[0x10];
};
struct Big {
    unsigned int x[0x15];
    Small* f100();
    void f120(Small*);
};
struct Joint2 {
    char pad[8];
    void* item;
    void b980(Small*);
};
struct Obj {
    Big* edf0();
    void ee40(Big*);
};
struct Arg {
    Obj* f490(void*);
};
class PhysicsJointMatrixModifier {
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
    virtual void vfunc_9(Arg*);
    char pad[12];
    unsigned char active;
    char p14[4];
    Joint2* joint;
};
void PhysicsJointMatrixModifier::vfunc_9(Arg* arg) {
    if (!active)
        return;
    void* it = joint->item;
    Obj* obj = arg->f490(it);
    Big* bp = obj->edf0();
    Big big = *bp;
    Small* sp = big.f100();
    Small small = *sp;
    joint->b980(&small);
    big.f120(&small);
    obj->ee40(&big);
}