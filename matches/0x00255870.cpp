class SeqEvent {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
extern "C" char FUN_0025abd0(void*, void*);
extern "C" char FUN_0025aa80(void*, void*);
extern "C" char FUN_0025bce0(void*, void*);
extern "C" char FUN_0024f010(void*, void*);
class Tail_255870 {
  public:
    char f(void*);
};
class SeqEventCrossFade : public SeqEvent {
  public:
    char pad[0x28];
    Tail_255870 tail;
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
int SeqEventCrossFade::vfunc_0(void* p) {
    if ((char)SeqEvent::vfunc_0(p) && FUN_0025abd0(p, (char*)this + 8) && FUN_0025abd0(p, (char*)this + 12) &&
        FUN_0025abd0(p, (char*)this + 16) && FUN_0025abd0(p, (char*)this + 20) && FUN_0025aa80(p, (char*)this + 24) &&
        FUN_0025aa80(p, (char*)this + 25) && FUN_0025bce0(p, (char*)this + 28) && FUN_0024f010(p, (char*)this + 40) &&
        tail.f(p))
        return 1;
    return 0;
}