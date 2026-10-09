class SeqActionSilence {
    char pad[0x14];
    int field;

  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(int);
    virtual void f5();
    virtual void f6();
};
void SeqActionSilence::f4(int) {
    field = 0;
}
