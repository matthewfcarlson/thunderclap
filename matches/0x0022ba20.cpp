class X {
  public:
    void f(void*);
};
class Y {
  public:
    void target(X* p);
};
void Y::target(X* p) {
    p->f(this);
}