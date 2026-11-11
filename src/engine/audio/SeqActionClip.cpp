// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00255d00..0x00256660 (kind game, layer engine, confidence high), dominant class audio::SeqActionClip
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "gen/audio.h"
#define TREE_TU_BEGIN namespace fn_f91a83dc {
#define TREE_TU_END }
namespace fn_f91a83dc {} using namespace fn_f91a83dc;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_f91a83dc {
class SeqEvent {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad[4];
};
extern "C" bool __cdecl FUN_0025aa80(void*, void*);
class Sub_255d30 {
  public:
    bool run(void*);
};
class SeqEventClip : public SeqEvent {
  public:
    virtual int vfunc_0(void*);
};
class SeqAction_255dc0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void vfunc_3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
extern "C" int __cdecl FUN_00259c50(int);
extern "C" void __cdecl FUN_00258e50(int);
class SeqAction_255df0 {
  public:
    virtual void x();
    char pad[0x10];
};
class SeqAction_255e20 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual unsigned int f5();
    virtual void f6();
};
struct Result_255e60 {};
class SeqActionClip_255e60 {
  public:
    char pad[0x14];
    int field;
    void Run(void*);
};
extern "C" Result_255e60* __cdecl FUN_00258cb0(int, int);
extern "C" void __cdecl FUN_0024cb50(Result_255e60*, int*);
extern "C" void __cdecl FUN_0024cb70(Result_255e60*, int*);
extern "C" void __cdecl FUN_0024c910(Result_255e60*, int, int);
extern "C" void __cdecl FUN_0024c950(Result_255e60*, int);
struct Pair_255ed0 {
    unsigned int bits;
    int value;
};
struct Source_255ed0 {
    char pad0[0x28];
    int handle;
};
struct Context {
    char pad0[0x28];
    int *wordPtr;       // +0x28
    float result;       // +0x2c
    int param;          // +0x30
    char pad34[0];
};
struct Context2_255ed0 {
    char pad0[0x28];
    int *wordPtr;       // +0x28
    float result;       // +0x2c
    int param;          // +0x30
    int *constPtr;      // +0x34
};
struct Binding_255ed0 {
    char pad0[4];
    Context2_255ed0 *context;
};
int __cdecl FUN_0025d060(int handle);
extern "C" void __cdecl FUN_0025be60(int key, Pair_255ed0 *out);
extern "C" int __cdecl FUN_00258f00(int id);
extern "C" int __cdecl FUN_0024c4d0(Pair_255ed0 *pair, int id);
extern "C" float __cdecl FUN_00261bb0(int word, int param, int a, unsigned int bits, int constant);
class SeqActionClip_255ed0 {
public:
    void FUN_00255ed0(Binding_255ed0 *binding);

    char pad0[0xc];
    int id;             // +0x0c
    Source_255ed0 *source;     // +0x10
    int sourceId;       // +0x14
};
struct Pair_256150 {
    float value;
    int index;
};
struct Entry_256150 {
    float f[4];
    int index;
};
struct Frame_256150 {
    Pair_256150 pairs[16];
    Entry_256150 entries[14];
    char tail[0x28];
};
extern "C" int __cdecl FUN_00258b70(int handle);
extern "C" int __cdecl FUN_0024c2d0(int v);
extern "C" void __cdecl FUN_00258bf0(int handle, Pair_256150 *pairs, int count);
extern "C" void __cdecl FUN_00258ba0(int handle, Entry_256150 *entries, int count);
extern "C" void __cdecl FUN_00258b80(int handle, float v);
struct Info_256150 {
    char pad0[0x14];
    float scale;
    float *factor;
    char pad1c[0x3c - 0x1c];
    float *weights;
    float *vectors;
};
struct Extra_256150 {
    char pad0[0x10];
    float amount;
};
struct Arg_256150 {
    float base;
    Info_256150 *info;
    char pad08[0x3c - 8];
    Extra_256150 *extra;
};
class SeqActionClip_256150 {
public:
    char pad0[0x14];
    int handle;
    void FUN_00256150(Arg_256150 *arg);
};
extern "C" void* __cdecl alloc(void*);
class Part {
  public:
    char pad[8];
    unsigned char flags;
    char pad2[3];
    unsigned int bits;
    int extra;
    void init(const char*);
    Part(unsigned char* flag) {
        *flag = 0;
        init("MyRsdFile");
        flags &= 0xfe;
        bits &= 0x80000000;
        extra = 0;
    }
};
class Base_2562c0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    char pad[4];
    Base_2562c0();
};
class Clip_2562c0 : public Base_2562c0 {
  public:
    unsigned char flag;
    char pad[7];
    Part part;
    Clip_2562c0() : Base_2562c0(), part(&flag) {}
};
struct Source_256370 {
    char pad0[0x1c];
    float* level;           // 0x1c
    float x20;              // 0x20
    float x24;              // 0x24
};
struct Scale_256370 {
    char pad0[0x14];
    float k;                // 0x14
};
struct Event_256370 {
    int f00;
    Source_256370* source;         // 0x04
    char pad08[0x3c - 8];
    Scale_256370* scale;           // 0x3c
};
struct Target_256370 {
    char pad0[8];
    unsigned char b8;       // 0x08
};
struct Voice;
void __cdecl FUN_00258c80(Voice* v, float gain);
extern "C" void __cdecl FUN_00258b40(Voice* v, int flag);
extern "C" void __cdecl FUN_00259be0(Voice* v);
} // namespace fn_f91a83dc
namespace audio {
class SeqActionClip_256370 : public ::audio::SeqAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1(Event_256370* e);
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    char pad04[4];
    Target_256370* target;         // 0x08
    char pad0c[4];
    void* clip;             // 0x10
    Voice* voice;           // 0x14
    int state;              // 0x18
    void FUN_00256150(Event_256370* e);
    void FUN_00255e60(Event_256370* e);
};
}

