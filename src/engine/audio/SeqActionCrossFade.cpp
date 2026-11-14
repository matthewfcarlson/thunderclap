// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00255460..0x00255d00 (kind game, layer engine, confidence high), dominant class audio::SeqActionCrossFade
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "gen/audio.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fa3ba6ee {
#define TREE_TU_END }
namespace fn_fa3ba6ee {} using namespace fn_fa3ba6ee;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_fa3ba6ee {
class SeqAction_2554b0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(void*);
    int pad4;
    char* mOwner;
    int mState;
    int mHandle;
};
extern int __cdecl Find_00247930(int, int);
extern void __cdecl Stop_002497e0(int);
extern "C" void __cdecl FUN_00247a20(int, int, int, bool, int);
struct Obj_2554b0 {
    char pad[0x3c];
    int value;
};
class SeqAction_255560 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    char pad[8];
};
void ReleaseThing_002497e0(int);
typedef unsigned __int64 U64;
} // namespace fn_fa3ba6ee
extern "C" U64 __cdecl FUN_002672f0(const char*, int, int) throw();
namespace fn_fa3ba6ee {
struct FUN_00240060 {
    int a, b, c;
    ~FUN_00240060() throw();
};
struct FUN_002605e0 {
    FUN_002605e0(FUN_00240060*, const U64*, int, int) throw();
    virtual void f();
};
struct SeqEventCrossFadeType_2555c0 : FUN_002605e0 {
    SeqEventCrossFadeType_2555c0() throw();
    virtual void f();
};
extern "C" void __cdecl FUN_00247550(void*, void*);
class SeqActionCrossFade_255660 : public audio::SeqAction {
  public:
    virtual SeqActionCrossFade_255660* vfunc_0(int);
};
class SeqEvent_255690 {
  public:
    virtual int Fnf_00255870(void*);
    char pad[4];
    SeqEvent_255690();
};
class Track {
  public:
    Track(const char*, int);
    char pad[12];
};
char* __cdecl find_002673a0(const char*, int);
struct Ptr {
    char* p;
    inline Ptr& operator=(char* v) {
        p = v;
        return *this;
    }
};
class SeqEventCrossFade : public SeqEvent_255690 {
  public:
    int a, b, c, d;
    char e, f;
    char gap[2];
    Track track;
    Ptr name;
    int x, y;
    SeqEventCrossFade();
    virtual char Fng_00255730(void*);
};
extern "C" void* __cdecl FUN_00247530(void*);
} // namespace fn_fa3ba6ee
namespace audio {
struct SeqActionCrossFade_255930 {
    virtual void* vfunc_0_00255660(int);
    char pad[4];
    audio::SeqEventCrossFade* event;
    int valueC, value10, value14, value18;
    SeqActionCrossFade_255930() : event(0), valueC(0), value10(0), value14(0), value18(0) {}
};
}
namespace audio {
struct SeqContext { void FUN_0025dc20(SeqActionCrossFade_255930*); };
}
namespace fn_fa3ba6ee {
struct Node { char pad[0x34]; Node* nextLink; };
struct Holder { char pad[0x48]; Node* firstLink; };
int __cdecl FUN_00247930(void* item, Node* node);
typedef unsigned int u32_2559e0;
struct Callee_2559e0 {
    hulk_uintptr run_00255690();
};
struct Item_255b10;
struct Pair_255b10 {
    int a;
    int b;
};
struct Source_255b10 {
    char pad0[0x3c];
    Group *group;
};
struct Layer_255b10 {
    char pad0[8];
    Source_255b10 *owner;
};
struct Item_255b10 {
    char pad0[8];
    Source_255b10 *source;
};
struct Target_255b10 {
    char pad0[0x2c];
    int level;
};
struct Config_255b10 {
    char pad0[8];
    int f8;
    int fc;
    int f10;
    int f14;
    char pad18;
    char keepAlive;
    char pad1a[0x2c - 0x1a];
    int levels;
};
extern "C" Handle *__cdecl FUN_002495c0(Group *g);
Item_255b10 *__cdecl FUN_002495f0(Handle *h);
extern "C" Item_255b10 *__cdecl FUN_00249600(Handle *h, Item_255b10 *prev);
Handle *__cdecl FUN_002495e0(Group *g, Handle *h);
void __cdecl FUN_002497e0(Item_255b10 *item);
int __cdecl FUN_00247930(Group *g, Item_255b10 *item);
extern "C" void __cdecl FUN_00247a90(Group *g, Item_255b10 *item, Pair_255b10 *p);
extern "C" void __cdecl FUN_00247b30(Group *g, Item_255b10 *item, Pair_255b10 *p, int zero);
bool __cdecl FUN_00261f90(int *levels, int cur, int target);
class SeqActionCrossFade {
public:
    virtual void vfunc_0();
    virtual void vfunc_1(Source_255b10 *src);
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    char pad4[4];
    Config_255b10 *config;
    int state;
    Item_255b10 *current;
    Target_255b10 *pending;
    int level;
    bool FUN_00255980(Group *g, Target_255b10 *t);
};

// 0x00255460 audio::SeqEventCrossFadeType::vfunc_0 (5 B): not yet verified
// 0x00255470 audio::SeqEventCrossFadeType::vfunc_1 (5 B): not yet verified

// 0x00255480 FUN_00255480 (6 B): matches/0x00255480.cpp
// sym: _FUN_00255480
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00255480() {
    return &(*(int*)&DAT_004e7508);
}


// 0x00255490 audio::SeqEventCrossFade::vfunc_3 (6 B): matches/0x00255490.cpp
// sym: _FUN_00255490
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00255490() {
    return &(*(int*)&DAT_004e7508);
}

} // namespace fn_fa3ba6ee

