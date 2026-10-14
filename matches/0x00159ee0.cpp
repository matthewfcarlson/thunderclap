void* operator new(unsigned int);
struct Base_159ee0 {
    virtual void g();
    Base_159ee0();
};
struct Track : Base_159ee0 {
    virtual void f();
    int x4, x8, xC;
    float x10;
    int x14, x18, x1C, x20;
    Track();
};
Track::Track() {
    xC = 0;
    x14 = 0;
    x1C = 0;
    x20 = 0;
    x10 = -1.0f;
    x18 = -5;
}
struct Factory_159ee0 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Track* v5();
};
Track* Factory_159ee0::v5() {
    Track* p = (Track*)::operator new(0x24);
    if (p) {
        p->Track::Track();
        return p;
    }
    return 0;
}
