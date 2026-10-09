namespace audio {
class SeqCommand {
  public:
    virtual void vfunc_0();
    virtual SeqCommand* vfunc_1(int);
};
class SeqCommandCondition : public SeqCommand {
  public:
    virtual void vfunc_0();
    virtual SeqCommandCondition* vfunc_1(int);
};
} // namespace audio
extern void __cdecl FUN_00247550(void*, void*);
audio::SeqCommandCondition* audio::SeqCommandCondition::vfunc_1(int arg) {
    *(int*)this = 0x429ac8;
    if (arg & 1)
        FUN_00247550((void*)0x4e68b0, this);
    return this;
}