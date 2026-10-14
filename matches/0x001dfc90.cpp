class Function {
  public:
    virtual void f0();
    virtual void f1();
};
struct Pair_1dfc90 {
    int a;
    int b;
};
class CSPManager {
  public:
    int Fn(int, int);
};
class Method2 : public Function {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(int, Pair_1dfc90*, int*);
    char pad[0x18];
    int (CSPManager::*mFn)(int, int);
};
void Method2::f2(int x, Pair_1dfc90* p, int* out) {
    int (CSPManager::*fn)(int, int) = mFn;
    CSPManager* m = (CSPManager*)x;
    int a = p->a;
    int b = p->b;
    int r = (m->*fn)(a, b);
    if (out)
        *out = r;
}
