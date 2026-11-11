// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002513a0..0x00251850 (kind game, layer engine, confidence high), dominant class audio::SeqEventPlayTrack
#include "tree_prelude.h"


// 0x00251590 audio::SeqEventPlayTrackType::vfunc_3 (74 B): matches/0x00251590.cpp [isolated: helper definitions (2 out-of-line function bodies); on include/gen/ and not mergeable]
// sym: ?vfunc_3@SeqEventPlayTrackType@audio@@UAEPAXXZ
#include "gen/audio.h"
#include "decls/data/engine/audio.h"
// data: heap = DAT_004e6c78

/* size_t: tree_prelude.h */
namespace audio {
class SeqEvent_251590 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    char pad[4];
    int x;
    int y;
    char flag;
    char pad2[3];
    class Field {
      public:
        void init_0023fc40(const char*, int);
    } field;
    SeqEvent_251590();
};
class SeqEventPlayTrack_251590 : public SeqEvent_251590 {
  public:
    SeqEventPlayTrack_251590();
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
};
} // namespace audio
extern void* alloc_00247530(char*);
inline void* operator new(size_t n, char* h) {
    return alloc_00247530(h);
}
audio::SeqEventPlayTrack_251590::SeqEventPlayTrack_251590() {
    x = 0;
    y = 0;
    flag = 0;
    field.init_0023fc40("MySeqTrack", 2);
}
void* audio::SeqEventPlayTrackType::vfunc_3() {
    return (void*)(new (((char*)((char*)&DAT_004e6c78))) audio::SeqEventPlayTrack_251590);
}

