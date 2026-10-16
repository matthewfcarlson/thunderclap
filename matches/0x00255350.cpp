#include "gen/audio.h"

typedef unsigned int size_t;
extern char bss;
void* __cdecl Alloc(char*);
inline void* operator new(size_t, void* p) {
    return p;
}
namespace audio {
class SeqEventBase {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    int pad;
    SeqEventBase();
};
class SeqEventMid : public SeqEventBase {
  public:
    int a, b, c;
    SeqEventMid() : a(0), b(0), c(0) {}
};
class SeqEventLogicOr_255350 : public SeqEventMid {
  public:
    float value;
    virtual void f0();
    SeqEventLogicOr_255350() : value(0.5f) {}
};

} // namespace audio
void* audio::SeqEventLogicOrType::vfunc_3() {
    void* p = Alloc(&bss);
    return (void*)(p ? new (p) SeqEventLogicOr_255350 : 0);
}
