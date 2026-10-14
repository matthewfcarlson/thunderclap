class SeqEvent {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
extern char check4(void*, void*);
extern char check2(void*, void*);
extern char check3(void*, void*);
extern char check5(void*, void*);
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
    if ((char)SeqEvent::vfunc_0(p) && check4(p, (char*)this + 8) && check4(p, (char*)this + 12) &&
        check4(p, (char*)this + 16) && check4(p, (char*)this + 20) && check2(p, (char*)this + 24) &&
        check2(p, (char*)this + 25) && check3(p, (char*)this + 28) && check5(p, (char*)this + 40) &&
        tail.f(p))
        return 1;
    return 0;
}