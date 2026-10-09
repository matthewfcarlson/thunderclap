class Inner {
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
    char pad[0x15];
    unsigned char state;
};
void __fastcall FUN_00306230(Inner* p);
class Obj {
  public:
    char pad[0x20];
    Inner* p;
    int x24;
    int x28;
    char pad2c[0x3c];
    unsigned char b68;
    unsigned char b69;
    void run();
};
void Obj::run() {
    p->state = 0;
    b68 = 1;
    b69 = 1;
    p->f10();
    x24 = 0;
    FUN_00306230(p);
    x28 = 0;
}
