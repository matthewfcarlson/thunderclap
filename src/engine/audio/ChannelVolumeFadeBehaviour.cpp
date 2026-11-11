// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00251850..0x00252350 (kind game, layer engine, confidence high), dominant class audio::ChannelVolumeFadeBehaviour
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "gen/audio.h"
#define TREE_TU_BEGIN namespace fn_f5ef859b {
#define TREE_TU_END }
namespace fn_f5ef859b {} using namespace fn_f5ef859b;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_f5ef859b {
struct Sub_251850 {
    void* Get() { return (char*)this + 0x1c; }
};
class SeqAction_251930 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
class SeqAction_251940 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(int);
    virtual void f5();
    virtual void f6();
};
struct Stream {
    char pad00[0x24];
    int depth;
};
struct Writer_2519e0 {
    Stream *stream;
};
char __cdecl FUN_00246f50(Stream *s, const char *text, ...);
extern "C" char __cdecl FUN_0025aaf0(Writer_2519e0 *w, int value);
struct Block { float values[16]; };
struct Object { char pad[0x3c]; Block *block; hulk_intptr FUN_00251ad0(); };
int FUN_002477f0();
Block * __cdecl FUN_00247530(int);
struct FUN_0025fd00 { virtual void dummy(); FUN_0025fd00(); };
struct SeqEventChannelVolumes : FUN_0025fd00 { char pad[4]; int a,b,c,d; int duration; int stitched; SeqEventChannelVolumes(); };
extern "C" int __cdecl FUN_002673a0(const char *, int);
extern "C" bool __cdecl Check(void*, uint);
} // namespace fn_f5ef859b
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_f5ef859b {
void* __cdecl FUN_00247530(void*);
} // namespace fn_f5ef859b
namespace audio {
struct SeqEventChannelVolumes_252070 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    int fields[5];
    int capacity;
    int name;
    void FUN_0025fd00();
};
}
namespace fn_f5ef859b {
class SeqEvent_252130 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
class SeqEventCheck {
  public:
    bool CheckBase_0025fd20(void* p);
};
extern "C" bool FUN_0025abd0(void*, void*);
extern "C" bool FUN_0024f010(void*, void*);
bool Read3_00252030(void*, void*);
struct AllocationPool { char byte; };
void* __cdecl FUN_00247530(AllocationPool*);
} // namespace fn_f5ef859b
namespace audio {
struct SeqActionChannelVolumes_252190 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    char padding[4];
    audio::SeqEventChannelVolumes* source;
    int state;
};
}
namespace fn_f5ef859b {
struct Context_252190 { void FUN_0025dc20(audio::SeqActionChannelVolumes_252190*); };


// 0x00251850 FUN_00251850 (4 B): matches/0x00251850.cpp
// sym: ?FUN_00251850@fn_f5ef859b@@YIPAXPAUSub_251850@1@@Z
void* __fastcall FUN_00251850(Sub_251850* self) {
    return (char*)self + 0x1c;
}

// 0x002518b0 audio::SeqEventChannelVolumesType::vfunc_0 (5 B): not yet verified
// 0x002518c0 audio::SeqEventChannelVolumesType::vfunc_1 (5 B): not yet verified

// 0x002518d0 FUN_002518d0 (6 B): matches/0x002518d0.cpp
// sym: _FUN_002518d0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
// DAT_004e6d30: a static om type (records.h)
extern "C" int* FUN_002518d0() {
    return &(*(int*)&DAT_004e6d30);
}


// 0x002518e0 audio::SeqEventChannelVolumes::vfunc_3 (6 B): matches/0x002518e0.cpp
// sym: _FUN_002518e0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
// DAT_004e6d30: a static om type (records.h)
extern "C" int* FUN_002518e0() {
    return &(*(int*)&DAT_004e6d30);
}

} // namespace fn_f5ef859b

