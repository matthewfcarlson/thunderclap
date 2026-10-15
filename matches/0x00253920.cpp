extern char gHeap;
void* Alloc(char*);
inline void* operator new(unsigned int, void* p) {
    return p;
}
namespace audio {
class SeqEvent {
  public:
    SeqEvent();
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    int unknown;
    float pitch;
};
class SeqEventVarPitch : public SeqEvent {
  public:
    SeqEventVarPitch() { pitch = 1.0f; }
    virtual void a();
};
class SeqEventVarPitchType {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual SeqEvent* d();
};
} // namespace audio
audio::SeqEvent* audio::SeqEventVarPitchType::d() {
    void* p = Alloc(&gHeap);
    if (p)
        return new (p) audio::SeqEventVarPitch;
    return 0;
}