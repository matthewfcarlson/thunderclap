class Obj {
  public:
    virtual void f0();
};
class Shader {
  public:
    int vft;
    char pad4[12];
    Obj* field10;
    char flag;
    char pad15[3];
    int field18;
    Shader* Ctor(int a, int b);
};
class Factory {
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
    virtual Obj* Get(int a, int b);
};
extern Factory* gFactory;
void BaseInit();
Shader* Shader::Ctor(int a, int b) {
    BaseInit();
    vft = 0x42cb44;
    flag = 0;
    field18 = 0;
    Obj* p = gFactory->Get(a, b);
    field10 = p;
    p->f0();
    return this;
}