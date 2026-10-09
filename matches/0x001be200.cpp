class Overlay {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
class CSubtitleOverlay : public Overlay {
  public:
    char pad[0x11d - 0x4];
    void vfunc_1();
};
void CSubtitleOverlay::vfunc_1() {
    *((char*)this + 0x11d) = 1;
}