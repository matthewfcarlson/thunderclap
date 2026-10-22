extern "C" void _ReadWriteBarrier();
extern void* g_vftable_22240[];
extern void* g_vftable2[];
void operator delete(void*);
class Ref_22240 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_22240 {
  public:
    void* vptr;
    void Fin();
};
class CEffectStopAction_22240 : public CAction_22240 {
  public:
    char pad[0x1c - 4];
    Ref_22240* m1c;
    CEffectStopAction_22240* f2(unsigned char flags);
};
CEffectStopAction_22240* CEffectStopAction_22240::f2(unsigned char flags) {
    vptr = g_vftable_22240;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
