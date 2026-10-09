class D {
  public:
    void g(void*, int, void*);
};
class A {
  public:
    virtual void f();
};
class C {
    char pad[0x10];
    D* m;

  public:
    void run(A* a, void* b);
};
void A::f() {}
void C::run(A* a, void* b) {
    D* mm = m;
    a->f();
    mm->g(b, 0, a);
}
