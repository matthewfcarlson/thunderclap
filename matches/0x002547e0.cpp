typedef unsigned int u32;
extern void* __cdecl allocObj(void*);
extern char gPool;
struct SeqEventSilence {
    u32 vptr;
    u32 unk;
    int duration;
    int end;
    void initialize();
};
struct SeqEventSilenceType {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual SeqEventSilence* vfunc_3();
};
SeqEventSilence* SeqEventSilenceType::vfunc_3() {
    SeqEventSilence* p = (SeqEventSilence*)allocObj(&gPool);
    if (p) {
        p->initialize();
        p->vptr = 0x42a30c;
        p->duration = 500;
        p->end = 1000;
        return p;
    }
    return (SeqEventSilence*)0;
}