class CGolem {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
};
class CActorGolem : public CGolem {};
class CCharacterGolem : public CActorGolem {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void vfunc_6();
    virtual void vfunc_7();
    char pad[0x100 - 4];
    void* p0;
    void* p1;
    void* p2;
    void* p3;
    void* p4;
    void* p5;
};
void CCharacterGolem::vfunc_7() {
    CGolem::v7();
    if (p0) {
        ((CGolem*)p0)->v1();
        p0 = 0;
    }
    if (p1) {
        ((CGolem*)p1)->v1();
        p1 = 0;
    }
    if (p2) {
        ((CGolem*)p2)->v1();
        p2 = 0;
    }
    if (p3) {
        ((CGolem*)p3)->v1();
        p3 = 0;
    }
    if (p4) {
        ((CGolem*)p4)->v1();
        p4 = 0;
    }
    if (p5) {
        ((CGolem*)p5)->v1();
        p5 = 0;
    }
}