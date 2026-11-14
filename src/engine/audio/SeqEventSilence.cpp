// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00254620..0x00254a50 (kind game, layer engine, confidence high), dominant class audio::SeqEventSilence
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "gen/audio.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f967ffb0 {
#define TREE_TU_END }
namespace fn_f967ffb0 {} using namespace fn_f967ffb0;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_f967ffb0 {
extern "C" char DAT_0042a30c[];
class SeqEventSilence {
  public:
    int* vptr;
    int pad4;
    int a;
    int b;
    void Init_0025fd00();
};
bool FUN_0025abd0(void*, void*);
class SeqEventSilence_254670 : public audio::SeqEvent {
  public:
    AudioSeqEventLink link;                 // records.h AudioSeqEventSilence past the vftable
    unsigned int minTimeMs;
    unsigned int maxTimeMs;
    int vfunc_0(void* p);
};
class SeqAction_2546d0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int, char);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    char pad[0x1c];
};
typedef unsigned int u32_2546f0;
extern u32_2546f0 FUN_00267f80();
class SeqActionSilence {
    char pad[0x14];

  public:
    u32_2546f0 m14;
    u32_2546f0 m18;
    void vfunc_1(int);
};
class SeqAction_254710 {
    char pad[0x14];
};
class SeqAction_254730 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual unsigned int f5();
    virtual void f6();
};
struct Id64 { unsigned int low, high; };
struct Temp { char data[32];   };
} // namespace fn_f967ffb0
extern "C" Id64 __cdecl FUN_002672f0(const char*, int, int);
inline void* operator new(size_t, void* place) { return place; }
namespace fn_f967ffb0 {
struct SeqEventSilenceType_nv_254760 {
    void FUN_002605e0(Temp*, const Id64*, int, int);
};
typedef unsigned int u32_2547e0;
extern "C" void* __cdecl FUN_00247530(void*);
struct SeqEventSilence_2547e0 {
    hulk_uintptr vptr;
    u32_2547e0 unk;
    int duration;
    int end;
    void initialize_0025fd00();
};
extern void* hulk_at_004298fc[];
class SeqActionSilence_254920 {
  public:
    void* vptr;
    SeqActionSilence_254920* f0(unsigned char flags);
};

// 0x00254620 audio::SeqEventSilenceType::vfunc_0 (5 B): not yet verified
// 0x00254630 audio::SeqEventSilenceType::vfunc_1 (5 B): not yet verified

// 0x00254640 FUN_00254640 (6 B): matches/0x00254640.cpp
// sym: _FUN_00254640
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00254640() {
    return &(*(int*)&DAT_004e72f8);
}


// 0x00254650 FUN_00254650 (32 B): matches/0x00254650.cpp
// sym: ?FUN_00254650@fn_f967ffb0@@YIPAVSeqEventSilence@1@PAV21@@Z
SeqEventSilence* __fastcall FUN_00254650(SeqEventSilence* self) {
    self->Init_0025fd00();
    self->vptr = (int*)((hulk_intptr)DAT_0042a30c);
    self->a = 500;
    self->b = 1000;
    return self;
}


// 0x00254670 audio::SeqEventSilence::vfunc_0 (69 B): matches/0x00254670.cpp
// sym: ?vfunc_0@SeqEventSilence_254670@fn_f967ffb0@@UAEHPAX@Z
// Same code shape as 0x002523a0 (propagated; names are from that function)
int SeqEventSilence_254670::vfunc_0(void* p) {
    char r = (char)audio::SeqEvent::vfunc_0(p);
    if (r) {
        if (FUN_0025abd0(p, &this->minTimeMs)) {
            if (FUN_0025abd0(p, &this->maxTimeMs))
                return 1;
        }
    }
    return 0;
}


// 0x002546c0 audio::SeqEventSilence::vfunc_3 (6 B): matches/0x002546c0.cpp
// sym: _FUN_002546c0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_002546c0() {
    return &(*(int*)&DAT_004e72f8);
}

} // namespace fn_f967ffb0

