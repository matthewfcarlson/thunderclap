struct C3_30c0a0 {
    void Fn(void* a, void* b);
};
struct C2_30c0a0 {
    C3_30c0a0* G();
};
struct C1_30c0a0 {
    C2_30c0a0* F();
};
struct Mgr_30c0a0 {
    C1_30c0a0* Find(int id);
};
struct Tbl_30c0a0 {
    char pad[0x10];
    char* data;
};
struct Own_30c0a0 {
    char pad[0x208];
    Mgr_30c0a0* mgr;
    char pad2[0x220 - 0x20c];
    Tbl_30c0a0* tbl;
    C1_30c0a0* Find(int id) { return mgr->Find(id); }
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
    Own_30c0a0* mOwn;
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
    C3_30c0a0* c = mOwn->Find(mC)->F()->G();
    c->Fn(mOwn->tbl->data + m8 * 0x1c + 0xc, blob);
    Fin();
    f25();
}
