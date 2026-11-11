// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002504b0..0x00250960 (kind game, layer engine, confidence high), dominant class audio::SeqEventWaitBeat
#include "tree_prelude.h"


// 0x00250910 audio::SeqEventWaitBeatType::vfunc_3 (73 B): matches/0x00250910.cpp [isolated: compile error in a shared declaration (C2084); on include/gen/ and not mergeable]
// sym: ?vfunc_3@SeqEventWaitBeatType@audio@@UAEPAXXZ
#include "gen/audio.h"
#include "decls/data/engine/audio.h"
// data: bss = DAT_004e6a68

void* alloc_00247530(void*);
int find_002673a0(const char*, int);
extern "C" void _ReadWriteBarrier();
namespace audio {
class SeqEvent_250910 {
  public:
    virtual int v0_00250870(void*);
    virtual bool v1_00250820(void*);
    virtual void v2_002508c0(hulk_intptr);
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
        a = find_002673a0("stitched", 0);
    }
};
} // namespace audio
inline void* operator new(size_t, void* p) {
    return p;
}
void* audio::SeqEventWaitBeatType::vfunc_3() {
    void* p = alloc_00247530(((char*)((char*)&DAT_004e6a68)));
    return (void*)(p ? new (p) SeqEventWaitBeat_250910 : 0);
}

