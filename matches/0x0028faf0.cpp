class GlobalThing_28faf0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};
extern GlobalThing_28faf0* gThing_28faf0;
class Other_28faf0 {
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
};
class Target_28faf0 {
  public:
    char pad[0xe8];
    Other_28faf0* other;
    char pad2[8];
    unsigned char flag;
    void run(bool);
};
void Target_28faf0::run(bool b) {
    gThing_28faf0->f5();
    flag = 0;
    if (b)
        other->f14();
}