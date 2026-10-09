class SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};
class SeqEventClip : public SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual SeqEventClip* f4(int);
    void helper();
};
extern void FUN_00247550(void*, SeqEventClip*);
extern int data_4e75b8;
SeqEventClip* SeqEventClip::f4(int arg) {
    helper();
    if (arg & 1)
        FUN_00247550(&data_4e75b8, this);
    return this;
}