#include "gen/audio.h"

typedef unsigned int size_t;
extern char bss;
extern void* __cdecl alloc(void*);
inline void* operator new(size_t, void* heap) {
    return alloc(heap);
}
namespace audio {

class SeqCommandCondition_24ff10 {
  public:
    virtual void f0() {}
    virtual void f1() {}
    char pad[4];
    audio::SeqEventCondition* owner;
    int value;
    SeqCommandCondition_24ff10(audio::SeqEventCondition* p) : owner(p), value(-1) {}
};
class Receiver {
  public:
    void send(SeqCommandCondition_24ff10*);
};

} // namespace audio
void audio::SeqEventCondition::vfunc_2(int __p0) { Receiver * r = (Receiver *)__p0;

    r->send(new (&bss) SeqCommandCondition_24ff10(this));
}