// 0x002554b0 audio::SeqActionCrossFade::vfunc_6 (152 B): matches/0x002554b0.cpp
// sym: ?vfunc_6@SeqActionCrossFade@audio@@UAEXH@Z
void audio::SeqActionCrossFade::vfunc_6(hulk_intptr __p0) { void * p = (void *)__p0;

    switch (this->f_0c) {
    case 1: {
        int value = ((Obj_2554b0*)p)->value;
        int h = Find_00247930(value, this->f_10);
        if (h) {
            if (h > 1 && h <= 4)
                this->f_0c = 2;
        } else {
            bool flag = ((*(char * *)&this->f_08)[0x18] == 0);
            int value2 = ((Obj_2554b0*)p)->value;
            FUN_00247a20(value2, this->f_10, 0, flag, 1);
        }
        break;
    }
    case 3: {
        int value = ((Obj_2554b0*)p)->value;
        int h = Find_00247930(value, this->f_10);
        if (!h) {
            this->f_0c = h;
            Stop_002497e0(this->f_10);
            this->f_10 = 0;
        }
        break;
    }
    }
}


// 0x00255550 audio::SeqActionCrossFade::vfunc_3 (3 B): matches/0x00255550.cpp
// sym: ?vfunc_3@SeqActionCrossFade@audio@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void audio::SeqActionCrossFade::vfunc_3(hulk_intptr a) {
    (void)a;
}


// 0x00255560 audio::SeqActionCrossFade::vfunc_4 (37 B): matches/0x00255560.cpp
// sym: ?vfunc_4@SeqActionCrossFade@audio@@UAEXH@Z
void audio::SeqActionCrossFade::vfunc_4(int unused) {
    if (this->f_10) {
        ReleaseThing_002497e0(this->f_10);
        this->f_10 = 0;
    }
    this->f_0c = 0;
}


// 0x00255590 audio::SeqActionCrossFade::vfunc_5 (6 B): matches/0x00255590.cpp
// sym: ?vfunc_5@SeqActionCrossFade@audio@@UAEHH@Z
// Same code shape as 0x002514e0 (propagated; names are from that function)
int audio::SeqActionCrossFade::vfunc_5(int ) {
    return this->f_0c;
}

