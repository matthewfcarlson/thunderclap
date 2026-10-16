#include "gen/audio.h"

extern char bss[];
void* alloc(void*);
int find(const char*, int);
extern "C" void _ReadWriteBarrier();
namespace audio {
class SeqEvent_250910 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    int x;
    SeqEvent_250910();
};
class SeqEventWaitBeat_250910 : public SeqEvent_250910 {
  public:
    int b;
    int c;
    int a;
    SeqEventWaitBeat_250910() {
        _ReadWriteBarrier();
        b = 0;
        c = 0;
        a = find("stitched", 0);
    }
};
} // namespace audio
inline void* operator new(unsigned int, void* p) {
    return p;
}
void* audio::SeqEventWaitBeatType::vfunc_3() {
    void* p = alloc(bss);
    return (void*)(p ? new (p) SeqEventWaitBeat_250910 : 0);
}
