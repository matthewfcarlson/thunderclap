// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00253a90..0x00254620 (kind game, layer engine, confidence high), dominant class audio::SeqActionStream
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "gen/audio.h"
#define TREE_TU_BEGIN namespace fn_f902c78b {
#define TREE_TU_END }
namespace fn_f902c78b {} using namespace fn_f902c78b;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_f902c78b {
extern "C" void first(char*);
extern "C" __int64 second_002672f0(char*, int, int);
class Thing {
  public:
    __int64 value;
    Thing(char* s);
};
class SeqEvent_253c70 {
  public:
    bool vfunc_0_0025fd20(void*);
};
class Reader {
public:
    virtual void v0();
    virtual int v1();
    virtual int *v2();
    virtual void v3();
    virtual int v4();
    virtual void v5(int value);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
};
struct Owner_253cb0 {
    char pad00[0x84];
    int f84;
};
struct Stream {
    char pad00[0x34];
    void *source;          // 0x34
    Reader *reader;        // 0x38
    Owner_253cb0 *owner;          // 0x3c
    char pad40[0x5c - 0x40];
    unsigned char done;    // 0x5c
    void FUN_0025d480(int *pos);
};
extern "C" int FUN_0024b220(void *source);
char FUN_0024b200(void *source);
extern "C" Reader *FUN_0025cab0(int a, int b, int c, int d);
extern "C" void FUN_0025be60(int *pos, int *local);
extern "C" int FUN_0024c4d0(int *local, int v);
extern "C" int FUN_0024c480(int *local, int v);
extern "C" int FUN_0024c2f0(int *pos);
extern "C" hulk_uintptr FUN_0026fd80(hulk_uintptr a, unsigned int b);
extern "C" Reader *FUN_0025bec0(Reader *r);
extern "C" int FUN_0024ba70(void *source, Reader *reader, int amount);
class SeqActionStream_253cb0 {
public:
    char pad00[8];
    int f08;
    int f0c;
    int result;            // 0x10
    int f14;
    int f18;
    int state;             // 0x1c
    int f20;
    int pos;               // 0x24
    int f28;

    void FUN_00253cb0(Stream *s);
};
class SeqAction_253eb0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(int);
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
extern int FUN_0024afe0(int);
extern "C" void FUN_0024c160(int);
class SeqAction_253ef0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
class SeqAction_253f00 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual int f5();
    virtual void f6();
};
typedef unsigned int u32_253f10;
struct Sub_253f10 {
    char x[16];
    float v;
};
struct Ctx_253f10 {
    char x[20];
    float s;
    float* p;
};
struct Param {
    float f;
    Ctx_253f10* c;
    char x[44];
    u32_253f10 a;
    char y[4];
    Sub_253f10* b;
};
void __cdecl Sink_0024b040(u32_253f10, float);
struct Source { char pad0[0x1c]; float *value; float scale2; float scale1; };
struct Factor { char pad[0x14]; float value; };
struct Context { char pad0[4]; Source *source; char pad1[0x2c]; void *destination; char pad2[4]; Factor *factor; };
void __cdecl FUN_0024b080(void *, float);
struct Inner3c_253f70 {
    char pad0[0x90];
    char v90[0xc];
    char v9c[0xc];
    int fa8;
};
struct Pair_253f70 { int a; int b; };
struct Inner4 {
    char pad0[0x38];
    Pair_253f70 *p38;
};
struct Src_253f70 {
    char pad0[4];
    Inner4 *f4;
    char pad8[0x34 - 8];
    int f34;
    char pad38[4];
    Inner3c_253f70 *f3c;
};
void *FUN_0024b0c0(int a, int b);
extern "C" void FUN_0024cb50(void *h, void *v);
extern "C" void FUN_0024cb70(void *h, void *v);
extern "C" void FUN_0024c910(void *h, int a, int b);
extern "C" void FUN_0024c950(void *h, int v);
extern "C" char __cdecl output_00246f50(const char*, const char*, ...);
class Handler {
  public:
    char check_0025ce40(char**);
};
} // namespace fn_f902c78b
extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int) throw();
namespace fn_f902c78b {
struct FUN_00240060 {
    char data[12];
    FUN_00240060* FUN_0023fc40(const char*, int) throw();
    ~FUN_00240060() throw();
};
struct FUN_002605e0 {
    FUN_002605e0(FUN_00240060*, const __int64&, int, int) throw();
    virtual void foo();
};
struct SeqEventStreamType : FUN_002605e0 {
    SeqEventStreamType();
    virtual void foo();
};
class Helper_254160 {
  public:
    void Run_0025fd10();
};
struct Stm_254190 {
    char pad[0x24];
    int depth;
};
class SeqEvent {
  public:
    virtual void _m_vf0();
    virtual bool v1(Stm_254190**);
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual SeqEvent* f4(int);
    virtual void _m_vf5();
};
class SeqEventStream : public SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual SeqEventStream* f4(int);
};
extern void __cdecl FUN_00247550(void*, SeqEventStream*);
extern bool Match_00246f50(Stm_254190*, const char*, ...);
extern bool ReadTrack_00254000(Stm_254190**, const char*, void*);
class SeqEventStream_254190 : public SeqEvent {
    AudioSeqEventLink link;                 // records.h AudioSeqEventStream past the vftable
    AudioSeqStreamFile file;

