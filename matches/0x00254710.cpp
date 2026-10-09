class SeqAction {
    char pad[0x14];
};
class SeqActionSilence : public SeqAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void vfunc_3(int);
    virtual void f4();
    virtual void f5();
    virtual void f6();
    int field;
};
void SeqActionSilence::vfunc_3(int) {
    field = 2;
}