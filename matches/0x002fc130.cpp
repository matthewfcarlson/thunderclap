struct Small_2fc130 {
    unsigned int x[0x10];
};
struct Big_2fc130 {
    unsigned int x[0x15];
    Small_2fc130* f100();
    void f120(Small_2fc130*);
};
struct Joint2 {
    char pad[8];
    void* item;
    void b980(Small_2fc130*);
};
struct Obj_2fc130 {
    Big_2fc130* edf0();
    void ee40(Big_2fc130*);
};
struct Arg_2fc130 {
    Obj_2fc130* f490(void*);
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
    virtual void vfunc_9(Arg_2fc130*);
    char pad[12];
    unsigned char active;
    char p14[4];
    Joint2* joint;
};
void PhysicsJointMatrixModifier::vfunc_9(Arg_2fc130* arg) {
    if (!active)
        return;
    void* it = joint->item;
    Obj_2fc130* obj = arg->f490(it);
    Big_2fc130* bp = obj->edf0();
    Big_2fc130 big = *bp;
    Small_2fc130* sp = big.f100();
    Small_2fc130 small = *sp;
    joint->b980(&small);
    big.f120(&small);
    obj->ee40(&big);
}