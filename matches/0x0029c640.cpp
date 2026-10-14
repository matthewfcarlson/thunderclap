class A_29c640 {
  public:
    virtual void f();
    virtual void g();
};
void thunk(int);
class B_29c640 {
  public:
    A_29c640* a;
    int b;
};
void __fastcall FUN_0029c640(B_29c640* p) {
    p->a->g();
    thunk(p->b);
}