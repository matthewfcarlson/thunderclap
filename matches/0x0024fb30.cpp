class SeqEvent {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    bool baseCheck(void*);
};
class SeqEventChannelSends : public SeqEvent {
  public:
    virtual int vfunc_0(void*);
    char pad[0x104];
};
extern "C" bool __cdecl FUN_0024f010(void*, void*);
extern "C" bool __cdecl FUN_0025c7c0(void*, void*);
int SeqEventChannelSends::vfunc_0(void* p) {
    if (SeqEvent::baseCheck(p))
        if (FUN_0024f010(p, (char*)this + 0x108))
            if (FUN_0025c7c0(p, (char*)this + 8))
                return 1;
    return 0;
}
