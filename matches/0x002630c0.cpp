class Device_2630c0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(int);
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual int Get();
};
class Obj_2630c0 {
  public:
    char pad[0x20];
    Device_2630c0* dev;
    char p24[8];
    int result;
    int base;
    int value;
    int delta;
    char p3c[8];
    int state;
};
void __fastcall FUN(Obj_2630c0* self) {
    int n = self->value;
    if (n == 0)
        n = self->dev->Get();
    self->result = n - self->delta - 0x800;
    self->dev->f5(self->base + self->delta + 0x800);
    self->state = 4;
}