// 0x00255d00 audio::SeqEventClipType::vfunc_0 (5 B): not yet verified
// 0x00255d10 audio::SeqEventClipType::vfunc_1 (5 B): not yet verified
namespace fn_f91a83dc {

// 0x00255d20 FUN_00255d20 (6 B): matches/0x00255d20.cpp
// sym: _FUN_00255d20
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00255d20() {
    return &(*(int*)&DAT_004e75b8);
}


// 0x00255d30 audio::SeqEventClip::vfunc_0 (65 B): matches/0x00255d30.cpp
// sym: ?vfunc_0@SeqEventClip@fn_f91a83dc@@UAEHPAX@Z
int SeqEventClip::vfunc_0(void* param) {
    if ((char)SeqEvent::vfunc_0(param)) {
        if (FUN_0025aa80(param, (char*)this + 8)) {
            if (((Sub_255d30*)((char*)this + 0x10))->run(param)) {
                return 1;
            }
        }
    }
    return 0;
}


// 0x00255d80 audio::SeqEventClip::vfunc_3 (6 B): matches/0x00255d80.cpp
// sym: _FUN_00255d80
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00255d80() {
    return &(*(int*)&DAT_004e75b8);
}

} // namespace fn_f91a83dc

// 0x00255da0 audio::SeqActionClip::vfunc_2 (25 B): matches/0x00255da0.cpp
// sym: ?vfunc_2@SeqActionClip@audio@@UAEXHH@Z
 // namespace audio
void audio::SeqActionClip::vfunc_2(int , int __p1) { unsigned char flag = (unsigned char)__p1;

    this->f_18 = 1;
    if (flag)
        this->f_0c = 0;
}


// 0x00255dc0 audio::SeqActionClip::vfunc_3 (47 B): matches/0x00255dc0.cpp
// sym: ?vfunc_3@SeqActionClip@audio@@UAEXH@Z
void audio::SeqActionClip::vfunc_3(hulk_intptr arg) {
    int x = this->f_14;
    if (x != 0 && FUN_00259c50(x) == 1)
        FUN_00258e50(this->f_14);
    this->f_18 = 4;
}


// 0x00255df0 audio::SeqActionClip::vfunc_4 (47 B): matches/0x00255df0.cpp
// sym: ?vfunc_4@SeqActionClip@audio@@UAEXH@Z
void audio::SeqActionClip::vfunc_4(int ) {
    if (this->f_14 != 0) {
        if (FUN_00259c50(this->f_14) == 1)
            FUN_00258e50(this->f_14);
    }
    this->f_18 = 5;
}


// 0x00255e20 audio::SeqActionClip::vfunc_5 (6 B): matches/0x00255e20.cpp
// sym: ?vfunc_5@SeqActionClip@audio@@UAEHH@Z
// Same code shape as 0x00254730 (propagated; names are from that function)
 // namespace audio
