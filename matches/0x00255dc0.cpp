class SeqAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void vfunc_3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
namespace audio {
class SeqActionClip : public SeqAction {
  public:
    char pad[0x10];
    int mThing;
    int mState;
    void vfunc_3(int);
};
} // namespace audio
int __cdecl Check(int);
void __cdecl DoThing(int);
void audio::SeqActionClip::vfunc_3(int arg) {
    int x = mThing;
    if (x != 0 && Check(x) == 1)
        DoThing(mThing);
    mState = 4;
}