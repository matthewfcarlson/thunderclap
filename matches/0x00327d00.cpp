extern int gValue_327d00;
class Target_327d00 {
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
    virtual int Check();
    int pad[2];
    int value;
    int TargetFunction();
};
int Target_327d00::TargetFunction() {
    if (value == gValue_327d00) {
        if (Check() == 1)
            return 1;
    }
    return 0;
}