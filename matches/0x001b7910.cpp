class State {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual int Get();
};
class Obj {
  public:
    char pad[8];
    char flag;
    char pad2[3];
    State* state;
    int Check();
};
int Obj::Check() {
    int v;
    State* s;
    if (!(((s = state) && ((v = s->Get()) == 4 || v == 3)) ||
          ((s = state) && ((v = s->Get()) == 1 || v == 2)) || flag))
        return 0;
    return 1;
}