// 0x002546d0 audio::SeqActionSilence::vfunc_2 (25 B): matches/0x002546d0.cpp
// sym: ?vfunc_2@SeqActionSilence@audio@@UAEXHH@Z
void audio::SeqActionSilence::vfunc_2(int , int __p1) { char flag = (char)__p1;

    *(int*)((char*)&this->f_18) = 2;
    if (flag)
        *(int*)((char*)&this->f_0c) = 0;
}

namespace fn_f967ffb0 {

// 0x002546f0 audio::SeqActionSilence::vfunc_1 (22 B): matches/0x002546f0.cpp
// sym: ?vfunc_1@SeqActionSilence@fn_f967ffb0@@QAEXH@Z
void SeqActionSilence::vfunc_1(int) {
    m14 = FUN_00267f80();
    m18 = 3;
}

} // namespace fn_f967ffb0

// 0x00254710 audio::SeqActionSilence::vfunc_3 (10 B): matches/0x00254710.cpp
// sym: ?vfunc_3@SeqActionSilence@audio@@UAEXH@Z
void audio::SeqActionSilence::vfunc_3(hulk_intptr ) {
    this->f_18 = 2;
}


// 0x00254720 audio::SeqActionSilence::vfunc_4 (10 B): matches/0x00254720.cpp
// sym: ?vfunc_4@SeqActionSilence@audio@@UAEXH@Z
void audio::SeqActionSilence::vfunc_4(int ) {
    this->f_18 = 0;
}


// 0x00254730 audio::SeqActionSilence::vfunc_5 (6 B): matches/0x00254730.cpp
// sym: ?vfunc_5@SeqActionSilence@audio@@UAEHH@Z
 // namespace audio
int audio::SeqActionSilence::vfunc_5(int ) {
    return (int)((*(unsigned int *)&this->f_18));
}


// 0x00254760 FUN_00254760 (86 B): equivalent/0x00254760.cpp
// sym: ?FUN_00254760@SeqEventSilenceType@audio@@QAEPAV12@XZ @b125f6c2118d @wb352b892ab25
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00254760 @ 0x00254760
audio::SeqEventSilenceType* audio::SeqEventSilenceType::FUN_00254760() {
    HULK_SIZE32(AudioSeqEventSilence, 0x10);
    Id64 id = FUN_002672f0("SeqEventSilence", 0, 0);
    Temp temp;
    ((SeqEventSilenceType_nv_254760*)this)->FUN_002605e0(((Temp *)((owners::String_23fc40 *)&temp)->FUN_0023fc40("Silnce", (hulk_intptr)0)), &id, (int)sizeof(AudioSeqEventSilence), (int)__alignof(AudioSeqEventSilence));
    ((owners::Str_240060 *)&temp)->FUN_00240060();
    new (this) audio::SeqEventSilenceType;
    return (audio::SeqEventSilenceType*)(this);
}


// 0x002547c0 audio::SeqEventSilenceType::vfunc_2 (30 B): matches/0x002547c0.cpp
// sym: ??_GSeqEventSilenceType@audio@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
audio::SeqEventSilenceType::~SeqEventSilenceType() {}


// 0x002547e0 audio::SeqEventSilenceType::vfunc_3 (55 B): matches/0x002547e0.cpp
// sym: ?vfunc_3@SeqEventSilenceType@audio@@UAEPAXXZ
// data: gPool_2547e0 = DAT_004e72f8
void* audio::SeqEventSilenceType::vfunc_3() {
    SeqEventSilence_2547e0* p = (SeqEventSilence_2547e0*)FUN_00247530(((char*)&DAT_004e72f8));
    if (p) {
        p->initialize_0025fd00();
        p->vptr = ((hulk_intptr)DAT_0042a30c);
        p->duration = 500;
        p->end = 1000;
        return (void*)(p);
    }
    return (void*)((SeqEventSilence_2547e0*)0);
}


