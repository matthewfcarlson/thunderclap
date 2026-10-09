struct C3 {
    void Fn(void* a, void* b);
};
struct C2 {
    C3* G();
};
struct C1 {
    C2* F();
};
struct Mgr {
    C1* Find(int id);
};
struct Tbl {
    char pad[0x10];
    char* data;
};
struct Own {
    char pad[0x208];
    Mgr* mgr;
    char pad2[0x220 - 0x20c];
    Tbl* tbl;
    C1* Find(int id) { return mgr->Find(id); }
};
class PhysicsJoint {
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
    virtual void vfunc_10(int);
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    char pad[4];
    int m8;
    int mC;
    char pad2[0x18 - 0x10];
    Own* mOwn;
};
class PhysicsJoint1D : public PhysicsJoint {
  public:
    virtual void vfunc_10(int);
    char pad3[0xfc - 0x1c];
    char blob[4];
    void Fin();
};
void PhysicsJoint1D::vfunc_10(int a) {
    PhysicsJoint::vfunc_10(a);
    C3* c = mOwn->Find(mC)->F()->G();
    c->Fn(mOwn->tbl->data + m8 * 0x1c + 0xc, blob);
    Fin();
    f25();
}