namespace fn_fa3ba6ee {

// 0x002555c0 FUN_002555c0 (86 B): matches/0x002555c0.cpp
// sym: ??0SeqEventCrossFadeType_2555c0@fn_fa3ba6ee@@QAE@XZ
SeqEventCrossFadeType_2555c0::SeqEventCrossFadeType_2555c0() throw() : FUN_002605e0(((FUN_00240060 *)((owners::String_23fc40 *)&(FUN_00240060()))->FUN_0023fc40("X-Fade", (hulk_intptr)0)), &(U64 const&)(FUN_002672f0("SeqEventCrossFade", 0, 0)), (int)sizeof(AudioSeqEventCrossFade), (int)__alignof(AudioSeqEventCrossFade)) { HULK_SIZE32(AudioSeqEventCrossFade, 0x34); }

} // namespace fn_fa3ba6ee

// 0x00255620 audio::SeqEventCrossFadeType::vfunc_2 (30 B): matches/0x00255620.cpp
// sym: ??_GSeqEventCrossFadeType@audio@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
audio::SeqEventCrossFadeType::~SeqEventCrossFadeType() {}

namespace fn_fa3ba6ee {

// 0x00255660 audio::SeqActionCrossFade::vfunc_0 (36 B): matches/0x00255660.cpp
// sym: ?vfunc_0@SeqActionCrossFade_255660@fn_fa3ba6ee@@UAEPAV12@H@Z
SeqActionCrossFade_255660* SeqActionCrossFade_255660::vfunc_0(int flag) {
    *(void**)this = (void*)((hulk_intptr)DAT_004298fc);
    if (flag & 1)
        FUN_00247550((void*)((hulk_intptr)DAT_004e74c0), this);
    return this;
}


// 0x00255690 FUN_00255690 (83 B): matches/0x00255690.cpp
// sym: ??0SeqEventCrossFade@fn_fa3ba6ee@@QAE@XZ
SeqEventCrossFade::SeqEventCrossFade() : a(0), b(1000), c(0), d(1000), e(0), f(0), track("MySeqTrack", 2) {
    name = find_002673a0("stitched", 0);
    x = 0;
    y = 0;
}

} // namespace fn_fa3ba6ee

// 0x002556f0 audio::SeqEventCrossFade::vfunc_4 (53 B): matches/0x002556f0.cpp [wrapped: conflict: SeqEventCrossFade]
// sym: ?vfunc_4@SeqEventCrossFade@fn_002556f0@@UAEPAU12@E@Z
namespace fn_002556f0 {
// data: gData_2556f0 = DAT_004e7508

typedef unsigned char byte_2556f0;
struct Sub1_2556f0 {
    void Fnm_00262020();
};
struct Sub2_2556f0 {
    void Fnm_00240060();
};
struct Sub3_2556f0 {
    void Fnm_0025fd10();
};
extern "C" void __cdecl FUN_00247550(void*, void*);
struct SeqEventCrossFade {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual SeqEventCrossFade* vfunc_4(byte_2556f0 p);
    AudioSeqEventLink link;                 // the record's words past the vftable (records.h AudioSeqEventCrossFade)
    unsigned int fadeInStartMs;
    unsigned int fadeInMs;
    unsigned int fadeOutStartMs;
    unsigned int fadeOutMs;
    unsigned char targetResume;
    unsigned char isSynchronous;
    unsigned char pad1a[2];
    OmString seqTrackName;
    int beatLayerName;
    AudioSeqBeatSet beatSet;
};
SeqEventCrossFade* SeqEventCrossFade::vfunc_4(byte_2556f0 p) {
    reinterpret_cast<Sub1_2556f0*>(&beatSet)->Fnm_00262020();
    reinterpret_cast<Sub2_2556f0*>(&seqTrackName)->Fnm_00240060();
    reinterpret_cast<Sub3_2556f0*>(this)->Fnm_0025fd10();
    if (p & 1)
        FUN_00247550(((char*)&DAT_004e7508), this);
    return this;
}
} // namespace fn_002556f0