int audio::SeqActionClip::vfunc_5(int ) {
    return (int)((*(unsigned int *)&this->f_18));
}

namespace fn_f91a83dc {

// 0x00255e60 FUN_00255e60 (101 B): matches/0x00255e60.cpp
// sym: ?Run@SeqActionClip_255e60@fn_f91a83dc@@QAEXPAX@Z
void SeqActionClip_255e60::Run(void* data) {
    Result_255e60* r = FUN_00258cb0(field, 0);
    if (!r)
        return;
    FUN_0024cb50(r, (int*)(*(char**)((char*)data + 0x3c) + 0x90));
    FUN_0024cb70(r, (int*)(*(char**)((char*)data + 0x3c) + 0x9c));
    int* p = *(int**)((char*)data + 4);
    int* q = *(int**)((char*)p + 0x38);
    FUN_0024c910(r, q[0], q[1]);
    FUN_0024c950(r, *(int*)(*(char**)((char*)data + 0x3c) + 0xa8));
}


// 0x00255ed0 FUN_00255ed0 (124 B): equivalent/0x00255ed0.cpp
// sym: ?FUN_00255ed0@SeqActionClip_255ed0@fn_f91a83dc@@QAEXPAUBinding_255ed0@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 2455 inputs, branch coverage 0/0)
// FUN_00255ed0 @ 0x00255ed0
void SeqActionClip_255ed0::FUN_00255ed0(Binding_255ed0 *binding) {
    Pair_255ed0 pair;
    FUN_0025be60(FUN_0025d060(source->handle), &pair);
    id = FUN_00258f00(sourceId);
    int a = FUN_0024c4d0(&pair, id);
    Context2_255ed0 *ctx = binding->context;
    int constant = *ctx->constPtr;
    int word = *ctx->wordPtr;
    ctx->result = FUN_00261bb0(word, ctx->param, a, (pair.bits >> 9) & 0x1ffff, constant);
}

} // namespace fn_f91a83dc

// 0x00255f70 FUN_00255f70 (86 B): matches/0x00255f70.cpp [wrapped: conflict: audio::SeqEventClipType]
// sym: ?FUN_00255f70@SeqEventClipType@audio@fn_00255f70@@QAEPAU123@XZ
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_00255f70 {
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
struct SeqEventClipType {
    void** vtable;
    void FUN_002605e0(Field*, __int64*, int, int);
    SeqEventClipType* FUN_00255f70();
};
} // namespace audio
extern void* DAT_0042a584[];
audio::SeqEventClipType* audio::SeqEventClipType::FUN_00255f70() {
    HULK_SIZE32(AudioSeqEventClip, 0x28);
    __int64 id = FUN_002672f0("SeqEventClip", 0, 0);
    Field field;
    FUN_002605e0(field.FUN_0023fc40("Clip", 0), &id, (int)sizeof(AudioSeqEventClip), (int)__alignof(AudioSeqEventClip));
    field.FUN_00240060();
    vtable = DAT_0042a584;
    return this;
}
} // namespace fn_00255f70
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00255fd0 audio::SeqEventClipType::vfunc_2 (30 B): matches/0x00255fd0.cpp
// sym: ??_GSeqEventClipType@audio@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
audio::SeqEventClipType::~SeqEventClipType() {}


// 0x00255ff0 FUN_00255ff0 (66 B): equivalent/0x00255ff0.cpp [wrapped: conflict: audio::SeqEventClip]
// sym: ??0SeqEventClip@audio@fn_00255ff0@@QAE@XZ
namespace fn_00255ff0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00255ff0 @ 0x00255ff0
struct ClipData {
    char pad[8];
    unsigned char flags;
    char gap[3];
    unsigned int value;
    unsigned int next;
    void FUN_00253a90(const char *name);
};
struct FUN_0025fd00 {
    virtual void slot0();
    char pad[4];
    unsigned char enabled;
    char gap[7];
    ClipData data;
    FUN_0025fd00();
};
namespace audio {
struct SeqEventClip : FUN_0025fd00 {
    virtual void slot0();
    SeqEventClip();
};
}
audio::SeqEventClip::SeqEventClip() {
    enabled = 0;
    data.FUN_00253a90("MyRsdFile");
    data.value &= 0x80000000u;
    data.flags &= 0xfe;
    data.next = 0;
}
} // namespace fn_00255ff0


