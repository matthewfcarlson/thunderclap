// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00252350..0x00252780 (kind game, layer engine, confidence high), dominant class audio::SeqEventVarVolumeRand
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "gen/audio.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f0c19b70 {
#define TREE_TU_END }
namespace fn_f0c19b70 {} using namespace fn_f0c19b70;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_f0c19b70 {
extern void* hulk_at_00429f0c;
class SeqEventVarVolumeRand_252380 {
  public:
    void* vf;
    int pad;
    float a;
    float b;
};
struct SeqEventVarVolumeRand_nv_252380 {
    void Init_0025fd00();
};
extern "C" bool FUN_0025ac10(void*, void*);
class SeqEventVarVolumeRand_2523a0 : public audio::SeqEvent {
  public:
    char pad[8];
    int x;
    int y;
    int vfunc_0(void* p);
};
class SeqAction_252440 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
class SeqAction_252450 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(int);
    virtual void f5();
    virtual void f6();
};
extern "C" unsigned char __cdecl FUN_00246f50(const char*, const char*, ...);
extern "C" unsigned char __cdecl FUN_0025abf0(const char**, const char*);
} // namespace fn_f0c19b70
namespace audio {
struct SeqEventVarVolumeRandType_nv_2524e0 {
    void FUN_002605e0(void*, const __int64*, int, int);
};
}
namespace fn_f0c19b70 {
struct Local { char data[32];   };
extern void* DAT_00429f28[];
extern "C" unsigned char DAT_004e6e20[112];
} // namespace fn_f0c19b70
namespace audio {
class Base {
  public:
    Base();
    virtual int Fna_002523a0(void*);
    virtual int Fnb_002525d0(void*);
    virtual void Fnc_002526f0(hulk_intptr);
    virtual void d();
    int unk;
};
}
namespace audio {
class SeqEventVarVolumeRand_252560 : public Base {
  public:
    float x;
    float y;
    SeqEventVarVolumeRand_252560() : Base(), x(0.5f), y(1.0f) {}
};
}
namespace fn_f0c19b70 {
extern "C" void* __cdecl alloc(void*);
class SeqEventVarVolumeRand_2525a0 : public audio::SeqEvent {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual SeqEventVarVolumeRand_2525a0* vfunc_4(int);
};
extern void FUN_00247550(void*, SeqEventVarVolumeRand_2525a0*);
extern void* hulk_at_004298fc[];
extern void* g_vftable2[];
} // namespace fn_f0c19b70
void operator delete(void*);
namespace fn_f0c19b70 {
class Ref_252680 {
  public:
    virtual void F0();
    virtual void Release();
};
class SeqAction_252680 {
  public:
    void* vptr;
    void Fin();
};
class SeqActionVarVolumeRand_252680 : public SeqAction_252680 {
  public:
    SeqActionVarVolumeRand_252680* f2(unsigned char flags);
};
} // namespace fn_f0c19b70
namespace audio {
struct Range {
    char pad[8];
    float a, b;
};
}
namespace audio {
struct Target {
    char pad[20];
    float volume;
};
}
namespace audio {
struct Context_2526b0 {
    char pad[4];
    Target* target;
};
}
namespace audio {
class SeqAction_2526b0 {
  public:
    virtual void v0();
    virtual void v1(Context_2526b0*);
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    int extra;
};
}
namespace fn_f0c19b70 {
class Random {
  public:
    float Get_000787e0(float, float);
};
inline float keep(float x, volatile float& v) {
    v = x;
    return x;
}
} // namespace fn_f0c19b70
inline void* operator new(size_t, void* p) {
    return p;
}
namespace audio {
class SeqActionVarVolumeRand_2526f0 {
  public:
    virtual void* v0_00252680(char);
    virtual void v1_002526b0(void*);
    int unused;
    audio::SeqEventVarVolumeRand* owner;
    int value;
    SeqActionVarVolumeRand_2526f0(audio::SeqEventVarVolumeRand* p) : owner(p), value(0) {}
};
}
namespace audio {
class Receiver {
  public:
    void Set_0025dc20(SeqActionVarVolumeRand_2526f0*);
};
}
namespace audio {
class SeqEvent_2526f0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(Receiver*);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
}
namespace fn_f0c19b70 {
extern "C" void* __cdecl FUN_00247530(void*);

// 0x00252350 audio::SeqEventVarVolumeRandType::vfunc_0 (5 B): not yet verified
// 0x00252360 audio::SeqEventVarVolumeRandType::vfunc_1 (5 B): not yet verified

// 0x00252370 FUN_00252370 (6 B): matches/0x00252370.cpp
// sym: _FUN_00252370
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
// DAT_004e6e28: a static om type (records.h)
extern "C" int* FUN_00252370() {
    return &(*(int*)&DAT_004e6e28);
}


// 0x00252380 FUN_00252380 (32 B): matches/0x00252380.cpp
// sym: ?FUN_00252380@fn_f0c19b70@@YIPAVSeqEventVarVolumeRand_252380@1@PAV21@@Z
SeqEventVarVolumeRand_252380* __fastcall FUN_00252380(SeqEventVarVolumeRand_252380* self) {
    ((SeqEventVarVolumeRand_nv_252380*)(((audio::SeqEventVarVolumeRand*)(self))))->Init_0025fd00();
    self->vf = &hulk_at_00429f0c;
    self->a = 0.5f;
    self->b = 1.0f;
    return self;
}


// 0x002523a0 audio::SeqEventVarVolumeRand::vfunc_0 (69 B): matches/0x002523a0.cpp
// sym: ?vfunc_0@SeqEventVarVolumeRand_2523a0@fn_f0c19b70@@UAEHPAX@Z
int SeqEventVarVolumeRand_2523a0::vfunc_0(void* p) {
    char r = (char)audio::SeqEvent::vfunc_0(p);
    if (r) {
        if (FUN_0025ac10(p, (char*)this + 8)) {
            if (FUN_0025ac10(p, (char*)this + 12))
                return 1;
        }
    }
    return 0;
}


// 0x002523f0 audio::SeqEventVarVolumeRand::vfunc_3 (6 B): matches/0x002523f0.cpp
// sym: _FUN_002523f0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
// DAT_004e6e28: a static om type (records.h)
extern "C" int* FUN_002523f0() {
    return &(*(int*)&DAT_004e6e28);
}

} // namespace fn_f0c19b70

