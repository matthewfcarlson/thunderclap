// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00250080..0x002504b0 (kind game, layer engine, confidence high), dominant class audio::SeqEventWait
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "gen/audio.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f0ad381b {
#define TREE_TU_END }
namespace fn_f0ad381b {} using namespace fn_f0ad381b;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_f0ad381b {
class Target_250080 {
  public:
    char pad[8];
    void* Get();
};
class SeqEvent_2500e0 {
  public:
    virtual void V();
    SeqEvent_2500e0();
    int x;
};
class Part {
  public:
};
class SeqEventWait_2500e0 : public SeqEvent_2500e0 {
  public:
    Part part;
    SeqEventWait_2500e0();
    virtual void V();
};
} // namespace fn_f0ad381b
namespace audio {
class SeqEventNestTrack_250110 : public ::audio::SeqEvent {
  public:
    virtual int vfunc_0(void*);
    char pad[4];
};
}
namespace fn_f0ad381b {
extern "C" bool __cdecl FUN_0025bce0(void*, void*);
struct Str_250160 {
    char *data;
    short mode;
    short pad6;
    short len;
    short pad10;
    Str_250160 *FUN_0023fac0();
    bool FUN_00240310(const Str_250160 *other);
};
extern "C" void __fastcall FUN_00240060(Str_250160 *s);
struct Table_250160 { char pad[0x10]; };
struct Mgr_250160 {
    char pad[0x5c];
    Table_250160 table;
};
struct Ctx_250160 {
    char pad[0x3c];
    Mgr_250160 *mgr;
};
struct WaitData {
    char pad[8];
    Str_250160 name;
};
extern "C" void FUN_002613b0(Table_250160 *t, Str_250160 *out, Str_250160 *in);
class SeqAction_250160 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(Ctx_250160 *ctx);
    char pad04[4];
    WaitData *data;     // 0x08
    int state;          // 0x0c
};
class SeqAction_250240 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
class SeqAction_250250 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(int);
    virtual void f5();
    virtual void f6();
};
typedef unsigned int u32_250310;
extern "C" void* __cdecl FUN_00247530(void*);
extern int hulk_at_00429b6c;
class NameObj_250310 {
  public:
};
class NestTrack_250310 {
  public:
    hulk_uintptr vf;
    char pad[4];
    NameObj_250310 name;
    void init_0025fd00();
};
class Elem_250350 {
  public:
};
class SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    char pad[4];
    Elem_250350 sub;
};
class SeqEventWait : public SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual SeqEventWait* f4(int);
    void Finish_0025fd10();
};
extern "C" void __cdecl FUN_00247550(void*, void*);
} // namespace fn_f0ad381b
namespace audio {
class SeqActionWait_250460 {
  public:
    virtual void v0();
    virtual void v1();
    int pad;
    audio::SeqEventWait* event;
    int zero;
    SeqActionWait_250460(audio::SeqEventWait* e) : event(e), zero(0) {}
};
}
namespace fn_f0ad381b {
class Target {
  public:
    void set_0025dc20(audio::SeqActionWait_250460*);
};
} // namespace fn_f0ad381b
namespace audio {
class SeqEvent_250460 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
}
namespace fn_f0ad381b {
extern "C" void* __cdecl alloc(void*);


// 0x00250080 FUN_00250080 (4 B): matches/0x00250080.cpp
// sym: ?Get@Target_250080@fn_f0ad381b@@QAEPAXXZ
void* Target_250080::Get() {
    return (void*)((char*)this + 8);
}

// 0x002500b0 audio::SeqEventWaitType::vfunc_0 (5 B): not yet verified
// 0x002500c0 audio::SeqEventWaitType::vfunc_1 (5 B): not yet verified

// 0x002500d0 FUN_002500d0 (6 B): matches/0x002500d0.cpp
// sym: _FUN_002500d0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_002500d0() {
    return &(*(int*)&DAT_004e69b0);
}


// 0x002500e0 FUN_002500e0 (33 B): matches/0x002500e0.cpp
// sym: ??0SeqEventWait_2500e0@fn_f0ad381b@@QAE@XZ
SeqEventWait_2500e0::SeqEventWait_2500e0() {
    ((owners::String_23fc40 *)&part)->FUN_0023fc40("($= $myvar true)", (hulk_intptr)2);
}

} // namespace fn_f0ad381b

// 0x00250110 audio::SeqEventWait::vfunc_0 (52 B): matches/0x00250110.cpp
// sym: ?vfunc_0@SeqEventNestTrack_250110@audio@@UAEHPAX@Z
// Same code shape as 0x0024e590 (propagated; names are from that function)
int audio::SeqEventNestTrack_250110::vfunc_0(void* param) {
    if ((unsigned char)::audio::SeqEvent::vfunc_0(param)) {
        if (FUN_0025bce0(param, (char*)this + 8))
            return 1;
    }
    return 0;
}

