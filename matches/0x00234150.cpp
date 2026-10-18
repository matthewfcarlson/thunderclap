class A_234150 {
  public:
    virtual void f();
    virtual void g();
};
int FUN_00267090(int);
class B_234150 {
  public:
    A_234150* a;
    int b;
};
int __fastcall FUN_00234150(B_234150* p) {
    if (p->a)
        p->a->g();
    p->a = 0;
    return FUN_00267090(p->b);
}