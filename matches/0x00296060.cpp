class Obj {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual bool h();
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
};
class DrawableNode {
  public:
    char pad[0x10];
    unsigned char flags;
    char pad2[7];
    Obj* child;
    bool vfunc_7();
};
bool DrawableNode::vfunc_7() {
    if ((flags & 1) == 0 && child != 0 && !child->h())
        return false;
    return true;
}