// 0x00255730 audio::SeqEventCrossFade::vfunc_1 (307 B): equivalent/0x00255730.cpp [wrapped: conflict: audio::SeqEvent; audio::SeqEventCrossFade]
// sym: ?vfunc_1@SeqEventCrossFade@audio@fn_00255730@@UAEDPAUArchive_255730@3@@Z @0d6b1051c937 @wc549747cfe26
namespace fn_00255730 {
// STATUS: equivalent (tools/equiv.py level 3: 101 inputs, branch coverage 24/24)
// audio::SeqEventCrossFade::vfunc_1 @ 0x00255730
struct Writer_255730 {
    char pad0[0x24];
    int indent;
};

struct Archive_255730 {
    Writer_255730 *writer;
};

struct NameBuf {
    char data[4];
};

struct BeatSet {
    char data[4];
};

struct TrackName {
    char data[0xc];
};

char FUN_00246f50(Writer_255730 *writer, const char *fmt, ...);
extern "C" char FUN_0024eb60(Archive_255730 *ar, const char *name, unsigned int *value);
char FUN_00250ef0(Archive_255730 *ar, const char *name, char *value);
extern "C" char FUN_0024e600(Archive_255730 *ar, const char *name, TrackName *value);
extern "C" char FUN_0024eff0(Archive_255730 *ar, const char *name, NameBuf *value);
extern "C" char FUN_00250640(Archive_255730 *ar, const char *name, BeatSet *value);

namespace audio {

class SeqEvent {
public:
    virtual char vfunc_0(Archive_255730 *ar);
    virtual char vfunc_1(Archive_255730 *ar);
    virtual char vfunc_2(Archive_255730 *ar);
    virtual char vfunc_3(Archive_255730 *ar);
    virtual char vfunc_4(Archive_255730 *ar);
    virtual char vfunc_5(Archive_255730 *ar);
    char pad04[4];
};

class SeqEventCrossFade : public SeqEvent {
public:
    virtual char vfunc_0(Archive_255730 *ar);
    virtual char vfunc_1(Archive_255730 *ar);
    unsigned int fadeInStartMs;
    unsigned int fadeInMs;
    unsigned int fadeOutStartMs;
    unsigned int fadeOutMs;
    char targetResume;
    char isSynchronous;
    char pad1a[2];
    TrackName seqTrackName;
    NameBuf beatLayerNameBuf;
    BeatSet beatSet;
};

char SeqEventCrossFade::vfunc_1(Archive_255730 *ar)
{
    if (!SeqEvent::vfunc_1(ar))
        return 0;
    if (!FUN_00246f50(ar->writer, "\n[\n"))
        return 0;
    ar->writer->indent++;
    if (!FUN_0024eb60(ar, "mFadeInStartMs", &fadeInStartMs))
        return 0;
    if (!FUN_0024eb60(ar, "mFadeInMs", &fadeInMs))
        return 0;
    if (!FUN_0024eb60(ar, "mFadeOutStartMs", &fadeOutStartMs))
        return 0;
    if (!FUN_0024eb60(ar, "mFadeOutMs", &fadeOutMs))
        return 0;
    if (!FUN_00250ef0(ar, "mTargetResume", &targetResume))
        return 0;
    if (!FUN_00250ef0(ar, "mIsSynchronous", &isSynchronous))
        return 0;
    if (!FUN_0024e600(ar, "mSeqTrackName", &seqTrackName))
        return 0;
    if (!FUN_0024eff0(ar, "mBeatLayerNameBuf", &beatLayerNameBuf))
        return 0;
    if (!FUN_00250640(ar, "mBeatSet", &beatSet))
        return 0;
    ar->writer->indent--;
    if (!FUN_00246f50(ar->writer, "]\n"))
        return 0;
    return 1;
}

}
} // namespace fn_00255730


