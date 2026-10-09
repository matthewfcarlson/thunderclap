struct H {
    void* get();
    void* next();
    void invoke(int, int);
};
struct HitThrowAction {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void vfunc_4();
    virtual void e();
    char pad[0x20 - 4];
    H* h;
    int arg;
    void finish();
};
void HitThrowAction::vfunc_4() {
    H* x = h;
    void* p = x->get();
    H* q = (H*)p;
    p = q->next();
    if (p) {
        ((H*)p)->invoke(arg, 0);
        finish();
    }
}