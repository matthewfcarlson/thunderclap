extern "C" void _ReadWriteBarrier();
extern void* g_vftable_21b40[];
void operator delete(void*);
class Ref_21b40 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_21b40 {
  public:
    void* vptr;
    void Fin();
};
class CMoveAddYAction_21b40 : public CAction_21b40 {
  public:
    char pad[0x1c - 4];
    Ref_21b40* m;
    CMoveAddYAction_21b40* f2(unsigned char flags);
};
CMoveAddYAction_21b40* CMoveAddYAction_21b40::f2(unsigned char flags) {
    vptr = g_vftable_21b40;
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
