namespace audio {
class SeqEvent {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*);
};
class SeqEventClip : public SeqEvent {
  public:
    virtual void vfunc_2(void*);
};
class BaseAction {
  public:
    virtual void act();
    char pad[4];
    SeqEventClip* owner;
    int a, b, c, d;
    BaseAction() : a(0), b(0), c(0), d(0) {}
};
class SeqActionClip : public BaseAction {
  public:
    virtual void act();
    SeqActionClip(SeqEventClip* p) { owner = p; }
};
class Target {
  public:
    void set(SeqActionClip*);
};
} // namespace audio
extern char bss[];
extern "C" void* alloc(void*);
inline audio::SeqActionClip* create(audio::SeqEventClip* p) {
    audio::SeqActionClip* a = (audio::SeqActionClip*)alloc(bss);
    if (a) {
        a->audio::SeqActionClip::SeqActionClip(p);
        return a;
    }
    return 0;
}
void audio::SeqEventClip::vfunc_2(void* p) {
    ((audio::Target*)p)->set(create(this));
}