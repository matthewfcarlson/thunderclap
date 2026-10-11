extern "C" char DAT_004e6698[];
class SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual SeqEvent* f4(unsigned int);
    virtual void f5();
};
class SeqEventNestTrack : public SeqEvent {
    char pad[8];

  public:
    virtual SeqEventNestTrack* f4(unsigned int);
};
class H {
  public:
    void a();
    void b();
};
extern void FUN_00247550(void*, SeqEventNestTrack*);
SeqEventNestTrack* SeqEventNestTrack::f4(unsigned int param) {
    ((H*)((char*)this + 8))->a();
    ((H*)this)->b();
    if (param & 1)
        FUN_00247550((void*)((int)DAT_004e6698), this);
    return this;
}