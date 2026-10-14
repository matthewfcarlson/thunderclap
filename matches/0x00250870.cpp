class SeqEvent {
  public:
    virtual int vfunc_0(void*);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
extern bool Check(void*, void*);
class Inner_250870 {
  public:
    bool CheckBeat(void*);
};
class Helper_250870 {
  public:
    bool Probe(void*);
};
class SeqEventWaitBeat : public SeqEvent {
  public:
    char pad[12];
    int field10;
    int vfunc_0(void*);
};
int SeqEventWaitBeat::vfunc_0(void* arg) {
    if (((Helper_250870*)this)->Probe(arg) && Check(arg, &field10) && ((Inner_250870*)((char*)this + 8))->CheckBeat(arg))
        return 1;
    return 0;
}
