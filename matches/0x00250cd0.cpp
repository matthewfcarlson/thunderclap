#include "compat/ptr.h"
#include "gen/audio.h"

typedef unsigned int size_t;
extern char bss;
extern "C" void* __cdecl allocate(void*);
namespace audio {

class SeqActionExpression_250cd0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    char pad[4];
    audio::SeqEventExpression* owner;
    int val;
    SeqActionExpression_250cd0(audio::SeqEventExpression* p) : owner(p), val(0) {}
    static void* operator new(size_t) { return allocate(&bss); }
};
class Engine {
  public:
    void send(SeqActionExpression_250cd0*);
};
class SeqEvent_250cd0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};
} // namespace audio
void audio::SeqEventExpression::vfunc_2(hulk_intptr __p0) { audio::Engine * e = (audio::Engine *)__p0;

    e->send(new audio::SeqActionExpression_250cd0(this));
}
