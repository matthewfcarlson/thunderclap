// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002620e0..0x00262230 (kind game, layer engine, confidence medium), dominant class audio::SeqTrack
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f61f7dd3 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f61f7dd3 {} using namespace fn_f61f7dd3;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_f61f7dd3 {
extern "C" bool __cdecl FUN_0024f010(void*, uint*);
extern "C" bool __cdecl FUN_0025abd0(void*, uint*);
extern "C" bool __cdecl FUN_0025aa80(void*, unsigned char*);
struct Embedded_2620e0 {
 virtual bool read(void*);
 char data[0x18];
};
namespace audio {
struct Entry { char padding[0x24]; unsigned int count; };
}
namespace audio {
struct SeqTrack {
  public:
    virtual bool vfunc_0(Entry **entry);
    virtual bool vfunc_1(void* stream);
    char _m_pad_4[0x18];
    Embedded_2620e0 embedded;
    uint first;
    uint second;
    uint flags;
    unsigned char byteFlags;
    char _m_pad_45[0x3];
};
}
unsigned char __cdecl FUN_00246f50(audio::Entry *, const char *, ...);


// 0x002620e0 audio::SeqTrack::vfunc_1 (241 B): equivalent/0x002620e0.cpp
// sym: ?vfunc_1@SeqTrack@audio@fn_f61f7dd3@@UAE_NPAX@Z @7cb3289f91f3 @wb18725668124
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 14/14)
// audio::SeqTrack::vfunc_1 @ 0x002620e0
bool audio::SeqTrack::vfunc_1(void* stream) {
 uint a=0, b=0;
 unsigned char c=0,d=0;
 if (!FUN_0024f010(stream,&first)) return false;
 if (!FUN_0024f010(stream,&second)) return false;
 if (!FUN_0025abd0(stream,&a)) return false;
 if (!FUN_0025abd0(stream,&b)) return false;
 if (!FUN_0025aa80(stream,&c)) return false;
 if (!FUN_0025aa80(stream,&d)) return false;
 if (!(&embedded)->read(stream)) return false;
 flags=(flags & 0xfffffc00u) | ((b & 31u)<<5) | (a & 31u);
 byteFlags=(unsigned char)((byteFlags & 0xfcu) | ((d & 1u)<<1) | (c & 1u));
 return true;
}


// 0x002621e0 audio::SeqTrack::vfunc_0 (61 B): equivalent/0x002621e0.cpp
// sym: ?vfunc_0@SeqTrack@audio@fn_f61f7dd3@@UAE_NPAPAUEntry@23@@Z @c356925811bb @w634f9bfc21d9
// STATUS: equivalent (tools/equiv.py level 3: 2886 inputs, branch coverage 2/2)
// audio::SeqTrack::vfunc_0 @ 0x002621e0
bool audio::SeqTrack::vfunc_0(Entry **entry) {
    if (FUN_00246f50(*entry, "[\n")) {
        ++(*entry)->count;
        FUN_00246f50(*entry, "%s ", "mName");
    }
    return false;
}

} // namespace fn_f61f7dd3
