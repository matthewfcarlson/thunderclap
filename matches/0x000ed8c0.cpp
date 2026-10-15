// Same code shape as 0x000ecdf0 (propagated; names are from that function)
struct Vec3_ed8c0 {
    int pad;
    float x;
    float y;
};
struct X_ed8c0 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    virtual void p(Vec3_ed8c0*, void*);
};
struct TextTable {
    char pad[20];
    X_ed8c0* obj;
    float vfunc_8();
};
float TextTable::vfunc_8() {
    Vec3_ed8c0 v;
    obj->p(&v, this);
    return v.x * 1.05f;
}