// 0x002518f0 audio::SeqActionChannelVolumes::vfunc_6 (34 B): matches/0x002518f0.cpp
// sym: ?vfunc_6@SeqActionChannelVolumes@audio@@UAEXH@Z
// Same code shape as 0x0024ea30 (propagated; names are from that function)
void audio::SeqActionChannelVolumes::vfunc_6(hulk_intptr ) {
    int i = this->f_0c;
    --i;
    if (i != 0) {
        i -= 3;
        if (i != 0) {
            --i;
            if (i == 0)
                this->f_0c = 0;
            return;
        }
    }
    this->f_0c = 2;
}


// 0x00251920 audio::SeqActionChannelVolumes::vfunc_2 (10 B): matches/0x00251920.cpp
// sym: ?vfunc_2@SeqActionChannelVolumes@audio@@UAEXHH@Z
// Same code shape as 0x0024ea60 (propagated; names are from that function)
void audio::SeqActionChannelVolumes::vfunc_2(int , int ) {
    this->f_0c = 1;
}


// 0x00251930 audio::SeqActionChannelVolumes::vfunc_3 (10 B): matches/0x00251930.cpp
// sym: ?vfunc_3@SeqActionChannelVolumes@audio@@UAEXH@Z
// Same code shape as 0x0024ea70 (propagated; names are from that function)
void audio::SeqActionChannelVolumes::vfunc_3(hulk_intptr ) {
    *(int*)((char*)this + 0xc) = 4;
}


// 0x00251940 audio::SeqActionChannelVolumes::vfunc_4 (10 B): matches/0x00251940.cpp
// sym: ?vfunc_4@SeqActionChannelVolumes@audio@@UAEXH@Z
// Same code shape as 0x0024ea80 (propagated; names are from that function)
void audio::SeqActionChannelVolumes::vfunc_4(int ) {
    *(int*)((char*)this + 0xc) = 5;
}


// 0x00251950 audio::SeqActionChannelVolumes::vfunc_5 (6 B): matches/0x00251950.cpp
// sym: ?vfunc_5@SeqActionChannelVolumes@audio@@UAEHH@Z
// Same code shape as 0x002514e0 (propagated; names are from that function)
int audio::SeqActionChannelVolumes::vfunc_5(int ) {
    return this->f_0c;
}

namespace fn_f5ef859b {

// 0x002519e0 FUN_002519e0 (133 B): equivalent/0x002519e0.cpp
// sym: ?FUN_002519e0@fn_f5ef859b@@YA_NPAUWriter_2519e0@1@PBE@Z @c04ab2c733eb @w1b991398a790
// STATUS: equivalent (tools/equiv.py level 3: 383 inputs, branch coverage 10/10)
// FUN_002519e0 @ 0x002519e0
bool FUN_002519e0(Writer_2519e0 *w, const unsigned char *bytes)
{
    if (!FUN_00246f50(w->stream, "\n[\n"))
        return false;
    w->stream->depth++;
    for (unsigned int i = 0; i < 0x10; i++) {
        if (!FUN_0025aaf0(w, bytes[i]))
            return false;
        if (!FUN_00246f50(w->stream, "\n"))
            return false;
    }
    w->stream->depth--;
    return FUN_00246f50(w->stream, "\n]\n") != 0;
}


// 0x00251ad0 FUN_00251ad0 (87 B): equivalent/0x00251ad0.cpp
// sym: ?FUN_00251ad0@Object@fn_f5ef859b@@QAEHXZ @34c20f564480 @wb19e86673236
// STATUS: equivalent (tools/equiv.py level 3: 15806 inputs, branch coverage 2/2)
// FUN_00251ad0 @ 0x00251ad0
// FUN_00251ad0 @ 0x00251ad0
hulk_intptr Object::FUN_00251ad0() { Block *p = FUN_00247530(FUN_002477f0()); if (p) { for (int i=0;i<16;++i) p->values[i]=1.0f; } block=p;     return (hulk_intptr)(block);
}

} // namespace fn_f5ef859b