// 0x00256040 audio::SeqEventClip::vfunc_4 (35 B): matches/0x00256040.cpp [wrapped: conflict: SeqEventClip]
// sym: ?f4@SeqEventClip@fn_00256040@@UAEPAV12@H@Z
namespace fn_00256040 {

class SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};
class SeqEventClip : public SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual SeqEventClip* f4(int);
    void helper();
};
extern void FUN_00247550(void*, SeqEventClip*);
SeqEventClip* SeqEventClip::f4(int arg) {
    helper();
    if (arg & 1)
        FUN_00247550(((int*)&DAT_004e75b8), this);
    return this;
}
} // namespace fn_00256040


// 0x00256070 audio::SeqEventClip::vfunc_1 (129 B): equivalent/0x00256070.cpp [wrapped: conflict: audio::SeqEvent; audio::SeqEventClip]
// sym: ?vfunc_1@SeqEventClip@audio@fn_00256070@@QAEHPAUWriter_256070@3@@Z
namespace fn_00256070 {
// STATUS: equivalent (tools/equiv.py level 3: 1534 inputs, branch coverage 10/10)
// audio::SeqEventClip::vfunc_1 @ 0x00256070
// 0x00256070: audio::SeqEventClip::vfunc_1: write the event (base fields, then two named values) to a text stream
struct Stream {
    char pad00[0x24];
    int indent;
};

struct Writer_256070 {
    Stream* out;
};

char FUN_00246f50(Stream* s, const char* fmt, ...);
char FUN_00250ef0(Writer_256070* w, const char* name, void* value);
extern "C" char FUN_00254000(Writer_256070* w, const char* name, void* value);

namespace audio {

class SeqEvent {
public:
    virtual void v0();
    char vfunc_1(Writer_256070* w);
    char pad04[4];
};

class SeqEventClip : public SeqEvent {
public:
    char field_08[4];
    char field_0c[4];
    char field_10[4];
    int vfunc_1(Writer_256070* w);
};

int SeqEventClip::vfunc_1(Writer_256070* w)
{
    if (!SeqEvent::vfunc_1(w))
        return 0;
    if (!FUN_00246f50(w->out, "\n[\n"))
        return 0;
    w->out->indent++;
    if (!FUN_00250ef0(w, "mIsLooping", &field_08))
        return 0;
    if (!FUN_00254000(w, "mRsdFile", &field_10))
        return 0;
    w->out->indent--;
    if (!FUN_00246f50(w->out, "]\n"))
        return 0;
    return 1;
}

}
} // namespace fn_00256070


// 0x00256120 audio::SeqActionClip::vfunc_0 (36 B): matches/0x00256120.cpp [wrapped: conflict: audio::SeqActionClip]
// sym: ?vfunc_0@SeqActionClip@audio@fn_00256120@@QAEPAV123@H@Z
namespace fn_00256120 {

extern "C" char DAT_004298fc[];
namespace audio {
class SeqActionClip {
  public:
    hulk_ulongptr vt;
    SeqActionClip* vfunc_0(int);
};
} // namespace audio
extern "C" void __cdecl FUN_00247550(void*, void*);
audio::SeqActionClip* audio::SeqActionClip::vfunc_0(int f) {
    SeqActionClip* p = this;
    vt = ((hulk_intptr)DAT_004298fc);
    if (f & 1)
        FUN_00247550((void*)((hulk_intptr)((char*)((char*)&DAT_004e7570))), p);
    return p;
}
} // namespace fn_00256120

namespace fn_f91a83dc {

// 0x00256150 FUN_00256150 (362 B): equivalent/0x00256150.cpp
// sym: ?FUN_00256150@SeqActionClip_256150@fn_f91a83dc@@QAEXPAUArg_256150@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 292 inputs, branch coverage 16/16)
// FUN_00256150 @ 0x00256150
void SeqActionClip_256150::FUN_00256150(Arg_256150 *arg)
{
    Frame_256150 f;
    int count = FUN_0024c2d0(FUN_0025d060(FUN_00258b70(handle)));
    float *weights = arg->info->weights;
    if (weights != 0) {
        for (unsigned int i = 0; i < (unsigned int)count; i++) {
            f.pairs[i].index = i;
            f.pairs[i].value = weights[i] * f.pairs[i].value;
        }
        FUN_00258bf0(handle, f.pairs, count);
    }
    float *vectors = arg->info->vectors;
    if (vectors != 0) {
        for (unsigned int j = 0; j < (unsigned int)count; j++) {
            f.entries[j].index = j;
            f.entries[j].f[0] = vectors[j * 4 + 0];
            f.entries[j].f[1] = vectors[j * 4 + 1];
            f.entries[j].f[2] = vectors[j * 4 + 2];
            f.entries[j].f[3] = vectors[j * 4 + 3];
        }
        FUN_00258ba0(handle, f.entries, count);
    }
    FUN_00258b80(handle, arg->extra->amount * arg->base * *arg->info->factor * arg->info->scale);
}

} // namespace fn_f91a83dc

