class Ref {
  public:
    virtual void Add();
    virtual void Release();
};
class Sub {
  public:
    void Init();
    char d[8];
};
class Base {
  public:
    Base();
    virtual void f();
    char b[0x30];
};
class RoutAction : public Base {
  public:
    RoutAction(int, Ref*);
    virtual void f();
    int a34;
    Ref* a38;
    int a3c;
    char p[0x18];
    int a58;
    int a5c;
    Sub s;
    char c68;
    int a6c;
    int a70;
};
RoutAction::RoutAction(int a, Ref* b) {
    a34 = 0;
    a38 = 0;
    a3c = 0;
    a58 = 0;
    a5c = 0;
    s.Init();
    c68 = 0;
    a6c = 0;
    a70 = 0x43610000;
    a34 = a;
    if (b)
        b->Add();
    Ref* o = a38;
    if (o)
        o->Release();
    a38 = b;
}