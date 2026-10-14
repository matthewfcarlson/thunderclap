extern "C" char DAT_004e6ad0[];
class SeqAction {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
};
namespace audio {
class SeqActionExpression : public SeqAction {
  public:
    virtual SeqActionExpression* vfunc_0(int);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
};
} // namespace audio
extern void __cdecl FUN_00247550(void*, void*);
extern void* seq_vftable_250ca0[];
audio::SeqActionExpression* audio::SeqActionExpression::vfunc_0(int x) {
    *(void**)this = seq_vftable_250ca0;
    if (x & 1)
        FUN_00247550((void*)((int)DAT_004e6ad0), this);
    return this;
}