// 0x002562c0 audio::SeqEventClipType::vfunc_3 (89 B): matches/0x002562c0.cpp
// sym: ?vfunc_3@SeqEventClipType@audio@@UAEPAXXZ
// data: pool_2562c0 = DAT_004e75b8
void* audio::SeqEventClipType::vfunc_3() {
    void* p = alloc(((char*)&DAT_004e75b8));
    if (p) {
        Clip_2562c0* q = (Clip_2562c0*)p;
        q->Clip_2562c0::Clip_2562c0();
        return (void*)(q);
    }
    return (void*)(0);
}


// 0x00256320 audio::SeqEventClip::vfunc_2 (73 B): matches/0x00256320.cpp [wrapped: conflict: audio::SeqActionClip; audio::SeqEvent; audio::SeqEventClip]
// sym: ?vfunc_2@SeqEventClip@audio@fn_00256320@@UAEXPAX@Z
namespace fn_00256320 {
// data: bss = DAT_004e7570

namespace audio {
class SeqEvent {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*);
};
class SeqEventClip : public SeqEvent {
  public:
    virtual void vfunc_2(void*);
};
class BaseAction {
  public:
    virtual void act();
    char pad[4];
    SeqEventClip* owner;
    int a, b, c, d;
    BaseAction() : a(0), b(0), c(0), d(0) {}
};
class SeqActionClip : public BaseAction {
  public:
    virtual void act();
    SeqActionClip(SeqEventClip* p) { owner = p; }
};
class Target {
  public:
    void set(SeqActionClip*);
};
} // namespace audio
extern "C" void* FUN_00247530(void*);
inline audio::SeqActionClip* create(audio::SeqEventClip* p) {
    audio::SeqActionClip* a = (audio::SeqActionClip*)FUN_00247530(((char*)((char*)&DAT_004e7570)));
    if (a) {
        a->audio::SeqActionClip::SeqActionClip(p);
        return a;
    }
    return 0;
}
void audio::SeqEventClip::vfunc_2(void* p) {
    ((audio::Target*)p)->set(create(this));
}
} // namespace fn_00256320


// 0x00256370 audio::SeqActionClip::vfunc_1 (125 B): equivalent/0x00256370.cpp
// sym: ?vfunc_1@SeqActionClip_256370@audio@@UAEXPAUEvent_256370@fn_f91a83dc@@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// audio::SeqActionClip::vfunc_1 @ 0x00256370
void audio::SeqActionClip_256370::vfunc_1(Event_256370* e)
{
    if (clip == 0 || voice == 0) {
        state = 5;
        return;
    }
    FUN_00256150(e);
    FUN_00258c80(voice, ((*e->source->level * e->scale->k) * e->source->x20) * e->source->x24);
    FUN_00255e60(e);
    FUN_00258b40(voice, target->b8);
    FUN_00259be0(voice);
    state = 3;
}


// 0x00256420 audio::SeqActionClip::vfunc_6 (430 B): equivalent/0x00256420.cpp [wrapped: conflict: content::LoadInventory::DynamicCaster; content::LoadInventory::DynamicCasterBase]
// sym: ?vfunc_6@SeqActionClip@fn_00256420@@UAEHPAUCtx_256420@2@@Z
inline void *operator new(size_t, void *p) throw() { return p; }
namespace fn_00256420 {
// STATUS: equivalent (tools/equiv.py level 3: 125 inputs, branch coverage 29/29)
// audio::SeqActionClip::vfunc_6 @ 0x00256420


namespace audio { class Clip; }

namespace content {
namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void *p) = 0;
};

template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void *p);
};
}
}

struct ClipRef_256420 {
    char pad0[0x10];
    unsigned int idLo;
    unsigned int idHi;
};

