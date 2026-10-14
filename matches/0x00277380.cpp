struct A_277380 {
    virtual void a();
};
struct Inner_277380 {
    virtual void f();
};
struct Obj_277380 : A_277380, Inner_277380 {};
struct CementLibrary {
    char pad[0xc];
    Obj_277380* p;
    void vfunc_0_adj10();
};
void CementLibrary::vfunc_0_adj10() {
    p->f();
}