// 0x00255870 audio::SeqEventCrossFade::vfunc_0 (192 B): matches/0x00255870.cpp [wrapped: conflict: SeqEventCrossFade]
// sym: ?vfunc_0@SeqEventCrossFade@fn_00255870@@UAEHPAX@Z
namespace fn_00255870 {
class SeqEvent {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
extern "C" char FUN_0025abd0(void*, void*);
extern "C" char FUN_0025aa80(void*, void*);
extern "C" char FUN_0025bce0(void*, void*);
extern "C" char FUN_0024f010(void*, void*);
class Tail_255870 {
  public:
    AudioSeqBeatSet set;
    char Fnf_00261ef0(void*);
};
class SeqEventCrossFade : public SeqEvent {
  public:
    AudioSeqEventLink link;                 // the record's words past the vftable (records.h AudioSeqEventCrossFade)
    unsigned int fadeInStartMs;
    unsigned int fadeInMs;
    unsigned int fadeOutStartMs;
    unsigned int fadeOutMs;
    unsigned char targetResume;
    unsigned char isSynchronous;
    unsigned char pad1a[2];
    OmString seqTrackName;
    int beatLayerName;
    Tail_255870 tail;                       // beatSet
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
int SeqEventCrossFade::vfunc_0(void* p) {
    if ((char)SeqEvent::vfunc_0(p) && FUN_0025abd0(p, &fadeInStartMs) && FUN_0025abd0(p, &fadeInMs) &&
        FUN_0025abd0(p, &fadeOutStartMs) && FUN_0025abd0(p, &fadeOutMs) && FUN_0025aa80(p, &targetResume) &&
        FUN_0025aa80(p, &isSynchronous) && FUN_0025bce0(p, &seqTrackName) && FUN_0024f010(p, &beatLayerName) &&
        tail.Fnf_00261ef0(p))
        return 1;
    return 0;
}
} // namespace fn_00255870


// 0x00255930 audio::SeqEventCrossFade::vfunc_2 (73 B): equivalent/0x00255930.cpp
// sym: ?vfunc_2@SeqEventCrossFade@audio@@UAEXH@Z @6ba04f85bfb8 @w150adda60fe8
// STATUS: equivalent (tools/equiv.py level 3: 19942 inputs, branch coverage 2/2)
// audio::SeqEventCrossFade::vfunc_2 @ 0x00255930
void audio::SeqEventCrossFade::vfunc_2(hulk_intptr __p0) { SeqContext * context = (SeqContext *)__p0;

    SeqActionCrossFade_255930* action = (SeqActionCrossFade_255930*)FUN_00247530(((char*)&DAT_004e74c0));
    if (action) {
        action->value10 = 0;
        action->value14 = 0;
        action->value18 = 0;
        action->valueC = 0;
        action->SeqActionCrossFade_255930::SeqActionCrossFade_255930();
        action->event = this;
    }
    context->FUN_0025dc20(action);
}

namespace fn_fa3ba6ee {

// 0x00255980 FUN_00255980 (88 B): equivalent/0x00255980.cpp
// sym: ?FUN_00255980@fn_fa3ba6ee@@YG_NPAXPAUHolder@1@@Z @fd4760c1ddd0 @wc7f0dfd6f68c
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 12/12)
// FUN_00255980 @ 0x00255980
bool __stdcall FUN_00255980(void* item, Holder* holder) { Node* node = holder->firstLink ? (Node*)((char*)holder->firstLink - 0x34) : 0; bool found = false; while (node) { int result = FUN_00247930(item,node); found = found || result == 3 || result == 4; Node* link = node->nextLink; node = link ? (Node*)((char*)link - 0x34) : 0; } return found; }

} // namespace fn_fa3ba6ee

// 0x002559e0 audio::SeqEventCrossFadeType::vfunc_3 (27 B): matches/0x002559e0.cpp
// sym: ?vfunc_3@SeqEventCrossFadeType@audio@@UAEPAXXZ
// Same code shape as 0x00242070 (propagated; names are from that function)
// data: g_data_2559e0 = DAT_004e7508
 // namespace audio
void* audio::SeqEventCrossFadeType::vfunc_3() {
    void* p = FUN_00247530(((char*)&DAT_004e7508));
    if (p)
        return (void*)(((Callee_2559e0*)p)->run_00255690());
    return (void*)(0);
}


// 0x00255a00 audio::SeqActionCrossFade::vfunc_2 (267 B): equivalent/0x00255a00.cpp [wrapped: conflict: audio::SeqActionCrossFade]
// sym: ?vfunc_2@SeqActionCrossFade@audio@fn_00255a00@@UAEXPAUContext@3@I@Z @0ac0c3ecf975 @wad7054fe4452
namespace fn_00255a00 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// audio::SeqActionCrossFade::vfunc_2 @ 0x00255a00
struct String { char data[12]; void FUN_0023fac0(); void FUN_00240170(void*); void FUN_00240060(); const char* FUN_0023fb00(); };
struct Sound_255a00 { char pad[44]; unsigned value; };
struct Bank { char pad[92]; char table[1]; };
struct Context { char pad[60]; Bank* bank; };
struct Params { char pad[28]; char name[12]; char other[1]; };
extern "C" void __cdecl FUN_002613b0(void*,String*,String*);
unsigned __cdecl FUN_002673a0(const char*,int);
void* __cdecl FUN_0024a370(Bank*,unsigned*);
extern "C" Sound_255a00* __cdecl FUN_0024a390(Bank*,void*);
Sound_255a00* __cdecl FUN_002495f0(void*);
extern "C" Sound_255a00* __cdecl FUN_0024a9c0(Bank*,void*);
extern "C" void __cdecl FUN_00247a10(Sound_255a00*);
namespace audio { struct SeqActionCrossFade { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(Context*,unsigned); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); unsigned field4; Params* params; unsigned state; Sound_255a00* current; Sound_255a00* previous; unsigned previousValue; bool FUN_00255980(Bank*,Sound_255a00*); }; }
void audio::SeqActionCrossFade::vfunc_2(Context* context,unsigned id) {
 Bank* bank=context->bank;
 String result; result.FUN_0023fac0();
 String key; key.FUN_00240170(params->name);
 FUN_002613b0(context->bank->table,&result,&key);
 key.FUN_00240060();
 id=FUN_002673a0(result.FUN_0023fb00(),0);
 void* entry=FUN_0024a370(context->bank,&id);
 if(entry) {
 previous=FUN_0024a390(bank,params->other);
 if(previous) { if(!FUN_00255980(bank,previous)) previous=0; else previousValue=previous->value; }
 current=FUN_002495f0(entry);
 if(!current) current=FUN_0024a9c0(bank,entry);
 if(current) { state=1; FUN_00247a10(current); result.FUN_00240060(); return; }
 }
 state=2; result.FUN_00240060();
}
} // namespace fn_00255a00

