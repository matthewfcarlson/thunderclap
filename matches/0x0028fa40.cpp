class X_28fa40 {
  public:
    virtual void x0();
    virtual void x1();
    virtual void x2();
    virtual void x3();
    virtual void x4();
    virtual void x5();
    virtual void x6();
    virtual void x7();
    virtual void x8();
    virtual void x9();
    virtual void x10();
    virtual void x11();
    virtual void x12();
    virtual void x13();
    virtual void x14(int, void*);
};
class G_28fa40 {
  public:
    virtual void y0();
    virtual void y1();
    virtual void y2();
    virtual void y3();
    virtual void y4();
    virtual void y5();
    virtual void y6();
    virtual void y7();
    virtual void y8();
    virtual void y9();
    virtual void y10();
    virtual void y11();
    virtual void y12();
    virtual void y13();
    virtual void y14();
    virtual void y15();
    virtual void y16();
    virtual void y17();
    virtual void y18();
    virtual void y19(void*);
};
struct Holder_28fa40 {
    X_28fa40* x;
};
struct Blk_28fa40 {
    unsigned int d[16];
};
extern G_28fa40* gG_28fa40;
struct Obj_28fa40 {
    char pad0[4];
    Holder_28fa40* h;
    char pad1[4];
    char buf1[64];
    char buf2[64];
    void f(unsigned int* a, unsigned int* b);
};
void Obj_28fa40::f(unsigned int* a, unsigned int* b) {
    *(Blk_28fa40*)(buf1) = *(Blk_28fa40*)a;
    *(Blk_28fa40*)(buf2) = *(Blk_28fa40*)b;
    Holder_28fa40* hh = h;
    X_28fa40* xx = hh->x;
    xx->x14(0, buf1);
    gG_28fa40->y19(a);
}