// 0x00251b40 FUN_00251b40 (86 B): equivalent/0x00251b40.cpp [wrapped: conflict: audio::SeqEventChannelVolumesType]
// sym: ?FUN_00251b40@SeqEventChannelVolumesType@audio@fn_00251b40@@QAEPAU123@XZ @d03d9587240c @wdfa61429e595
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_00251b40 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00251b40 @ 0x00251b40
// FUN_00251b40 @ 0x00251b40
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

typedef __int64 Int64;
struct ChannelValue {
    char data[12];
    // equiv-conv: FUN_0023fc40 ecx stack stack
    ChannelValue *FUN_0023fc40(const char *, int);
    void FUN_00240060();
};
namespace audio {
struct SeqEventChannelVolumesType {
    virtual void placeholder();
    // equiv-conv: FUN_002605e0 ecx stack stack stack stack
    void FUN_002605e0(ChannelValue *, const Int64 *, int, int);
    SeqEventChannelVolumesType *FUN_00251b40();
};
}
audio::SeqEventChannelVolumesType *audio::SeqEventChannelVolumesType::FUN_00251b40() {
    HULK_SIZE32(AudioSeqEventChannelVolumes, 0x20);
    Int64 value = FUN_002672f0("SeqEventChannelVolumes", 0, 0);
    ChannelValue channel;
    ChannelValue *result = channel.FUN_0023fc40("ChVol", 0);
    FUN_002605e0(result, &value, (int)sizeof(AudioSeqEventChannelVolumes), (int)__alignof(AudioSeqEventChannelVolumes));
    channel.FUN_00240060();
    SeqEventChannelVolumesType marker;
    *(unsigned int *)this = *(unsigned int *)&marker;
    return this;
}
} // namespace fn_00251b40
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00251ba0 audio::SeqEventChannelVolumesType::vfunc_2 (30 B): matches/0x00251ba0.cpp
// sym: ??_GSeqEventChannelVolumesType@audio@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
audio::SeqEventChannelVolumesType::~SeqEventChannelVolumesType() {}

namespace fn_f5ef859b {

// 0x00251bc0 FUN_00251bc0 (57 B): equivalent/0x00251bc0.cpp
// sym: ??0SeqEventChannelVolumes@fn_f5ef859b@@QAE@XZ @520bc53020f9 @w7d171f646709
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00251bc0 @ 0x00251bc0
SeqEventChannelVolumes::SeqEventChannelVolumes() { duration=1000; stitched=FUN_002673a0("stitched",0); a=b=c=d=0; }

} // namespace fn_f5ef859b

// 0x00251c00 audio::SeqEventChannelVolumes::vfunc_4 (35 B): matches/0x00251c00.cpp [wrapped: conflict: SeqEventChannelVolumes]
// sym: ?f4@SeqEventChannelVolumes@fn_00251c00@@UAEPAV12@H@Z
namespace fn_00251c00 {

class SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    void Base_0025fd10();
};
class SeqEventChannelVolumes : public SeqEvent {
  public:
    virtual SeqEventChannelVolumes* f4(int);
};
extern "C" void __cdecl FUN_00247550(void*, void*);
SeqEventChannelVolumes* SeqEventChannelVolumes::f4(int flag) {
    Base_0025fd10();
    if (flag & 1)
        FUN_00247550(((char*)((char*)&DAT_004e6d30)), this);
    return this;
}
} // namespace fn_00251c00


// 0x00251c50 audio::SeqActionChannelVolumes::vfunc_0 (36 B): matches/0x00251c50.cpp [wrapped: conflict: audio::SeqAction]
// sym: ??0SeqAction@audio@fn_00251c50@@QAE@H@Z
namespace fn_00251c50 {
// data: g_bss = DAT_004e6ce0

extern "C" char DAT_004298fc[];
namespace audio {
class SeqAction {
  public:
    hulk_intptr vptr;
    SeqAction(int);
};
} // namespace audio
extern "C" void __cdecl FUN_00247550(void*, void*);
audio::SeqAction::SeqAction(int flag) {
    vptr = ((hulk_intptr)DAT_004298fc);
    if (flag & 1)
        FUN_00247550(((char*)&DAT_004e6ce0), this);
}
} // namespace fn_00251c50


