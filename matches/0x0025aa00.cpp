extern char mixVftable;
void f70();
class Mix {
  public:
    virtual void f0();
    virtual void f1();
    virtual Mix* f2(unsigned char);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    char pad[0x38 - 4];
    void setup();
};
void a220(void*);
void df0(void*);
int f660();
int f550(int, Mix*);
Mix* Mix::f2(unsigned char x) {
    *(void**)this = &mixVftable;
    a220((char*)this + 0x38);
    df0((char*)this + 0x28);
    setup();
    if (x & 1) {
        f550(f660(), this);
    }
    return this;
}