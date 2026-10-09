class X {
  public:
    virtual void f();
    virtual void g();
    virtual void h(int);
    char pad[4];
    char b;
};
extern X* g;
void target() {
    X* p = g;
    p->b = 0;
    p->h(0);
}