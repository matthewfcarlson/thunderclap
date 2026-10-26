#include "decls/data/engine/audio.h"
// data: bss = DAT_004e6a68

typedef unsigned int size_t;
extern "C" void* __cdecl allocate(void*);
inline void* operator new(size_t, char* p) {
    return allocate(p);
}
namespace audio {
class Dest;
class SeqEvent {
  public:
    virtual void v0();
    virtual void v1();
    virtual void vfunc_2(Dest*);
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class SeqActionVarVolume {
  public:
    virtual void v0();
    char pad[4];
    SeqEvent* owner;
    int value;
    SeqActionVarVolume(SeqEvent* o) : owner(o), value(0) {}
};
class SeqEventVarVolume : public SeqEvent {
  public:
    virtual void vfunc_2(Dest*);
};
class Dest {
  public:
    void add(SeqActionVarVolume*);
};
} // namespace audio
void audio::SeqEventVarVolume::vfunc_2(Dest* p) {
    p->add(new (((char*)((char*)&DAT_004e6a60 + 8))) SeqActionVarVolume(this));
}