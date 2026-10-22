extern "C" void _ReadWriteBarrier();
extern void* g_vftable_142220[];
void operator delete(void*);
class Ref_142220 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_142220 {
  public:
    void* vptr;
    void Fin();
};
class WallRunAction_142220 : public Action_142220 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_142220* m20;
    Ref_142220* m24;
    Ref_142220* m28;
    WallRunAction_142220* f2(unsigned char flags);
};
WallRunAction_142220* WallRunAction_142220::f2(unsigned char flags) {
    vptr = g_vftable_142220;
    _ReadWriteBarrier();
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
