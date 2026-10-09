class SeqEvent {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual SeqEvent* v4(int);
    virtual void v5();
    void Prepare();
};
class SeqEventSilence : public SeqEvent {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual SeqEventSilence* v4(int);
};
extern void FUN_00247550(void*, SeqEventSilence*);
extern char DAT_004e72f8[];
SeqEventSilence* SeqEventSilence::v4(int flags) {
    Prepare();
    if (flags & 1)
        FUN_00247550(DAT_004e72f8, this);
    return this;
}