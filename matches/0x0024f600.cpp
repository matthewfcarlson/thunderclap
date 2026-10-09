class SeqEvent {
  public:
    bool vfunc_0(void*);
};
extern bool ReadA(void*, void*);
extern bool ReadB(void*, void*);
extern bool ReadC(void*, void*);
class SeqEventChannelSendVolumes {
  public:
    virtual int vfunc_0(void* p);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad0[4];
    int field8;
    char pad[0x48 - 0xc];
    int field48;
    int field4c;
};
int SeqEventChannelSendVolumes::vfunc_0(void* p) {
    SeqEvent* base = reinterpret_cast<SeqEvent*>(this);
    if (base->vfunc_0(p) && ReadA(p, &field48) && ReadB(p, &field4c) && ReadC(p, &field8))
        return 1;
    return 0;
}
