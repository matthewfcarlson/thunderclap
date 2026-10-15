namespace audio {
class SeqEventWait;
class SeqActionWait {
  public:
    virtual void v0();
    virtual void v1();
    int pad;
    SeqEventWait* event;
    int zero;
    SeqActionWait(SeqEventWait* e) : event(e), zero(0) {}
};
} // namespace audio
class Target {
  public:
    void set(audio::SeqActionWait*);
};
namespace audio {
class SeqEvent {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class SeqEventWait : public SeqEvent {
  public:
    virtual void v2(Target*);
};
} // namespace audio
extern char bss;
extern "C" void* __cdecl alloc(void*);
void audio::SeqEventWait::v2(Target* p) {
    audio::SeqActionWait* a = (audio::SeqActionWait*)alloc(&bss);
    p->set(a ? (a->audio::SeqActionWait::SeqActionWait(this), a) : 0);
}