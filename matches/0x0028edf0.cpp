extern "C" char DAT_0042cb44[];
class Obj_28edf0 {
  public:
    virtual void f0();
};
class Shader {
  public:
    int vft;
    char pad4[12];
    Obj_28edf0* field10;
    char flag;
    char pad15[3];
    int field18;
    Shader* Ctor(int a, int b);
};
class Factory_28edf0 {
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
    virtual Obj_28edf0* Get(int a, int b);
};
extern Factory_28edf0* gFactory_28edf0;
struct ThisCall_0027b070 {
    void BaseInit();
};
Shader* Shader::Ctor(int a, int b) {
    ((ThisCall_0027b070*)(this))->BaseInit();
    vft = ((int)DAT_0042cb44);
    flag = 0;
    field18 = 0;
    Obj_28edf0* p = gFactory_28edf0->Get(a, b);
    field10 = p;
    p->f0();
    return this;
}