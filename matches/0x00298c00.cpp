class Obj_298c00 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual char Check();
};
class Obj22 {
  public:
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
    virtual void p();
    virtual void q();
    virtual void r();
    virtual void s();
    virtual void t();
    virtual void u();
    virtual void v();
    virtual char Check();
};
struct First_298c00 {
    char pad20[0x20];
    unsigned char count;
    char pad[0xf];
    unsigned char* ids;
    char pad2[8];
    Obj_298c00** objs;
};
struct Second_298c00 {
    char pad8[8];
    unsigned char count;
    char pad[0xf];
    unsigned char* ids;
    char pad2[8];
    Obj22** objs;
};
class CompositeDrawable {
  public:
    char pad44[0x44];
    First_298c00* first;
    Second_298c00* second;
    Obj22* third;
    Obj22* fourth;
    char a();
    char b();
    char c();
    char d();
    char e();
    char f();
    char g();
    char v7();
};
char CompositeDrawable::v7() {
    unsigned char i = 0;
    if (!second) {
        unsigned char n = first->count;
        while (i < n) {
            Obj_298c00* o = first->objs[first->ids[i] * 3 + 2];
            if (!o->Check())
                return 0;
            ++i;
        }
        if (third && !third->Check())
            return 0;
        if (fourth && !fourth->Check())
            return 0;
    } else {
        unsigned char n = second->count;
        while (i < n) {
            Obj22* o = second->objs[second->ids[i]];
            if (!o->Check())
                return 0;
            ++i;
        }
    }
    return 1;
}