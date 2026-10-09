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
extern bool __cdecl checkA(void*, void*);
extern bool __cdecl checkB(void*, void*);
int SeqEventChannelSends::vfunc_0(void* p) {
    if (SeqEvent::baseCheck(p))
        if (checkA(p, (char*)this + 0x108))
            if (checkB(p, (char*)this + 8))
                return 1;
    return 0;
}