  public:
    int vfunc_1(Stm_254190**);
};
extern void* hulk_at_004298fc[];
class SeqActionStream_254230 {
  public:
    void* vptr;
    SeqActionStream_254230* f0(unsigned char flags);
};
struct Voice_254260 {
    char pad0[0x10];
    float volume;           // 0x10
    float pitch;            // 0x14
};
struct Config_254260 {
    char pad0[0x14];
    float gain;             // 0x14
    float *volumeScale;     // 0x18
    float *pitchScale;      // 0x1c
    float pitchB;           // 0x20
    float pitchA;           // 0x24
};
struct Event_254260 {
    float scale;            // 0x0
    Config_254260 *config;         // 0x4
    char pad8[0x34 - 8];
    int handle;             // 0x34
    char pad38[4];
    Voice_254260 *voice;           // 0x3c
};
void __cdecl FUN_0024b040(int handle, float volume);
void __cdecl FUN_0024b080(int handle, float pitch);
extern "C" void __cdecl FUN_0024c120(int handle);
} // namespace fn_f902c78b
namespace audio {
class SeqAction_254260 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1(Event_254260 *e);
    char pad4[0x1c];
    int state;              // 0x20

    void FUN_00253f70(Event_254260 *e);
};
}
namespace audio {
struct SeqActionStream_nv_254260 {
    void FUN_00253f70(Event_254260 *e);
};
}
namespace fn_f902c78b {
extern "C" char DAT_0042a2b0[];
struct Sub_254520 {
    void Setup_00253a90(const char* s);
    char pad[8];
    u8 flags;
    char p2[3];
    unsigned int bits;
    unsigned int zero;
};
class Stream_254520 {
  public:
    hulk_intptr vf;
    void BaseInit_0025fd00();
    char pad[4];
    Sub_254520 sub;
};
extern "C" void* FUN_00247530(void*);


// 0x00253a90 FUN_00253a90 (72 B): matches/0x00253a90.cpp
// sym: ??0Thing@fn_f902c78b@@QAE@PAD@Z
Thing::Thing(char* s) {
    char buf[256];
    hulk_intptr offset = buf - s;
    char c;
    do {
        c = *s;
        s[offset] = c;
        ++s;
    } while (c);
    first(buf);
    value = second_002672f0(buf, 0, 0);
}

// 0x00253c30 audio::SeqEventStreamType::vfunc_0 (5 B): not yet verified
// 0x00253c40 audio::SeqEventStreamType::vfunc_1 (5 B): not yet verified

// 0x00253c50 FUN_00253c50 (6 B): matches/0x00253c50.cpp
// sym: _FUN_00253c50
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00253c50() {
    return &(*(int*)&DAT_004e7200);
}


// 0x00253c60 audio::SeqEventStream::vfunc_3 (6 B): matches/0x00253c60.cpp
// sym: _FUN_00253c60
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00253c60() {
    return &(*(int*)&DAT_004e7200);
}

} // namespace fn_f902c78b

// 0x00253c70 audio::SeqEventStream::vfunc_0 (48 B): matches/0x00253c70.cpp
// sym: ?vfunc_0@SeqEventStream@audio@@UAEHPAX@Z
// Same code shape as 0x00252fe0 (propagated; names are from that function)
int audio::SeqEventStream::vfunc_0(void* __p0) { void * p = (void *)__p0;

    if (((SeqEvent_253c70*)this)->vfunc_0_0025fd20(p)) {
        if (((PosHelper*)((char*)&this->f_08))->test(p))
            return 1;
    }
    return 0;
}