namespace fn_f0ad381b {

// 0x00250150 audio::SeqEventWait::vfunc_3 (6 B): matches/0x00250150.cpp
// sym: _FUN_00250150
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00250150() {
    return &(*(int*)&DAT_004e69b0);
}

} // namespace fn_f0ad381b

// 0x00250160 audio::SeqActionWait::vfunc_6 (162 B): equivalent/0x00250160.cpp
// sym: ?vfunc_6@SeqActionWait@audio@@UAEXH@Z
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 9/9)
// audio::SeqActionWait::vfunc_6 @ 0x00250160
void audio::SeqActionWait::vfunc_6(hulk_intptr __p0) { Ctx_250160 * ctx = (Ctx_250160 *)__p0;

    Str_250160 value;
    Str_250160 probe;
    switch (this->f_0c) {
    case 1:
    case 4:
        this->f_0c = 2;
        break;
    case 3: {
        value.FUN_0023fac0();
        FUN_002613b0(&ctx->mgr->table, &value, &(*(WaitData * *)&this->f_08)->name);
        bool same = ((Str_250160 *)((owners::String_23fc40 *)&probe)->FUN_0023fc40("t", (hulk_intptr)2))->FUN_00240310(&value);
        FUN_00240060(&probe);
        if (same)
            this->f_0c = 0;
        FUN_00240060(&value);
        break;
    }
    case 5:
        this->f_0c = 0;
        break;
    }
}


// 0x00250220 audio::SeqActionWait::vfunc_2 (10 B): matches/0x00250220.cpp
// sym: ?vfunc_2@SeqActionWait@audio@@UAEXHH@Z
// Same code shape as 0x0024ea60 (propagated; names are from that function)
void audio::SeqActionWait::vfunc_2(int , int ) {
    this->f_0c = 1;
}


// 0x00250230 audio::SeqActionWait::vfunc_1 (10 B): matches/0x00250230.cpp
// sym: ?vfunc_1@SeqActionWait@audio@@UAEXPAX@Z
 // namespace audio
void audio::SeqActionWait::vfunc_1(void* __p0) {
    this->f_0c = 3;
}


// 0x00250240 audio::SeqActionWait::vfunc_3 (10 B): matches/0x00250240.cpp
// sym: ?vfunc_3@SeqActionWait@audio@@UAEXH@Z
// Same code shape as 0x0024ea70 (propagated; names are from that function)
void audio::SeqActionWait::vfunc_3(hulk_intptr ) {
    *(int*)((char*)this + 0xc) = 4;
}


// 0x00250250 audio::SeqActionWait::vfunc_4 (10 B): matches/0x00250250.cpp
// sym: ?vfunc_4@SeqActionWait@audio@@UAEXH@Z
// Same code shape as 0x0024ea80 (propagated; names are from that function)
void audio::SeqActionWait::vfunc_4(int ) {
    *(int*)((char*)this + 0xc) = 5;
}


// 0x00250260 audio::SeqActionWait::vfunc_5 (6 B): matches/0x00250260.cpp
// sym: ?vfunc_5@SeqActionWait@audio@@UAEHH@Z
// Same code shape as 0x002514e0 (propagated; names are from that function)
int audio::SeqActionWait::vfunc_5(int ) {
    return this->f_0c;
}


// 0x00250290 FUN_00250290 (86 B): equivalent/0x00250290.cpp [wrapped: conflict: audio::SeqEventWaitType]
// sym: ?FUN_00250290@SeqEventWaitType@audio@fn_00250290@@QAEXXZ
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_00250290 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00250290 @ 0x00250290
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

typedef unsigned __int64 U64;

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void * __cdecl memcpy(void *, const void *, unsigned int);
#endif

struct WaitName {
    char data[12];
    WaitName *FUN_0023fc40(const char *, int);
    void FUN_00240060();
};
namespace audio {
struct SeqEventWaitType {
    virtual void unused();
    void FUN_002605e0(WaitName *, const U64 *, int, int);
    void FUN_00250290();
};
void SeqEventWaitType::FUN_00250290() {
    HULK_SIZE32(AudioSeqEventWait, 0x14);
    U64 id = FUN_002672f0("SeqEventWait", 0, 0);
    WaitName name;
    FUN_002605e0(name.FUN_0023fc40("Wait", 0), &id, (int)sizeof(AudioSeqEventWait), (int)__alignof(AudioSeqEventWait));
    name.FUN_00240060();
    SeqEventWaitType fresh;
    memcpy(this, &fresh, sizeof fresh);
}
}
} // namespace fn_00250290
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x002502f0 audio::SeqEventWaitType::vfunc_2 (30 B): matches/0x002502f0.cpp
// sym: ??_GSeqEventWaitType@audio@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
audio::SeqEventWaitType::~SeqEventWaitType() {}


