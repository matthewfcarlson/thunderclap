class SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};
class SeqEventVarPosDist : public SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual SeqEventVarPosDist* f4(int);
    void Prep();
};
extern void FUN_00247550(void*, SeqEventVarPosDist*);
SeqEventVarPosDist* SeqEventVarPosDist::f4(int flags) {
    Prep();
    if (flags & 1)
        FUN_00247550((void*)0x4e7038, this);
    return this;
}