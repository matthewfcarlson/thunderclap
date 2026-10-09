class SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void vfunc_4();
    virtual void f5();
};
namespace audio {
class SeqEventVarPitch : public SeqEvent {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual SeqEventVarPitch* vfunc_4(int);
    void Helper();
};
} // namespace audio
extern void FUN_00247550(void*, audio::SeqEventVarPitch*);
extern char g_4e7198;
audio::SeqEventVarPitch* audio::SeqEventVarPitch::vfunc_4(int x) {
    Helper();
    if (x & 1)
        FUN_00247550(&g_4e7198, this);
    return this;
}