// 0x00250310 audio::SeqEventWaitType::vfunc_3 (56 B): matches/0x00250310.cpp
// sym: ?vfunc_3@SeqEventWaitType@audio@@UAEPAXXZ
// Same code shape as 0x0024e6f0 (propagated; names are from that function)
// data: gName_250310 = DAT_00429b84, gPool_250310 = DAT_004e69b0
void* audio::SeqEventWaitType::vfunc_3() {
    NestTrack_250310* p = (NestTrack_250310*)FUN_00247530(((char*)&DAT_004e69b0));
    if (p) {
        p->init_0025fd00();
        p->vf = (hulk_uintptr)&hulk_at_00429b6c;
        ((owners::String_23fc40 *)&(p->name))->FUN_0023fc40(DAT_00429b84, (hulk_intptr)2);
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f0ad381b {

// 0x00250350 audio::SeqEventWait::vfunc_4 (45 B): matches/0x00250350.cpp
// sym: ?f4@SeqEventWait@fn_f0ad381b@@UAEPAV12@H@Z
SeqEventWait* SeqEventWait::f4(int flags) {
    ((owners::Str_240060 *)&sub)->FUN_00240060();
    Finish_0025fd10();
    if (flags & 1)
        FUN_00247550(((int*)&DAT_004e69b0), this);
    return this;
}

} // namespace fn_f0ad381b

// 0x00250380 audio::SeqEventWait::vfunc_1 (131 B): equivalent/0x00250380.cpp [wrapped: conflict: audio::SeqEvent; audio::SeqEventWait]
// sym: ?vfunc_1@SeqEventWait@audio@fn_00250380@@QAEHPAUWriter_250380@3@@Z
namespace fn_00250380 {
// STATUS: equivalent (tools/equiv.py level 3: 1600 inputs, branch coverage 10/10)
// audio::SeqEventWait::vfunc_1 @ 0x00250380
struct Stream {
    char pad00[0x24];
    int indent;
};

struct Writer_250380 {
    Stream *out;
};

char FUN_00246f50(Stream *s, const char *fmt, ...);
extern "C" char FUN_0024e600(Writer_250380 *w, const char *name, void *value);

namespace audio {

class SeqEvent {
public:
    virtual void v0();
    char vfunc_1_0025fd40(Writer_250380 *w);
    char pad04[4];
};

class SeqEventWait : public SeqEvent {
public:
    char field_08[4];
    int vfunc_1(Writer_250380 *w);
};

int SeqEventWait::vfunc_1(Writer_250380 *w)
{
    if (!SeqEvent::vfunc_1_0025fd40(w))
        return 0;
    if (!FUN_00246f50(w->out, "\n[\n"))
        return 0;
    w->out->indent++;
    if (!FUN_0024e600(w, "mExpression", &field_08))
        return 0;
    if (!FUN_00246f50(w->out, "\n"))
        return 0;
    w->out->indent--;
    if (!FUN_00246f50(w->out, "]\n"))
        return 0;
    return 1;
}

}
} // namespace fn_00250380


// 0x00250430 audio::SeqActionWait::vfunc_0 (36 B): matches/0x00250430.cpp [wrapped: conflict: audio::SeqAction; audio::SeqActionWait]
// sym: ?vfunc_0@SeqActionWait@audio@fn_00250430@@UAEPAV123@H@Z
namespace fn_00250430 {
// data: global_bss = DAT_004e6960

extern "C" char DAT_004298fc[];
namespace audio {
class SeqAction {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
};
class SeqActionWait : public SeqAction {
  public:
    virtual SeqActionWait* vfunc_0(int);
};
} // namespace audio
extern "C" void __cdecl FUN_00247550(void*, void*);
audio::SeqActionWait* audio::SeqActionWait::vfunc_0(int x) {
    SeqActionWait* p = this;
    *(void**)p = (void*)((hulk_intptr)DAT_004298fc);
    if (x & 1)
        FUN_00247550(((int*)((char*)&DAT_004e6960)), this);
    return this;
}
} // namespace fn_00250430


// 0x00250460 audio::SeqEventWait::vfunc_2 (66 B): matches/0x00250460.cpp
// sym: ?vfunc_2@SeqEventWait@audio@@UAEXH@Z
void audio::SeqEventWait::vfunc_2(hulk_intptr __p0) { Target * p = (Target *)__p0;

    audio::SeqActionWait_250460* a = (audio::SeqActionWait_250460*)alloc(&bss);
    p->set_0025dc20(a ? (a->audio::SeqActionWait_250460::SeqActionWait_250460(this), a) : 0);
}

