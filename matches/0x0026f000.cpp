class X_26f000 {
  public:
    virtual void f();
    virtual void g_26f000();
    virtual void h(int);
    char pad[4];
    char b;
};
extern X_26f000* g_26f000;
void target() {
    X_26f000* p = g_26f000;
    p->b = 0;
    p->h(0);
}