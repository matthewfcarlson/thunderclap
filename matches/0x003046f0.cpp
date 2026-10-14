class Inner_3046f0 {
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
    void Stop();
    void Start();
};
class Obj_3046f0 {
  public:
    char p[0x20];
    Inner_3046f0* inner;
    char q[0x2c];
    char active;
    char r[0x17];
    char a, b;
    void Set(char x);
};
void Obj_3046f0::Set(char x) {
    if (active && !x) {
        active = x;
        inner->Stop();
    } else if (!active && x) {
        inner->f10();
        active = x;
        inner->Start();
        a = 0;
        b = 0;
    }
}