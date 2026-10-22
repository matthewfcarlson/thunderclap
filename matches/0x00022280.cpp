extern "C" void _ReadWriteBarrier();
extern void* g_vftable_22280[];
void operator delete(void*);
class Ref_22280 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_22280 {
  public:
    void* vptr;
    void Fin();
};
class CCameraShakeAction_22280 : public CAction_22280 {
  public:
    char pad[24];
    Ref_22280* m;
    CCameraShakeAction_22280* f2(unsigned char flags);
};
CCameraShakeAction_22280* CCameraShakeAction_22280::f2(unsigned char flags) {
    vptr = g_vftable_22280;
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
