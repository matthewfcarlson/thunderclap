class SeqEvent {
  public:
    virtual int vfunc_0(int);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
int Transform(int, void*);
class SeqEventVarVolume : public SeqEvent {
  public:
    virtual int vfunc_0(int);
};
int SeqEventVarVolume::vfunc_0(int value) {
    SeqEvent::vfunc_0(value);
    return Transform(value, (char*)this + 8);
}