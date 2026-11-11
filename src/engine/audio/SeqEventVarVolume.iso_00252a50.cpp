// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00252780..0x00252b30 (kind game, layer engine, confidence high), dominant class audio::SeqEventVarVolume
#include "tree_prelude.h"


// 0x00252a50 audio::SeqEventVarVolume::vfunc_2 (66 B): matches/0x00252a50.cpp [isolated: compile error C3861: 'allocate': identifier not found, even with argument-dependent lookup]
// sym: ?vfunc_2@SeqEventVarVolume@audio@fn_f777b0e5@@UAEXPAVDest@23@@Z
#include "gen/owners.h"
#include "decls/data/engine/audio.h"
namespace fn_f777b0e5 {} using namespace fn_f777b0e5;
namespace fn_f777b0e5 {
extern "C" unsigned char DAT_004e6e88[112];
// data: bss = DAT_004e6a68

/* size_t: tree_prelude.h */
extern "C" void* __cdecl allocate(void*);

} // namespace fn_f777b0e5
inline void* operator new(size_t, char* p) {
    return allocate(p);
}
namespace fn_f777b0e5 {

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
    virtual void* v0_00252a20(int);
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
    void add_0025dc20(SeqActionVarVolume*);
};
} // namespace audio
void audio::SeqEventVarVolume::vfunc_2(Dest* p) {
    p->add_0025dc20(new (((char*)((char*)&(*(unsigned char(*)[112])&DAT_004e6e88) + 8))) SeqActionVarVolume(this));
}
} // namespace fn_f777b0e5

