extern "C" char DAT_00427898[];
class Branch {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    char pad[0x18 - 4];
    void run();
};
class Helper_233970 {
  public:
    void init();
    void finish();
};
void Branch::run() {
    *(void**)this = (void*)((int)DAT_00427898);
    Branch::f7();
    ((Helper_233970*)((char*)this + 0x18))->init();
    ((Helper_233970*)this)->finish();
}