// 0x00252400 audio::SeqActionVarVolumeRand::vfunc_6 (34 B): matches/0x00252400.cpp
// sym: ?vfunc_6@SeqActionVarVolumeRand@audio@@UAEXH@Z
// Same code shape as 0x0024ea30 (propagated; names are from that function)
void audio::SeqActionVarVolumeRand::vfunc_6(hulk_intptr ) {
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


// 0x00252430 audio::SeqActionVarVolumeRand::vfunc_2 (10 B): matches/0x00252430.cpp
// sym: ?vfunc_2@SeqActionVarVolumeRand@audio@@UAEXHH@Z
// Same code shape as 0x0024ea60 (propagated; names are from that function)
void audio::SeqActionVarVolumeRand::vfunc_2(int , int ) {
    this->f_0c = 1;
}


// 0x00252440 audio::SeqActionVarVolumeRand::vfunc_3 (10 B): matches/0x00252440.cpp
// sym: ?vfunc_3@SeqActionVarVolumeRand@audio@@UAEXH@Z
// Same code shape as 0x0024ea70 (propagated; names are from that function)
void audio::SeqActionVarVolumeRand::vfunc_3(hulk_intptr ) {
    *(int*)((char*)this + 0xc) = 4;
}


// 0x00252450 audio::SeqActionVarVolumeRand::vfunc_4 (10 B): matches/0x00252450.cpp
// sym: ?vfunc_4@SeqActionVarVolumeRand@audio@@UAEXH@Z
// Same code shape as 0x0024ea80 (propagated; names are from that function)
void audio::SeqActionVarVolumeRand::vfunc_4(int ) {
    *(int*)((char*)this + 0xc) = 5;
}


// 0x00252460 audio::SeqActionVarVolumeRand::vfunc_5 (6 B): matches/0x00252460.cpp
// sym: ?vfunc_5@SeqActionVarVolumeRand@audio@@UAEHH@Z
// Same code shape as 0x002514e0 (propagated; names are from that function)
int audio::SeqActionVarVolumeRand::vfunc_5(int ) {
    return this->f_0c;
}

namespace fn_f0c19b70 {

// 0x00252470 FUN_00252470 (72 B): matches/0x00252470.cpp
// sym: _FUN_00252470
// data: fmt = DAT_004298a8
extern "C" unsigned char __cdecl FUN_00252470(const char** text, const char* value, const char** other) {
    const char* s = *text;
    if (FUN_00246f50(s, DAT_004298a8, value)) {
        if (FUN_0025abf0(text, *other)) {
            value = *text;
            return FUN_00246f50(value, DAT_00422518);
        }
    }
    return 0;
}

} // namespace fn_f0c19b70

// 0x002524e0 FUN_002524e0 (86 B): equivalent/0x002524e0.cpp
// sym: ?FUN_002524e0@SeqEventVarVolumeRandType@audio@@QAEPAXXZ @600f408cffe6 @we74d6218be6a
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002524e0 @ 0x002524e0
void* audio::SeqEventVarVolumeRandType::FUN_002524e0() { HULK_SIZE32(AudioSeqEventVarVolumeRand, 0x10); __int64 value = FUN_002672f0("SeqEventVarVolumeRand", 0, 0); Local local; void* p = ((void *)((owners::String_23fc40 *)&local)->FUN_0023fc40("Vol?", (hulk_intptr)0)); ((SeqEventVarVolumeRandType_nv_2524e0*)this)->FUN_002605e0(p, &value, (int)sizeof(AudioSeqEventVarVolumeRand), (int)__alignof(AudioSeqEventVarVolumeRand)); ((owners::Str_240060 *)&local)->FUN_00240060(); *(void**)this = DAT_00429f28; return (void*)(this); }


// 0x00252540 audio::SeqEventVarVolumeRandType::vfunc_2 (30 B): matches/0x00252540.cpp
// sym: ??_GSeqEventVarVolumeRandType@audio@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
audio::SeqEventVarVolumeRandType::~SeqEventVarVolumeRandType() {}


// 0x00252560 audio::SeqEventVarVolumeRandType::vfunc_3 (55 B): matches/0x00252560.cpp
// sym: ?vfunc_3@SeqEventVarVolumeRandType@audio@@UAEPAXXZ
void* audio::SeqEventVarVolumeRandType::vfunc_3() {
    audio::SeqEventVarVolumeRand_252560* p = (audio::SeqEventVarVolumeRand_252560*)alloc(((char*)((char*)&(*(unsigned char(*)[112])&DAT_004e6e20) + 8)));
    if (p) {
        p->audio::SeqEventVarVolumeRand_252560::SeqEventVarVolumeRand_252560();
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f0c19b70 {

// 0x002525a0 audio::SeqEventVarVolumeRand::vfunc_4 (35 B): matches/0x002525a0.cpp
// sym: ?vfunc_4@SeqEventVarVolumeRand_2525a0@fn_f0c19b70@@UAEPAV12@H@Z
SeqEventVarVolumeRand_2525a0* SeqEventVarVolumeRand_2525a0::vfunc_4(int x) {
    FUN_0025fd10((void*)(this));
    if (x & 1)
        FUN_00247550(((char*)((char*)&DAT_004e6e28)), this);
    return this;
}

} // namespace fn_f0c19b70

// 0x002525d0 audio::SeqEventVarVolumeRand::vfunc_1 (129 B): equivalent/0x002525d0.cpp [wrapped: conflict: audio::SeqEvent; audio::SeqEventVarVolumeRand]
// sym: ?vfunc_1@SeqEventVarVolumeRand@audio@fn_002525d0@@QAEHPAUWriter_2525d0@3@@Z @3daf4eeb84c9 @w74ded7e17c77
namespace fn_002525d0 {
// STATUS: equivalent (tools/equiv.py level 3: 1534 inputs, branch coverage 10/10)
// audio::SeqEventVarVolumeRand::vfunc_1 @ 0x002525d0
// 0x002525d0: audio::SeqEventVarVolumeRand::vfunc_1: write the event (base fields, then two named values) to a text stream
struct Stream {
    char pad00[0x24];
    int indent;
};

struct Writer_2525d0 {
    Stream* out;
};

char FUN_00246f50(Stream* s, const char* fmt, ...);
extern "C++" __declspec(nothrow) unsigned char __cdecl FUN_00252470(const char **, const char *, const char **);
extern "C++" __declspec(nothrow) unsigned char __cdecl FUN_00252470(const char **, const char *, const char **);

namespace audio {

class SeqEvent {
public:
    virtual void v0();
    char vfunc_1_0025fd40(Writer_2525d0* w);
    char pad04[4];
};

class SeqEventVarVolumeRand : public SeqEvent {
public:
    char field_08[4];
    char field_0c[4];
    char field_10[4];
    int vfunc_1(Writer_2525d0* w);
};

int SeqEventVarVolumeRand::vfunc_1(Writer_2525d0* w)
{
    if (!SeqEvent::vfunc_1_0025fd40(w))
        return 0;
    if (!FUN_00246f50(w->out, "\n[\n"))
        return 0;
    w->out->indent++;
    if (!((char)FUN_00252470((const char **)(Writer_2525d0 *)w, "mMinVolume", (const char **)(void *)(&field_08))))
        return 0;
    if (!((char)FUN_00252470((const char **)(Writer_2525d0 *)w, "mMaxVolume", (const char **)(void *)(&field_0c))))
        return 0;
    w->out->indent--;
    if (!FUN_00246f50(w->out, "]\n"))
        return 0;
    return 1;
}

}
} // namespace fn_002525d0

namespace fn_f0c19b70 {

// 0x00252680 audio::SeqActionVarVolumeRand::vfunc_0 (36 B): matches/0x00252680.cpp
// sym: ?f2@SeqActionVarVolumeRand_252680@fn_f0c19b70@@QAEPAV12@E@Z
// data: g_pool_252680 = DAT_004e6de0
SeqActionVarVolumeRand_252680* SeqActionVarVolumeRand_252680::f2(unsigned char flags) {
    vptr = hulk_at_004298fc;
    if (flags & 1)
        Free(((char*)&DAT_004e6de0), this);
    return this;
}

} // namespace fn_f0c19b70

// 0x002526b0 audio::SeqActionVarVolumeRand::vfunc_1 (62 B): matches/0x002526b0.cpp
// sym: ?vfunc_1@SeqActionVarVolumeRand@audio@@UAEXPAX@Z
// data: gRandom = DAT_004e5acc
void audio::SeqActionVarVolumeRand::vfunc_1(void* __p0) { Context_2526b0 * ctx = (Context_2526b0 *)__p0;

    volatile float a, b;
    Range* r = (*(Range * *)&this->f_08);
    float hi = r->b, lo = r->a;
    Target* tgt = ctx->target;
    tgt->volume = (*(Random**)&DAT_004e5acc)->Get_000787e0(keep(lo, a), keep(hi, b));
    this->f_0c = 0;
}


// 0x002526f0 audio::SeqEventVarVolumeRand::vfunc_2 (66 B): matches/0x002526f0.cpp
// sym: ?vfunc_2@SeqEventVarVolumeRand@audio@@UAEXH@Z
void audio::SeqEventVarVolumeRand::vfunc_2(hulk_intptr __p0) { Receiver * r = (Receiver *)__p0;

    void* p = FUN_00247530(&bss);
    SeqActionVarVolumeRand_2526f0* a = p ? new (p) SeqActionVarVolumeRand_2526f0(this) : 0;
    r->Set_0025dc20(a);
}