// 0x00251cb0 audio::ChannelVolumeFadeBehaviour::vfunc_0 (36 B): matches/0x00251cb0.cpp [wrapped: conflict: audio::ChannelVolumeFadeBehaviour]
// sym: ?vfunc_0@ChannelVolumeFadeBehaviour@audio@fn_00251cb0@@UAEPAV123@H@Z
namespace fn_00251cb0 {
// data: gdata = DAT_004e6d98

extern "C" char DAT_0042991c[];
namespace audio {
class ChannelVolumeFadeBehaviour;
}
class DynBehaviour {
  public:
    virtual audio::ChannelVolumeFadeBehaviour* vfunc_0(int);
    virtual void vfunc_1();
};
namespace audio {
class ChannelVolumeFadeBehaviour : public DynBehaviour {
  public:
    virtual ChannelVolumeFadeBehaviour* vfunc_0(int);
    virtual void vfunc_1();
};
} // namespace audio
extern "C" void __cdecl FUN_00247550(void*, void*);
audio::ChannelVolumeFadeBehaviour* audio::ChannelVolumeFadeBehaviour::vfunc_0(int x) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0042991c);
    if (x & 1)
        FUN_00247550(((int*)&DAT_004e6d98), this);
    return this;
}
} // namespace fn_00251cb0


// 0x00251ce0 audio::ChannelVolumeFadeBehaviour::vfunc_1 (755 B): equivalent/0x00251ce0.cpp [wrapped: conflict: audio::ChannelVolumeFadeBehaviour]
// sym: ?vfunc_1@ChannelVolumeFadeBehaviour@audio@fn_00251ce0@@UAE_NHH@Z @9031f8c5d9e5 @w6bf03d32ab2d
namespace fn_00251ce0 {
// STATUS: equivalent (tools/equiv.py level 3: 19929 inputs, branch coverage 54/54)
// audio::ChannelVolumeFadeBehaviour::vfunc_1 @ 0x00251ce0
namespace audio {
class ChannelVolumeFadeBehaviour {
public:
    virtual void vfunc_0();
    virtual bool vfunc_1(int a1, int elapsed);
    char pad04[0x14];
    int duration;               // 0x18
    unsigned char *targets;     // 0x1c
    float *volumes;             // 0x20
};

// Moves the 16 channel volumes toward their targets (targets[i] / 255); true when all arrived.
bool ChannelVolumeFadeBehaviour::vfunc_1(int a1, int elapsed)
{
    hulk_freg step;
    if (duration == 0)
        step = 1.0f;
    else
        step = (hulk_freg)elapsed / duration;

    int arrived = 0;
    for (int i = 0; i < 16; i++) {
        hulk_freg cur = volumes[i];
        float target = targets[i] * 0.003921569f;
        if (cur < target) {
            hulk_freg v = cur + step;
            if (!(v >= target)) {
                volumes[i] = v;
            } else {
                volumes[i] = target;
                arrived++;
            }
        } else {
            hulk_freg v = cur - step;
            if (!(v <= target)) {
                volumes[i] = v;
            } else {
                volumes[i] = target;
                arrived++;
            }
        }
    }
    return arrived == 16;
}
}
} // namespace fn_00251ce0

namespace fn_f5ef859b {

// 0x00252030 FUN_00252030 (51 B): matches/0x00252030.cpp
// sym: ?Target@fn_f5ef859b@@YA_NPAXH@Z
bool __cdecl Target(void* p, int offset) {
    for (uint i = 0; i < 0x10; ++i) {
        if (!Check(p, i + offset))
            return false;
    }
    return true;
}

} // namespace fn_f5ef859b

