class DrawableNode {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void vfunc_6(int, int);
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
    char pad[12];
    unsigned char flags;
    char pad2[7];
    void* ptr;
};
void DrawableNode::vfunc_6(int x, int y) {
    if (!(flags & 1) && ptr)
        ((DrawableNode*)ptr)->vfunc_6(x, y);
}