struct Clip {
    char pad0[0x22];
    unsigned short refs;
    char pad24[4];
    void *source;
};

class ClipLookup_256420 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Clip *lookup(content::LoadInventory::DynamicCasterBase *caster, unsigned __int64 id);
};

struct Env_256420 {
    char pad0[0x14];
    float scale;
    char pad18[0x88 - 0x18];
    ClipLookup_256420 *clips;
    char pad8c[0xb4 - 0x8c];
    unsigned char flags;
};

struct Voice_256420 {
    char pad0[0x1c];
    float *volume;
    float gain;
    float pan;
    char pad28[0x44 - 0x28];
    unsigned int *params;
};

struct Ctx_256420 {
    char pad0[4];
    Voice_256420 *voice;
    char pad8[0x3c - 8];
    Env_256420 *env;
    char *ownerLink;
};

class SeqActionClip;

unsigned int *__cdecl FUN_0025d060(void *source);
extern "C" void __cdecl FUN_0025c320(unsigned int *p, unsigned int *out, int bit0, int bit1);
extern "C" int __cdecl FUN_00259610(unsigned int *params, int one, void *source);
extern "C" void __cdecl FUN_00258ea0(int handle, int arg);
extern "C" int __cdecl FUN_00259c50(int handle);
extern "C" void __cdecl FUN_00259b40(int handle);
void __cdecl FUN_00258c80(int handle, float v);

union Flag_256420 {
    char b;
    int w;
};

struct Frame_256420 {
    char pad0[4];
    int saved;                  // 0x10
    Flag_256420 bit1;                  // 0x14
    Flag_256420 bit0;                  // 0x18
    int caster;                 // 0x1c, holds a DynamicCaster
    unsigned int buf[63];       // 0x20
};

class SeqActionClip {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual int vfunc_6(Ctx_256420 *ctx);
    char pad04[4];
    ClipRef_256420 *ref;       // 0x08
    int f0c;
    Clip *clip;         // 0x10
    int handle;         // 0x14
    int state;          // 0x18
    void FUN_00256150(Ctx_256420 *ctx);
    void FUN_00255e60(Ctx_256420 *ctx);
    void FUN_00255ed0(Ctx_256420 *ctx);
};

int SeqActionClip::vfunc_6(Ctx_256420 *ctx)
{
    Frame_256420 fr;
    do {
        fr.saved = state;
        switch (state) {
        case 1: {
            char *link = ctx->ownerLink;
            SeqActionClip *owner = link ? (SeqActionClip *)(link - 4) : 0;
            if (owner == this) {
                content::LoadInventory::DynamicCaster<audio::Clip> *caster =
                    new (&fr.caster) content::LoadInventory::DynamicCaster<audio::Clip>();
                unsigned __int64 id = ((unsigned __int64)ref->idHi << 32) | ref->idLo;
                clip = ctx->env->clips->lookup(caster, id);
                if (clip) {
                    clip->refs++;
                    unsigned int *params = ctx->voice->params;
                    if (params == 0) {
                        unsigned char flags = ctx->env->flags;
                        fr.bit1.b = (flags >> 1) & 1;
                        fr.bit0.b = flags & 1;
                        params = fr.buf;
                        FUN_0025c320(FUN_0025d060(clip->source), params, fr.bit0.w, fr.bit1.w);
                    }
                    handle = FUN_00259610(params, 1, clip->source);
                    FUN_00258ea0(handle, f0c);
                }
                state = 2;
            }
            break;
        }
        case 3:
            if (handle != 0 && FUN_00259c50(handle) != 0) {
                FUN_00256150(ctx);
                Voice_256420 *v = ctx->voice;
                Env_256420 *e = ctx->env;
                FUN_00258c80(handle, *v->volume * e->scale * v->gain * v->pan);
                FUN_00255e60(ctx);
                FUN_00255ed0(ctx);
            } else {
                state = 5;
            }
            break;
        case 4:
            if (handle == 0 || FUN_00259c50(handle) == 0)
                state = 2;
            break;
        case 5:
            if (handle != 0) {
                if (FUN_00259c50(handle) != 0)
                    break;
                FUN_00259b40(handle);
                Clip *c = clip;
                handle = 0;
                c->refs--;
                clip = 0;
            }
            state = 0;
            break;
        }
    } while (fr.saved != state);
    return state;
}
} // namespace fn_00256420

