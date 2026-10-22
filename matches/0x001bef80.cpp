extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1bef80[];
extern void* g_vftable2[];
class Ref_1bef80 {
  public:
    virtual void F0();
    virtual void Release();
};
class Overlay_1bef80 {
  public:
    void* vptr;
};
class CSubtitleOverlay_1bef80 : public Overlay_1bef80 {
  public:
    char pad[0x14];
    Ref_1bef80* m18;
    ~CSubtitleOverlay_1bef80() throw();
};
CSubtitleOverlay_1bef80::~CSubtitleOverlay_1bef80() throw() {
    vptr = g_vftable_1bef80;
    _ReadWriteBarrier();
    if (m18) {
        m18->Release();
        m18 = 0;
    }
    vptr = g_vftable2;
}
