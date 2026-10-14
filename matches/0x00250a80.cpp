class SeqAction {
  public:
    virtual void f0();
    virtual void f1(int);
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    char pad[4];
    int field8;
    int fieldC;
};
struct Temp_250a80 {
    char bytes[12];
    void init();
    void fini();
};
extern void operate(int, Temp_250a80*, int);
void SeqAction::f1(int p) {
    Temp_250a80 t;
    t.init();
    operate(*(int*)(p + 0x3c) + 0x5c, &t, field8 + 8);
    fieldC = 0;
    t.fini();
}