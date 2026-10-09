extern void* seqActionVtable;
extern char seqActionBss;
extern void __cdecl FUN_00247550(void*, void*);
class SeqAction {
  public:
    virtual SeqAction* vfunc_0(int);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
};
namespace audio {
class SeqActionStopTrack : public SeqAction {
  public:
    virtual SeqAction* vfunc_0(int);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
};
} // namespace audio
SeqAction* audio::SeqActionStopTrack::vfunc_0(int flags) {
    *(void**)this = &seqActionVtable;
    if (flags & 1)
        FUN_00247550(&seqActionBss, this);
    return this;
}
