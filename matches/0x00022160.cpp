extern "C" void _ReadWriteBarrier();
extern void* g_vftable_22160[];
void operator delete(void*);
class Ref_22160 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_22160 {
  public:
    void* vptr;
    void Fin();
};
class CIntangibleToActorsAction_22160 : public CAction_22160 {
  public:
    char pad[0x1c - 4];
    Ref_22160* m;
    CIntangibleToActorsAction_22160* f2(unsigned char flags);
};
CIntangibleToActorsAction_22160* CIntangibleToActorsAction_22160::f2(unsigned char flags) {
    vptr = g_vftable_22160;
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