// 0x00252070 audio::SeqEventChannelVolumesType::vfunc_3 (80 B): equivalent/0x00252070.cpp
// sym: ?vfunc_3@SeqEventChannelVolumesType@audio@@UAEPAXXZ @afdbbf26f4e5 @w11d3902adb75
// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 2/2)
// audio::SeqEventChannelVolumesType::vfunc_3 @ 0x00252070
void* audio::SeqEventChannelVolumesType::vfunc_3() {
    SeqEventChannelVolumes_252070* result = (SeqEventChannelVolumes_252070*)FUN_00247530(((char*)((char*)&DAT_004e6d30)));
    if (!result) return (void*)(0);
    result->FUN_0025fd00();
    new (result) SeqEventChannelVolumes_252070;
    result->capacity = 1000;
    result->name = FUN_002673a0("stitched", 0);
    result->fields[1] = 0;
    result->fields[2] = 0;
    result->fields[3] = 0;
    result->fields[4] = 0;
    return (void*)(result);
}


// 0x002520c0 audio::SeqEventChannelVolumes::vfunc_1 (97 B): equivalent/0x002520c0.cpp [wrapped: conflict: audio::SeqEvent; audio::SeqEventChannelVolumes]
// sym: ?vfunc_1@SeqEventChannelVolumes@audio@fn_002520c0@@UAEEPAPAX@Z @fb219e1bd6b8 @wbd66afcc8bab
namespace fn_002520c0 {
// STATUS: equivalent (tools/equiv.py level 3: 2853 inputs, branch coverage 6/6)
// audio::SeqEventChannelVolumes::vfunc_1 @ 0x002520c0
namespace audio {
struct SeqEvent {
    virtual void vfunc_0();
    virtual unsigned char vfunc_1(void **);
};
struct SeqEventChannelVolumes : SeqEvent {
    char pad[0x14];
    float fadeTime;
    virtual unsigned char vfunc_1(void **);
};
}
struct Output { char pad[0x24]; int depth; };
unsigned char __cdecl FUN_00246f50(Output *, const char *, ...);
extern "C" unsigned char __cdecl FUN_0024eb60(void **, const char *, float *);
unsigned char audio::SeqEventChannelVolumes::vfunc_1(void **stream) {
    if (SeqEvent::vfunc_1(stream)) {
        if (FUN_00246f50((Output *)*stream, "\n[\n")) {
            ++((Output *)*stream)->depth;
            if (FUN_0024eb60(stream, "mFadeTime", &fadeTime))
                FUN_00246f50((Output *)*stream, "%s ", "mLayerNameBuf");
        }
    }
    return 0;
}
} // namespace fn_002520c0


// 0x00252130 audio::SeqEventChannelVolumes::vfunc_0 (86 B): matches/0x00252130.cpp
// sym: ?vfunc_0@SeqEventChannelVolumes@audio@@UAEHPAX@Z
int audio::SeqEventChannelVolumes::vfunc_0(void* __p0) { void * p = (void *)__p0;

    if (((SeqEventCheck*)this)->CheckBase_0025fd20(p)) {
        if (FUN_0025abd0(p, (char*)this + 0x18)) {
            if (FUN_0024f010(p, (char*)this + 0x1c)) {
                if (Read3_00252030(p, (char*)this + 8)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}


// 0x00252190 audio::SeqEventChannelVolumes::vfunc_2 (66 B): equivalent/0x00252190.cpp
// sym: ?vfunc_2@SeqEventChannelVolumes@audio@@UAEXH@Z @844f015bc48f @w2f2e1e872d2e
// STATUS: equivalent (tools/equiv.py level 3: 19941 inputs, branch coverage 2/2)
// audio::SeqEventChannelVolumes::vfunc_2 @ 0x00252190
void audio::SeqEventChannelVolumes::vfunc_2(hulk_intptr __p0) { void * context = (void *)__p0;

    void* memory = FUN_00247530(((AllocationPool*)&DAT_004e6ce0));
    audio::SeqActionChannelVolumes_252190* action = (audio::SeqActionChannelVolumes_252190*)memory;
    if (action) {
        action->audio::SeqActionChannelVolumes_252190::SeqActionChannelVolumes_252190();
        action->source = this;
        action->state = 0;
    }
    ((Context_252190*)context)->FUN_0025dc20(action);
}

