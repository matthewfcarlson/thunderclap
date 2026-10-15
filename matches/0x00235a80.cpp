namespace fight {
class FightNodeCondition {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual bool vfunc_6(int, int, int);
    virtual int* lookup(int);
    char pad[8];
    int op;
    int value;
};
bool FightNodeCondition::vfunc_6(int a, int b, int c) {
    int* p = lookup(b);
    if (!p)
        return false;
    int v = value;
    int mode = op;
    int x = *p;
    switch (mode) {
    case 0:
        return x == v;
    case 1:
        return x != v;
    }
    return false;
}
} // namespace fight