// 0x00254820 audio::SeqEventSilence::vfunc_4 (35 B): matches/0x00254820.cpp [wrapped: conflict: SeqEventSilence]
// sym: ?v4@SeqEventSilence@fn_00254820@@UAEPAV12@H@Z
namespace fn_00254820 {

class SeqEvent {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual SeqEvent* v4(int);
    virtual void v5();
    void Prepare_0025fd10();
};
class SeqEventSilence : public SeqEvent {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual SeqEventSilence* v4(int);
};
extern void FUN_00247550(void*, SeqEventSilence*);
SeqEventSilence* SeqEventSilence::v4(int flags) {
    Prepare_0025fd10();
    if (flags & 1)
        FUN_00247550(DAT_004e72f8, this);
    return this;
}
} // namespace fn_00254820

namespace fn_f967ffb0 {

// 0x00254920 audio::SeqActionSilence::vfunc_0 (36 B): matches/0x00254920.cpp
// sym: ?f0@SeqActionSilence_254920@fn_f967ffb0@@QAEPAV12@E@Z
// data: g_pool_254920 = DAT_004e72b0
SeqActionSilence_254920* SeqActionSilence_254920::f0(unsigned char flags) {
    vptr = hulk_at_004298fc;
    if (flags & 1)
        Free(((char*)&DAT_004e72b0), this);
    return this;
}

} // namespace fn_f967ffb0

// 0x00254950 audio::SeqActionSilence::vfunc_6 (79 B): matches/0x00254950.cpp [wrapped: conflict: audio::SeqAction; audio::SeqActionSilence]
// sym: ?vfunc_6@SeqActionSilence@audio@fn_00254950@@UAEXH@Z
namespace fn_00254950 {
namespace audio {
class SeqAction {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void vfunc_6(int);
    char pad[8];
    unsigned int elapsed;
    float duration;
    int last;
    int state;
};
class SeqActionSilence : public SeqAction {
  public:
    virtual void vfunc_6(int);
};
} // namespace audio
extern "C++" __declspec(nothrow) int __cdecl tick_00267f80();
void audio::SeqActionSilence::vfunc_6(int) {
    if (state == 3) {
        int t = tick_00267f80();
        elapsed += t - last;
        last = t;
        if ((float)elapsed >= duration) {
            elapsed = (int)duration;
            state = 0;
        }
    }
}
} // namespace fn_00254950


// 0x002549a0 audio::SeqEventSilence::vfunc_2 (108 B): matches/0x002549a0.cpp [wrapped: conflict: SeqEventSilence]
// sym: ?v2@SeqEventSilence@fn_002549a0@@UAEXH@Z
namespace fn_002549a0 {
// data: g_buffer = DAT_004e72b0

class SeqEvent {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2(int);
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class SeqActionSilence {
  public:
    hulk_intptr vf;
    int pad4;
    void* owner;
    int a;
    float b;
    int pad14;
    int c;
};
class SeqEventSilence : public SeqEvent {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2(int);
    virtual void v3();
    virtual void v4();
    int pad4;
    int m8;
    int mc;
};
extern "C" void* __cdecl FUN_00247530(void*);
extern "C" int __cdecl FUN_000113e0(int, int);
extern char hulk_at_0042a36c[];
class Helper_2549a0 {
  public:
    void FUN_0025dc20(SeqActionSilence*);
};
void SeqEventSilence::v2(int arg) {
    SeqActionSilence* a = (SeqActionSilence*)FUN_00247530(((char*)&DAT_004e72b0));
    SeqActionSilence* r;
    if (a) {
        a->vf = (hulk_intptr)hulk_at_0042a36c;
        a->owner = this;
        int x = mc;
        int y = m8;
        int r2 = FUN_000113e0(y, x);
        a->a = 0;
        a->b = (float)r2;
        a->c = 0;
        r = a;
    } else
        r = 0;
    ((Helper_2549a0*)arg)->FUN_0025dc20(r);
}
} // namespace fn_002549a0