namespace fn_f902c78b {

// 0x00253cb0 FUN_00253cb0 (460 B): equivalent/0x00253cb0.cpp
// sym: ?FUN_00253cb0@SeqActionStream_253cb0@fn_f902c78b@@QAEXPAUStream@2@@Z @8e4d388643af @we08ae62f3155
// STATUS: equivalent (tools/equiv.py level 3: 20029 inputs, branch coverage 26/26)
// FUN_00253cb0 @ 0x00253cb0
void SeqActionStream_253cb0::FUN_00253cb0(Stream *s)
{
    if (s->done)
        return;

    if (state == 0) {
        bool create;
        if (s->source == 0)
            create = (f18 == 0);
        else if (s->reader != 0)
            create = false;
        else
            create = (FUN_0024b220(s->source) == 0);
        if (create) {
            Reader *r = FUN_0025cab0(s->owner->f84, f08 + 8, 0, 0);
            s->reader = r;
            r->v0();
            state = 1;
        }
    }
    if (state == 1) {
        s->reader->v11();
        int st = s->reader->v1();
        if (st == 1)
            return;
        if (st == 2) {
            pos = *s->reader->v2();
            f28 = s->reader->v4();
            state = 2;
        } else if (st == 3) {
            state = 4;
            s->reader->v12();
            s->reader = 0;
            f20 = 2;
            return;
        }
    }
    if (state != 2)
        return;

    int local;
    FUN_0025be60(&pos, &local);
    int base = FUN_0024c4d0(&local, f14);
    state = 2;
    if (s->source == 0)
        s->FUN_0025d480(&pos);
    if (s->source == 0) {
        state = 4;
        s->reader->v12();
        s->reader = 0;
        f20 = 2;
        return;
    }
    if (FUN_0024b200(s->source))
        return;
    int n = FUN_0024c480(&pos, base);
    hulk_intptr m = FUN_0026fd80(n, FUN_0024c2f0(&pos));
    s->reader->v5(m);
    s->reader = FUN_0025bec0(s->reader);
    int k = FUN_0024c4d0(&pos, f28) - base;
    result = FUN_0024ba70(s->source, s->reader, FUN_0024c480(&local, k));
    s->reader = 0;
    f0c = f14;
    state = 3;
}

} // namespace fn_f902c78b

// 0x00253e80 audio::SeqActionStream::vfunc_2 (43 B): matches/0x00253e80.cpp
// sym: ?vfunc_2@SeqActionStream@audio@@UAEXHH@Z
void audio::SeqActionStream::vfunc_2(int , int __p1) { char flag = (char)__p1;

    this->f_18 = 100;
    this->f_20 = 1;
    if (flag) {
        this->f_14 = 0;
        this->f_0c = -1;
        this->f_10 = -1;
    }
}


// 0x00253eb0 audio::SeqActionStream::vfunc_3 (49 B): matches/0x00253eb0.cpp
// sym: ?vfunc_3@SeqActionStream@audio@@UAEXH@Z
void audio::SeqActionStream::vfunc_3(hulk_intptr p) {
    int v = *(int*)((char*)p + 0x34);
    int x = FUN_0024afe0(v);
    if (x == 2) {
        v = *(int*)((char*)p + 0x34);
        FUN_0024c160(v);
    }
    this->f_20 = 4;
}


// 0x00253ef0 audio::SeqActionStream::vfunc_4 (10 B): matches/0x00253ef0.cpp
// sym: ?vfunc_4@SeqActionStream@audio@@UAEXH@Z
void audio::SeqActionStream::vfunc_4(int ) {
    *(int*)((char*)&this->f_20) = 5;
}


// 0x00253f00 audio::SeqActionStream::vfunc_5 (6 B): matches/0x00253f00.cpp
// sym: ?vfunc_5@SeqActionStream@audio@@UAEHH@Z
 // namespace audio
int audio::SeqActionStream::vfunc_5(int ) {
    return this->f_20;
}