namespace fn_fa3ba6ee {

// 0x00255b10 audio::SeqActionCrossFade::vfunc_1 (403 B): equivalent/0x00255b10.cpp
// sym: ?vfunc_1@SeqActionCrossFade@fn_fa3ba6ee@@UAEXPAUSource_255b10@2@@Z @e4027c5db81a @w37162e316182
// STATUS: equivalent (tools/equiv.py level 3: 63 inputs, branch coverage 32/32)
// audio::SeqActionCrossFade::vfunc_1 @ 0x00255b10
void SeqActionCrossFade::vfunc_1(Source_255b10 *src)
{
    if (current) {
        if (pending) {
            if (FUN_00255980(src->group, pending)) {
                int t = pending->level;
                if (!FUN_00261f90(&config->levels, level, t)) {
                    level = t;
                    return;
                }
            }
        }

        Group *g = src->group;
        Handle *h = FUN_002495c0(g);
        while (h) {
            Item_255b10 *it = FUN_002495f0(h);
            while (it) {
                if (current == it) {
                    Pair_255b10 p1;
                    p1.a = config->f8;
                    p1.b = config->fc;
                    if (FUN_00247930(g, it) == 2)
                        FUN_00247a90(g, it, &p1);
                } else if (it->source != src) {
                    int r = FUN_00247930(g, it);
                    if (r != 0 && r != 5) {
                        Pair_255b10 p2;
                        p2.a = config->f10;
                        p2.b = config->f14;
                        FUN_00247b30(g, it, &p2, 0);
                    }
                }
                it = FUN_00249600(h, it);
            }
            h = FUN_002495e0(g, h);
        }

        if (!config->keepAlive) {
            FUN_002497e0(current);
            current = 0;
        }
    }

    if (config->keepAlive && current)
        state = 3;
    else
        state = 0;
}

} // namespace fn_fa3ba6ee
