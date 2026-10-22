extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1bfc80[];
extern void* g_vftable2[];
class Ref_1bfc80 {
  public:
    virtual void F0();
    virtual void Release();
};
class Overlay_1bfc80 {
  public:
    void* vptr;
    void Fin();
};
void Free(void*) throw();

class CSubtitleOverlay_1bfc80 : public Overlay_1bfc80 {
  public:
    char pad[0x14];
    Ref_1bfc80* m18;
    CSubtitleOverlay_1bfc80* f0(unsigned char fl);
};
CSubtitleOverlay_1bfc80* CSubtitleOverlay_1bfc80::f0(unsigned char fl) {
    vptr = g_vftable_1bfc80;
    _ReadWriteBarrier();
    if (m18) {
        m18->Release();
        m18 = 0;
    }
    vptr = g_vftable2;
    if (fl & 1)
        Free(this);
    return this;
}
