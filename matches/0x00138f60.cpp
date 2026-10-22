extern "C" void _ReadWriteBarrier();
extern void* g_vftable_138f60[];
extern void* g_vftable2[];
class Ref_138f60 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_138f60 {
  public:
    void* vptr;
    void Fin();
};

void operator delete(void*);
class FlyingAutoTargetAction_138f60 : public Action_138f60 {
  public:
    char pad[0x1c - 4];
    void* m1c;
    Ref_138f60* m20;
    Ref_138f60* m24;
    Ref_138f60* m28;
    FlyingAutoTargetAction_138f60* f2(unsigned char flags);
};
FlyingAutoTargetAction_138f60* FlyingAutoTargetAction_138f60::f2(unsigned char flags) {
    vptr = g_vftable_138f60;
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