namespace fn_f902c78b {

// 0x00253f10 FUN_00253f10 (42 B): matches/0x00253f10.cpp
// sym: ?Target@fn_f902c78b@@YGXPAUParam@1@@Z
void __stdcall Target(Param* p) {
    hulk_freg x = p->b->v;
    x = x * p->f;
    x = x * *p->c->p;
    x = x * p->c->s;
    Sink_0024b040(p->a, x);
}


// 0x00253f40 FUN_00253f40 (45 B): equivalent/0x00253f40.cpp
// sym: ?FUN_00253f40@fn_f902c78b@@YGXPAUContext@1@@Z @0df801628301 @w66afd4b6322b
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00253f40 @ 0x00253f40
void __stdcall FUN_00253f40(Context *context) { Source *source = context->source; float result = *source->value * context->factor->value * source->scale1 * source->scale2; FUN_0024b080(context->destination, result); }


// 0x00253f70 FUN_00253f70 (100 B): equivalent/0x00253f70.cpp
// sym: ?FUN_00253f70@fn_f902c78b@@YGXPAUSrc_253f70@1@@Z @74792c39aaed @w6e3af07ec93b
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00253f70 @ 0x00253f70
void __stdcall FUN_00253f70(Src_253f70 *s)
{
    void *h = FUN_0024b0c0(s->f34, 0);
    if (h) {
        FUN_0024cb50(h, (char *)s->f3c + 0x90);
        FUN_0024cb70(h, (char *)s->f3c + 0x9c);
        Pair_253f70 *p = s->f4->p38;
        FUN_0024c910(h, p->a, p->b);
        FUN_0024c950(h, s->f3c->fa8);
    }
}


// 0x00254000 FUN_00254000 (66 B): matches/0x00254000.cpp
// sym: ?work@fn_f902c78b@@YADPAPADPBDPAVHandler@1@@Z
// data: ending = DAT_00422518, fmt = DAT_004298a8
char work(char** text, const char* value, Handler* handler) {
    char* s = *text;
    if (output_00246f50(s, DAT_004298a8, value) && handler->check_0025ce40(text)) {
        s = *text;
        return output_00246f50(s, DAT_00422518);
    }
    return 0;
}


// 0x002540a0 FUN_002540a0 (86 B): matches/0x002540a0.cpp
// sym: ??0SeqEventStreamType@fn_f902c78b@@QAE@XZ
SeqEventStreamType::SeqEventStreamType() : FUN_002605e0(FUN_00240060().FUN_0023fc40("Stream", 0), FUN_002672f0("SeqEventStream", 0, 0), (int)sizeof(AudioSeqEventStream), (int)__alignof(AudioSeqEventStream)) { HULK_SIZE32(AudioSeqEventStream, 0x20); }

} // namespace fn_f902c78b

// 0x00254100 audio::SeqEventStreamType::vfunc_2 (30 B): matches/0x00254100.cpp
// sym: ??_GSeqEventStreamType@audio@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
audio::SeqEventStreamType::~SeqEventStreamType() {}


// 0x00254120 FUN_00254120 (62 B): equivalent/0x00254120.cpp [wrapped: conflict: audio::SeqEventStream]
// sym: ??0SeqEventStream@audio@fn_00254120@@QAE@XZ @570962d986b2 @w40cb7f43d58b
namespace fn_00254120 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00254120 @ 0x00254120
namespace audio {
struct FUN_0025fd00 {
    FUN_0025fd00();
    virtual void virtual0();
    char padding[4];
};
struct RsdFile {
    void FUN_00253a90(const char *name);
    char pad[8];
    unsigned char flags;
    char gap[3];
    unsigned int state;
    unsigned int field;
};
struct SeqEventStream : FUN_0025fd00 {
    RsdFile file;
    SeqEventStream();
    virtual void virtual0();
};
SeqEventStream::SeqEventStream() {
    file.FUN_00253a90("MyRsdFile");
    file.state &= 0x80000000u;
    file.flags &= 0xfe;
    file.field = 0;
}
}
} // namespace fn_00254120

namespace fn_f902c78b {

// 0x00254160 audio::SeqEventStream::vfunc_4 (35 B): matches/0x00254160.cpp
// sym: ?f4@SeqEventStream@fn_f902c78b@@UAEPAV12@H@Z
SeqEventStream* SeqEventStream::f4(int flag) {
    ((Helper_254160*)this)->Run_0025fd10();
    if (flag & 1)
        FUN_00247550((void*)((hulk_intptr)DAT_004e7200), this);
    return this;
}


// 0x00254190 audio::SeqEventStream::vfunc_1 (111 B): matches/0x00254190.cpp
// sym: ?vfunc_1@SeqEventStream_254190@fn_f902c78b@@QAEHPAPAUStm_254190@2@@Z
// data: sClose_0042a2c8 = DAT_0042a2c8, sName_0042a2cc = DAT_0042a2cc, sOpen = DAT_004298f4
int SeqEventStream_254190::vfunc_1(Stm_254190** p) {
    if (SeqEvent::v1(p)) {
        if (Match_00246f50(*p, DAT_004298f4)) {
            (*p)->depth++;
            if (ReadTrack_00254000(p, DAT_0042a2cc, &this->file)) {
                (*p)->depth--;
                Stm_254190* s = *p;
                if (Match_00246f50(s, DAT_0042a2c8))
                    return 1;
            }
        }
    }
    return 0;
}


// 0x00254230 audio::SeqActionStream::vfunc_0 (36 B): matches/0x00254230.cpp
// sym: ?f0@SeqActionStream_254230@fn_f902c78b@@QAEPAV12@E@Z
// data: g_pool_254230 = DAT_004e7268
SeqActionStream_254230* SeqActionStream_254230::f0(unsigned char flags) {
    vptr = hulk_at_004298fc;
    if (flags & 1)
        Free(((char*)((char*)&DAT_004e7268)), this);
    return this;
}

} // namespace fn_f902c78b

