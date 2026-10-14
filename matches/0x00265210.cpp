class D {
  public:
    void g(void*, int, void*);
};
class A_265210 {
  public:
    virtual void f();
};
class C_265210 {
    char pad[0x10];
    D* m;

  public:
    void run(A_265210* a, void* b);
};
void A_265210::f() {}
void C_265210::run(A_265210* a, void* b) {
    D* mm = m;
    a->f();
    mm->g(b, 0, a);
}
