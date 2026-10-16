#include "gen/audio.h"

namespace audio {
class Base {
  public:
    virtual void v0();
    Base();
};
class SeqEventVarPosDist_2531a0 : public Base {
  public:
    char pad[4];
    float a, b;
    SeqEventVarPosDist_2531a0() : Base(), a(1.0f), b(100.0f) {}
    static void* operator new(unsigned int, void* p) { return p; }
};
} // namespace audio
extern void* alloc(void*);
extern char heap;
void* audio::SeqEventVarPosDistType::vfunc_3() {
    void* p = alloc(&heap);
    audio::SeqEventVarPosDist_2531a0* q;
    if (p)
        q = new (p) audio::SeqEventVarPosDist_2531a0;
    else
        q = 0;
    return (void*)(q);
}
