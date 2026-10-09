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
class Helper {
  public:
    void init();
    void finish();
};
void Branch::run() {
    *(void**)this = (void*)0x427898;
    Branch::f7();
    ((Helper*)((char*)this + 0x18))->init();
    ((Helper*)this)->finish();
}