// 0x00254260 audio::SeqActionStream::vfunc_1 (148 B): equivalent/0x00254260.cpp
// sym: ?vfunc_1@SeqActionStream@audio@@UAEXPAX@Z @e54807662725 @w9f856d5ead9f
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// audio::SeqActionStream::vfunc_1 @ 0x00254260
void audio::SeqActionStream::vfunc_1(void* __p0) { Event_254260 * e = (Event_254260 *)__p0;

    if (e->handle == 0) {
        this->f_20 = 0;
        return;
    }
    int status = FUN_0024afe0(e->handle);
    if (status == 4 || status == 3) {
        Voice_254260 *v = e->voice;
        Config_254260 *c = e->config;
        FUN_0024b040(e->handle, (((v->volume * e->scale) * *c->volumeScale) * c->gain));
        c = e->config;
        FUN_0024b080(e->handle, (((*c->pitchScale * e->voice->pitch) * c->pitchA) * c->pitchB));
        ((SeqActionStream_nv_254260*)this)->FUN_00253f70(e);
        FUN_0024c120(e->handle);
    }
    this->f_20 = 3;
}


// 0x00254300 audio::SeqActionStream::vfunc_6 (524 B): equivalent/0x00254300.cpp [wrapped: conflict: Reader; Stream; audio::SeqActionStream]
// sym: ?vfunc_6@SeqActionStream@audio@fn_00254300@@UAEHPAUStream@3@@Z @ffe098ffdc97 @w3d7fac04784c
namespace fn_00254300 {
// STATUS: equivalent (tools/equiv.py level 3: 185 inputs, branch coverage 43/43)
// audio::SeqActionStream::vfunc_6 @ 0x00254300
class Reader {
public:
    virtual void v0();
    virtual int v1();
    virtual int *v2();
    virtual void v3();
    virtual int v4();
    virtual void v5(int value);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual int v12();
};

struct Source;

struct Track {
    char pad00[0x28];
    int *startPtr;          // 0x28
    float result;            // 0x2c
    unsigned int rate;       // 0x30
    int *endPtr;            // 0x34
};

struct Stream {
    char pad00[4];
    Track *track;            // 0x04
    char pad08[0x34 - 0x08];
    Source *source;          // 0x34
    Reader *reader;          // 0x38
    char pad3c[0x54 - 0x3c];
    signed char priority;    // 0x54
};

int FUN_0024afe0(Source *src);
extern "C" int FUN_0024c090(Source *src);
extern "C" int FUN_0024b0d0(Source *src);
extern "C" void FUN_0025be60(int *pos, int *local);
extern "C" int FUN_0024c4d0(int *local, int v);
extern "C" int FUN_0024c480(int *local, int v);
extern "C" float FUN_00261bb0(int a, int b, int c, int d, int e);

namespace audio {

class SeqActionStream {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual int vfunc_6(Stream *s);
    char pad04[4];
    int f08;
    int f0c;
    int f10;
    int f14;
    unsigned int minPriority;  // 0x18
    int state;                 // 0x1c
    int mode;                  // 0x20
    int pos;                   // 0x24
    int f28;

