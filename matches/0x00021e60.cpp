extern "C" void _ReadWriteBarrier();
extern void* g_vftable_21e60[];
extern void* g_base_vftable[];
void operator delete(void*);
class Ref_21e60 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_21e60 {
  public:
    void* vptr;
    void Fin();
};
class CSmartPropUpdateAttachmentAction_21e60 : public Base_21e60 {
  public:
    char pad[0x18];
    Ref_21e60* m1c;
    char pad2[4];
    Ref_21e60* m24;
    CSmartPropUpdateAttachmentAction_21e60* f2(unsigned char flags);
};
CSmartPropUpdateAttachmentAction_21e60* CSmartPropUpdateAttachmentAction_21e60::f2(unsigned char flags) {
    vptr = g_vftable_21e60;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    vptr = g_base_vftable;
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
