// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00253370..0x00253750 (kind game, layer engine, confidence high), dominant class audio::SeqEventVarPitchRand
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "gen/audio.h"
#define TREE_TU_BEGIN namespace fn_f3b07bfc {
#define TREE_TU_END }
namespace fn_f3b07bfc {} using namespace fn_f3b07bfc;
namespace fn_f3b07bfc { extern "C" char DAT_0042a150[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_f3b07bfc {
extern int hulk_at_0042a150;
class SeqEventVarPitchRand {
  public:
    void init_0025fd00();
    SeqEventVarPitchRand();
    hulk_intptr vptr;
    int unused;
    int a;
    int b;
};
extern "C" bool FUN_0025ac10(void*, void*);
class SeqEventVarPitchRand_2533c0 : public audio::SeqEvent {
  public:
    char pad[8];
    int x;
    int y;
    int vfunc_0(void* p);
};
class SeqAction_253460 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
class SeqAction_253470 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(int);
    virtual void f5();
    virtual void f6();
};
extern "C" void* __cdecl Alloc(void*);
extern int rand_vftable;
struct SeqEventVarPitchRand_253530 {
    int* vf;
    int pad;
    float a;
    float b;
    void init_0025fd00();
};
class SeqAction {
  public:
    hulk_intptr mVptr;
};
class SeqActionVarPitchRand : public SeqAction {
  public:
    SeqActionVarPitchRand* vfunc_0(int);
};
} // namespace fn_f3b07bfc
namespace audio {
struct Data {
    char pad[8];
    float lo, hi;
};
}
namespace audio {
struct Sound {
    char pad[0x24];
    float pitch;
};
}
namespace audio {
struct Context_253680 {
    char pad[4];
    Sound* snd;
};
}
namespace audio {
struct Rand {
    float between_000787e0(float, float);
};
}
namespace audio {
extern Rand* hulk_at_004e5acc;
}

// 0x00253370 audio::SeqEventVarPitchRandType::vfunc_0 (5 B): not yet verified
// 0x00253380 audio::SeqEventVarPitchRandType::vfunc_1 (5 B): not yet verified
namespace fn_f3b07bfc {

// 0x00253390 FUN_00253390 (6 B): matches/0x00253390.cpp
// sym: _FUN_00253390
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00253390() {
    return &(*(int*)&DAT_004e70e8);
}


// 0x002533a0 FUN_002533a0 (32 B): matches/0x002533a0.cpp
// sym: ??0SeqEventVarPitchRand@fn_f3b07bfc@@QAE@XZ
SeqEventVarPitchRand::SeqEventVarPitchRand() {
    init_0025fd00();
    vptr = (hulk_intptr)&hulk_at_0042a150;
    a = 0x3f4ccccd;
    b = 0x3f99999a;
}


// 0x002533c0 audio::SeqEventVarPitchRand::vfunc_0 (69 B): matches/0x002533c0.cpp
// sym: ?vfunc_0@SeqEventVarPitchRand_2533c0@fn_f3b07bfc@@UAEHPAX@Z
// Same code shape as 0x002523a0 (propagated; names are from that function)
int SeqEventVarPitchRand_2533c0::vfunc_0(void* p) {
    char r = (char)audio::SeqEvent::vfunc_0(p);
    if (r) {
        if (FUN_0025ac10(p, (char*)this + 8)) {
            if (FUN_0025ac10(p, (char*)this + 12))
                return 1;
        }
    }
    return 0;
}


// 0x00253410 audio::SeqEventVarPitchRand::vfunc_3 (6 B): matches/0x00253410.cpp
// sym: _FUN_00253410
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00253410() {
    return &(*(int*)&DAT_004e70e8);
}

} // namespace fn_f3b07bfc

// 0x00253420 audio::SeqActionVarPitchRand::vfunc_6 (34 B): matches/0x00253420.cpp
// sym: ?vfunc_6@SeqActionVarPitchRand@audio@@UAEXH@Z
// Same code shape as 0x0024ea30 (propagated; names are from that function)
void audio::SeqActionVarPitchRand::vfunc_6(hulk_intptr ) {
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


// 0x00253450 audio::SeqActionVarPitchRand::vfunc_2 (10 B): matches/0x00253450.cpp
// sym: ?vfunc_2@SeqActionVarPitchRand@audio@@UAEXHH@Z
// Same code shape as 0x0024ea60 (propagated; names are from that function)
void audio::SeqActionVarPitchRand::vfunc_2(int , int ) {
    this->f_0c = 1;
}


// 0x00253460 audio::SeqActionVarPitchRand::vfunc_3 (10 B): matches/0x00253460.cpp
// sym: ?vfunc_3@SeqActionVarPitchRand@audio@@UAEXH@Z
// Same code shape as 0x0024ea70 (propagated; names are from that function)
void audio::SeqActionVarPitchRand::vfunc_3(hulk_intptr ) {
    *(int*)((char*)this + 0xc) = 4;
}


// 0x00253470 audio::SeqActionVarPitchRand::vfunc_4 (10 B): matches/0x00253470.cpp
// sym: ?vfunc_4@SeqActionVarPitchRand@audio@@UAEXH@Z
// Same code shape as 0x0024ea80 (propagated; names are from that function)
void audio::SeqActionVarPitchRand::vfunc_4(int ) {
    *(int*)((char*)this + 0xc) = 5;
}


// 0x00253480 audio::SeqActionVarPitchRand::vfunc_5 (6 B): matches/0x00253480.cpp
// sym: ?vfunc_5@SeqActionVarPitchRand@audio@@UAEHH@Z
// Same code shape as 0x002514e0 (propagated; names are from that function)
int audio::SeqActionVarPitchRand::vfunc_5(int ) {
    return this->f_0c;
}


// 0x002534b0 FUN_002534b0 (86 B): matches/0x002534b0.cpp [wrapped: conflict: audio::SeqEventVarPitchRandType]
// sym: ?FUN_002534b0@SeqEventVarPitchRandType@audio@fn_002534b0@@QAEPAU123@XZ
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_002534b0 {
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

struct Field {
    char space[12];
    Field* FUN_0023fc40(const char*, int);
    void FUN_00240060();
};
namespace audio {
struct SeqEventVarPitchRandType {
    void** vtable;
    void FUN_002605e0(Field*, __int64*, int, int);
    SeqEventVarPitchRandType* FUN_002534b0();
};
} // namespace audio
extern void* DAT_0042a16c[];
audio::SeqEventVarPitchRandType* audio::SeqEventVarPitchRandType::FUN_002534b0() {
    HULK_SIZE32(AudioSeqEventVarPitchRand, 0x10);
    __int64 id = FUN_002672f0("SeqEventVarPitchRand", 0, 0);
    Field field;
    FUN_002605e0(field.FUN_0023fc40("Pitch?", 0), &id, (int)sizeof(AudioSeqEventVarPitchRand), (int)__alignof(AudioSeqEventVarPitchRand));
    field.FUN_00240060();
    vtable = DAT_0042a16c;
    return this;
}
} // namespace fn_002534b0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00253510 audio::SeqEventVarPitchRandType::vfunc_2 (30 B): matches/0x00253510.cpp
// sym: ??_GSeqEventVarPitchRandType@audio@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
audio::SeqEventVarPitchRandType::~SeqEventVarPitchRandType() {}


// 0x00253530 audio::SeqEventVarPitchRandType::vfunc_3 (55 B): matches/0x00253530.cpp
// sym: ?vfunc_3@SeqEventVarPitchRandType@audio@@UAEPAXXZ
// data: g_pool_253530 = DAT_004e70e8
void* audio::SeqEventVarPitchRandType::vfunc_3() {
    SeqEventVarPitchRand_253530* p = (SeqEventVarPitchRand_253530*)Alloc(((int*)&DAT_004e70e8));
    if (p) {
        p->init_0025fd00();
        p->vf = ((int*)DAT_0042a150);
        p->a = 0.8f;
        p->b = 1.2f;
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x00253570 audio::SeqEventVarPitchRand::vfunc_4 (35 B): matches/0x00253570.cpp [wrapped: conflict: SeqEventVarPitchRand]
// sym: ?vfunc_4@SeqEventVarPitchRand@fn_00253570@@UAEPAV12@H@Z
namespace fn_00253570 {

typedef unsigned int uint;
extern void __cdecl FUN_00247550(const void*, void*);
extern "C" void __fastcall FUN_0025fd10(void*);

class SeqEvent {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual SeqEvent* vfunc_4(int flags);
    virtual void vfunc_5();
};

class SeqEventVarPitchRand : public SeqEvent {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual SeqEventVarPitchRand* vfunc_4(int flags);
    virtual void vfunc_5();
};

SeqEventVarPitchRand* SeqEventVarPitchRand::vfunc_4(int flags) {
    FUN_0025fd10((void*)(this));
    if (flags & 1)
        FUN_00247550(((char*)&DAT_004e70e8), this);
    return this;
}
} // namespace fn_00253570

namespace fn_f3b07bfc {

// 0x00253650 audio::SeqActionVarPitchRand::vfunc_0 (36 B): matches/0x00253650.cpp
// sym: ?vfunc_0@SeqActionVarPitchRand@fn_f3b07bfc@@QAEPAV12@H@Z
SeqActionVarPitchRand* SeqActionVarPitchRand::vfunc_0(int flag) {
    SeqActionVarPitchRand* self = this;
    self->mVptr = ((hulk_intptr)DAT_004298fc);
    if (flag & 1)
        Register((void*)((hulk_intptr)DAT_004e70a0), self);
    return self;
}

} // namespace fn_f3b07bfc

// 0x00253680 audio::SeqActionVarPitchRand::vfunc_1 (62 B): matches/0x00253680.cpp
// sym: ?vfunc_1@SeqActionVarPitchRand@audio@@UAEXPAX@Z
 // namespace audio
void audio::SeqActionVarPitchRand::vfunc_1(void* __p0) { Context_253680 * ctx = (Context_253680 *)__p0;

    float hi = (*(Data * *)&this->f_08)->hi;
    float lo = (*(Data * *)&this->f_08)->lo;
    Sound* snd = ctx->snd;
    snd->pitch = hulk_at_004e5acc->between_000787e0(lo, hi);
    this->f_0c = 0;
}


// 0x002536c0 audio::SeqEventVarPitchRand::vfunc_2 (66 B): matches/0x002536c0.cpp [wrapped: conflict: audio::SeqActionVarPitchRand; audio::SeqEvent; audio::SeqEventVarPitchRand]
// sym: ?v2@SeqEventVarPitchRand@audio@fn_002536c0@@UAEXPAVCtx@23@@Z
inline void* operator new(size_t, void* p) {
    return p;
}
namespace fn_002536c0 {
// data: bss = DAT_004e70a0

/* size_t: tree_prelude.h */

namespace audio {
class SeqEvent;
class SeqActionVarPitchRand {
  public:
    virtual void* v0_00253650(int);
    char pad[4];
    SeqEvent* ev;
    int n;
    SeqActionVarPitchRand(SeqEvent* e) : ev(e), n(0) {}
};
class Ctx {
  public:
    void Add_0025dc20(SeqActionVarPitchRand*);
};
class SeqEvent {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2(Ctx*);
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class SeqEventVarPitchRand : public SeqEvent {
  public:
    virtual void v2(Ctx*);
};
} // namespace audio
extern "C" void* FUN_00247530(void*);
void audio::SeqEventVarPitchRand::v2(Ctx* ctx) {
    void* p = FUN_00247530(DAT_004e70a0);
    ctx->Add_0025dc20(p ? new (p) SeqActionVarPitchRand(this) : 0);
}
} // namespace fn_002536c0

