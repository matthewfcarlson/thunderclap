extern "C" void _ReadWriteBarrier();
extern void* g_vftable_22730[];
void operator delete(void*);
class Ref_22730 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_22730 {
  public:
    void* vptr;
    void Fin();
};
class CMotionHitGroundHeightAction_22730 : public CAction_22730 {
  public:
    char pad[0x1c - 4];
    Ref_22730* m;
    CMotionHitGroundHeightAction_22730* f2(unsigned char flags);
};
CMotionHitGroundHeightAction_22730* CMotionHitGroundHeightAction_22730::f2(unsigned char flags) {
    vptr = g_vftable_22730;
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
