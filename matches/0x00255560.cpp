class SeqAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    char pad[8];
};
class SeqActionCrossFade : public SeqAction {
  public:
    int fieldC;
    int field10;
    virtual void f4(int);
};
void ReleaseThing(int);
void SeqActionCrossFade::f4(int unused) {
    if (field10) {
        ReleaseThing(field10);
        field10 = 0;
    }
    fieldC = 0;
}