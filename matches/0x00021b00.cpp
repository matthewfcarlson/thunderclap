extern "C" void _ReadWriteBarrier();
extern void* g_vftable_21b00[];
void operator delete(void*);
class Ref_21b00 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_21b00 {
  public:
    void* vptr;
    void Fin();
};
class CMoveAddAction_21b00 : public CAction_21b00 {
  public:
    char pad[24];
    Ref_21b00* m;
    CMoveAddAction_21b00* f2(unsigned char flags);
};
CMoveAddAction_21b00* CMoveAddAction_21b00::f2(unsigned char flags) {
    vptr = g_vftable_21b00;
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
