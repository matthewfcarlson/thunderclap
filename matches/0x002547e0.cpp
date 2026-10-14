extern "C" char DAT_0042a30c[];
typedef unsigned int u32_2547e0;
extern void* __cdecl allocObj(void*);
extern char gPool_2547e0;
struct SeqEventSilence {
    u32_2547e0 vptr;
    u32_2547e0 unk;
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
    SeqEventSilence* p = (SeqEventSilence*)allocObj(&gPool_2547e0);
    if (p) {
        p->initialize();
        p->vptr = ((int)DAT_0042a30c);
        p->duration = 500;
        p->end = 1000;
        return p;
    }
    return (SeqEventSilence*)0;
}