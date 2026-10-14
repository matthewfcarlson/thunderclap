struct Part_2319c0 {
    void run(void*);
};
class Branch {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void vfunc_6();
};
class Node : public Branch {
    char pad[0x24];
    Part_2319c0 part;

  public:
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void vfunc_6();
    virtual void k();
    virtual void l();
    virtual void m();
};
void Node::vfunc_6() {
    part.run(this);
    Branch::vfunc_6();
}