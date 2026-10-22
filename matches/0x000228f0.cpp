extern "C" void _ReadWriteBarrier();
extern void* g_vftable_228f0[];
void operator delete(void*);
class Ref_228f0 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_228f0 {
  public:
    void* vptr;
    void Fin();
};
class CClearHitRecordsAction_228f0 : public CAction_228f0 {
  public:
    char pad[0x1c - 4];
    Ref_228f0* m;
    CClearHitRecordsAction_228f0* f2(unsigned char flags);
};
CClearHitRecordsAction_228f0* CClearHitRecordsAction_228f0::f2(unsigned char flags) {
    vptr = g_vftable_228f0;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
