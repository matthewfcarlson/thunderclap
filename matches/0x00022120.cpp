extern "C" void _ReadWriteBarrier();
extern void* g_vftable_22120[];
void operator delete(void*);
class Ref_22120 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_22120 {
  public:
    void* vptr;
    void Fin();
};
class CIntangibleAction_22120 : public CAction_22120 {
  public:
    char pad[0x1c - 4];
    Ref_22120* m;
    CIntangibleAction_22120* f2(unsigned char flags);
};
CIntangibleAction_22120* CIntangibleAction_22120::f2(unsigned char flags) {
    vptr = g_vftable_22120;
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
