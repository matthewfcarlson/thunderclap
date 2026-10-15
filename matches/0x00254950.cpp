namespace audio {
class SeqAction {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void vfunc_6(int);
    char pad[8];
    unsigned int elapsed;
    float duration;
    int last;
    int state;
};
class SeqActionSilence : public SeqAction {
  public:
    virtual void vfunc_6(int);
};
} // namespace audio
extern "C" int __cdecl tick();
void audio::SeqActionSilence::vfunc_6(int) {
    if (state == 3) {
        int t = tick();
        elapsed += t - last;
        last = t;
        if ((float)elapsed >= duration) {
            elapsed = (int)duration;
            state = 0;
        }
    }
}