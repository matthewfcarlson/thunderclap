class Manager_d7e60 {
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
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual int f44();
};
Manager_d7e60* getManager();
extern char* name_d7e60;
class Field_d7e60 {
  public:
    int val;
    void set(char*, int, int);
};
class FEObject {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void vfunc_3();
};
class FEMemCardControl : public FEObject {
  public:
    char a[0x18 - 4];
    int x18;
    char b[0x1d0 - 0x1c];
    int x1d0;
    char c[0x220 - 0x1d4];
    int x220;
    char d[0x25c - 0x224];
    int x25c;
    char e[0x298 - 0x260];
    int x298;
    char f[0x2d4 - 0x29c];
    int x2d4;
    char g[0x310 - 0x2d8];
    int x310;
    char h[0x384 - 0x314];
    Field_d7e60 field;
    virtual void vfunc_3();
};
void FEMemCardControl::vfunc_3() {
    FEObject::vfunc_3();
    x1d0 = 0;
    x18 = 0;
    Manager_d7e60* m = getManager();
    field.set(name_d7e60, m->f44(), 1);
    field.val = 0;
    x220 = 0;
    x25c = 0;
    x298 = 0;
    x2d4 = 0;
    x310 = 0;
}