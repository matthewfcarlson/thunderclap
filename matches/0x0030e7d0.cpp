class V {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual int* q();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14(void*);
};
class W_30e7d0 : public V {
  public:
    char pad[0x38 - sizeof(V)];
    int x38, x3c, x40, x44;
    int x48, x4c, x50;
    virtual void w13();
    virtual void vfunc_14(W_30e7d0*);
};
void W_30e7d0::vfunc_14(W_30e7d0* out) {
    V::f14(out);
    int* a = this->q();
    int* b = out->q();
    b[0] = a[0];
    b[1] = a[1];
    b[2] = a[2];
    out->x38 = x38;
    out->x3c = x3c;
    out->x40 = x40;
    out->x48 = x48;
    out->x4c = x4c;
    out->x50 = x50;
    out->x44 = x44;
}