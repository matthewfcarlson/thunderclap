class CCondition {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g(int);
    virtual int h(int);
    int vfunc_6(int, int, int);
};
int CCondition::vfunc_6(int x, int y, int z) {
    return h(y);
}