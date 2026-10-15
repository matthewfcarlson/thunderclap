extern char bss[];
void* alloc(void*);
int find(const char*, int);
extern "C" void _ReadWriteBarrier();
namespace audio {
class SeqEvent {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    int x;
    SeqEvent();
};
class SeqEventWaitBeat : public SeqEvent {
  public:
    int b;
    int c;
    int a;
    SeqEventWaitBeat() {
        _ReadWriteBarrier();
        b = 0;
        c = 0;
        a = find("stitched", 0);
    }
};
class SeqEventWaitBeatType {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual SeqEventWaitBeat* vfunc_3();
};
} // namespace audio
inline void* operator new(unsigned int, void* p) {
    return p;
}
audio::SeqEventWaitBeat* audio::SeqEventWaitBeatType::vfunc_3() {
    void* p = alloc(bss);
    return p ? new (p) SeqEventWaitBeat : 0;
}