    int FUN_00253cb0(Stream *s);
    void FUN_00253f10(Stream *s);
    void FUN_00253f40(Stream *s);
    int FUN_00253f70(Stream *s);
};

}

int audio::SeqActionStream::vfunc_6(Stream *s)
{
    switch (mode) {
    case 1: {
        Stream *st = s;
        if ((unsigned int)(int)st->priority < minPriority)
            return st->priority;
        if (state != 3) {
            int rc = FUN_00253cb0(st);
            if (state != 3)
                return rc;
        }
        int r = FUN_0024afe0(st->source);
        if (r == 0) {
            return FUN_0024c090(st->source);
        }
        if (r > 1 && r <= 4)
            mode = 2;
        return r;
    }
    case 3: {
        Stream *st = s;
        int r = FUN_0024afe0(st->source);
        if (r == 0 || r == 5) {
            mode = 5;
            return 0;
        }
        if (r == 2) {
            int *x = (int *)&s;
            int base = FUN_0024b0d0(st->source);
            f14 = (f0c - f10) + base;
            FUN_0025be60(&pos, x);
            int p0 = FUN_0024c4d0(&pos, f28);
            int p1 = FUN_0024c4d0(x, f14);
            Track *t = st->track;
            int loc0 = *t->endPtr;
            unsigned int rate = t->rate;
            int loc1 = *t->startPtr;
            t->result = FUN_00261bb0(loc1, rate, p1, (unsigned int)*x >> 9 & 0x1ffff, loc0);
            int n = FUN_0024c480(x, p0);
            FUN_00253f10(st);
            FUN_00253f40(st);
            int rl = FUN_00253f70(st);
            if (f14 > n) {
                f14 = 0;
                mode = 0;
                return 0;
            }
            return rl;
        }
        return r - 5;
    }
    case 4: {
        Stream *st = s;
        int r = FUN_0024afe0(st->source);
        if (r == 0 || r == 4)
            mode = 2;
        return r;
    }
    case 5: {
        Stream *st = s;
        if (state != 0 && state != 3 && st->reader != 0) {
            st->reader->v11();
            int rr = st->reader->v1();
            if (rr == 1)
                return rr;
            int rv = st->reader->v12();
            st->reader = 0;
            state = 0;
            return rv;
        }
        int old = state;
        Source *src = st->source;
        int ra = old;
        if (src != 0)
            ra = FUN_0024afe0(src);
        if (src == 0 || ra == 0) {
            mode = 0;
            state = 0;
        }
        return ra;
    }
    default:
        return mode - 1;
    }
}
} // namespace fn_00254300


// 0x00254520 audio::SeqEventStreamType::vfunc_3 (85 B): matches/0x00254520.cpp
// sym: ?vfunc_3@SeqEventStreamType@audio@@UAEPAXXZ
// data: gPool_254520 = DAT_004e7200
void* audio::SeqEventStreamType::vfunc_3() {
    Stream_254520* p = (Stream_254520*)FUN_00247530(((int*)&DAT_004e7200));
    if (p) {
        p->BaseInit_0025fd00();
        Sub_254520* s = &p->sub;
        p->vf = ((hulk_intptr)DAT_0042a2b0);
        s->Setup_00253a90("MyRsdFile");
        s->flags &= 0xfe;
        s->bits &= 0x80000000;
        s->zero = 0;
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x00254580 audio::SeqEventStream::vfunc_2 (85 B): equivalent/0x00254580.cpp [wrapped: conflict: audio::SeqActionStream; audio::SeqEvent; audio::SeqEventStream]
// sym: ?vfunc_2@SeqEventStream@audio@fn_00254580@@UAEXPAX@Z @25028e2d2ccf @wc5ef14c25592
namespace fn_00254580 {
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 2/2)
// audio::SeqEventStream::vfunc_2 @ 0x00254580

extern "C" void* __cdecl FUN_00247530(void*);
namespace audio {
struct SeqEvent { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); };
struct SeqEventStream : SeqEvent { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(void*); virtual void vfunc_3(); virtual void vfunc_4(); };
struct SeqActionStream {
 virtual void* vfunc_0_00254230(char);
 char reserved[4];
 SeqEventStream* stream;
 int first;
 int second;
 int field14;
 char reserved18[4];
 int field1c;
 int field20;
 int field24;
 int field28;
};
}
struct ActionTarget { void FUN_0025dc20(audio::SeqActionStream*); };
void audio::SeqEventStream::vfunc_2(void* target) {
 audio::SeqActionStream* action = (audio::SeqActionStream*)FUN_00247530(((char*)((char*)&DAT_004e7268)));
 if (action) {
  action->audio::SeqActionStream::SeqActionStream();
  action->field14 = 0;
  action->field1c = 0;
  action->field20 = 0;
  action->field28 = 0;
  action->stream = this;
  action->first = -1;
  action->second = -1;
  action->field24 = 0;
 }
 ((ActionTarget*)target)->FUN_0025dc20(action);
}
} // namespace fn_00254580

