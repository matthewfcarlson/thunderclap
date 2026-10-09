// Same code shape as 0x00254730 (propagated; names are from that function)
class SeqAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual unsigned int f5();
    virtual void f6();
};
namespace audio {
class SeqActionSilence : public SeqAction {
  public:
    char pad[0x18 - sizeof(SeqAction)];
    unsigned int value;
    unsigned int vfunc_5(int);
};
} // namespace audio
unsigned int audio::SeqActionSilence::vfunc_5(int) {
    return value;
}