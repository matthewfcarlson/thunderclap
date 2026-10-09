namespace audio {
class SeqActionWaitBeat;
}
class SeqAction {
  public:
    virtual audio::SeqActionWaitBeat* vfunc_0(int);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
};
extern void __cdecl FUN_00247550(void*, void*);
namespace audio {
class SeqActionWaitBeat : public SeqAction {
  public:
    virtual SeqActionWaitBeat* vfunc_0(int);
};
SeqActionWaitBeat* SeqActionWaitBeat::vfunc_0(int flag) {
    SeqActionWaitBeat* s = this;
    *(int*)s = 0x4298fc;
    if (flag & 1)
        FUN_00247550((void*)0x4e6a18, s);
    return s;
}
} // namespace audio