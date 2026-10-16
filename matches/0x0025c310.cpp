namespace audio {
class HalStream {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int vfunc_3();
};
class OmHalStream : public HalStream {
  public:
    char pad[8];
    char data[4];
    int vfunc_3();
};
} // namespace audio
int helper(void*);
int audio::OmHalStream::vfunc_3() {
    return helper(&data[0]);
}