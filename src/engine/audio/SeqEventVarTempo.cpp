// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00252b30..0x00252f90 (kind game, layer engine, confidence high), dominant class audio::SeqEventVarTempo
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "gen/audio.h"
#define TREE_TU_BEGIN namespace fn_f0c0637a {
#define TREE_TU_END }
namespace fn_f0c0637a {} using namespace fn_f0c0637a;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_f0c0637a {
class SeqEvent_252b90 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
class SeqEventB {
  public:
    virtual bool vfunc_0(void*);
};
class TempoCheck {
  public:
    bool check_00261a80(void*);
};
extern "C" bool __cdecl FUN_0025ac10(void*, void*);
class SeqAction_252c30 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
class SeqAction_252c60 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
class SeqAction_252c70 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(int);
    virtual void f5();
    virtual void f6();
};
extern "C" char __cdecl parse_00246f50(const char*, const char*, ...);
extern "C" char __cdecl parse2_00246f50(const char*, const char*, ...);
class Reader {
  public:
    char consume_00261c20(char**);
};
class FUN_00240060 {
  public:
    FUN_00240060* FUN_0023fc40(const char*, int) throw();
    ~FUN_00240060() throw();
    char pad[12];
};
class FUN_002605e0 {
  public:
    virtual void f();
    FUN_002605e0(FUN_00240060*, const __int64&, int, int) throw();
};
class SeqEventVarTempoType_252d00 : public FUN_002605e0 {
  public:
    virtual void f();
    SeqEventVarTempoType_252d00();
};
} // namespace fn_f0c0637a
extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int);
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f0c0637a {
extern "C" void* __cdecl FUN_00247530(void*);
} // namespace fn_f0c0637a
namespace audio {
struct SeqEventVarTempo_252d80 {
    virtual int vfunc_0_00252b90(void*);
    virtual int vfunc_1_00252df0(void*);
    virtual void vfunc_2_00252ed0(void*);
    virtual void vfunc_3();
    int field4;
    int field8;
    int fieldc;
    float tempo;
    void FUN_0025fd00();
};
}
namespace fn_f0c0637a {
class SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual SeqEvent* f4(int);
    virtual void f5();
    void setup_0025fd10();
};
class SeqEventVarTempo : public SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual SeqEventVarTempo* f4(int);
};
extern void FUN_00247550(const char*, SeqEventVarTempo*);
extern void* hulk_at_004298fc[];
class SeqActionVarTempo_252ea0 {
  public:
    void* vptr;
    SeqActionVarTempo_252ea0* f0(unsigned char flags);
};

// 0x00252b30 audio::SeqEventVarTempoType::vfunc_0 (5 B): not yet verified
// 0x00252b40 audio::SeqEventVarTempoType::vfunc_1 (5 B): not yet verified

// 0x00252b50 FUN_00252b50 (6 B): matches/0x00252b50.cpp
// sym: _FUN_00252b50
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00252b50() {
    return &(*(int*)&DAT_004e6f88);
}

} // namespace fn_f0c0637a

// 0x00252b60 FUN_00252b60 (36 B): matches/0x00252b60.cpp [wrapped: conflict: audio::SeqEvent; audio::SeqEventVarTempo]
// sym: ??0SeqEventVarTempo@audio@fn_00252b60@@QAE@XZ
namespace fn_00252b60 {
extern "C" void _ReadWriteBarrier();
namespace audio {
class SeqEvent {
  public:
    SeqEvent();
    virtual void f();
    char pad[4];
};
class SeqEventVarTempo : public SeqEvent {
  public:
    SeqEventVarTempo();
    virtual void f();
    int a;
    int b;
    float tempo;
};
SeqEventVarTempo::SeqEventVarTempo() : SeqEvent(), a(4), b(4), tempo(120.0f) {
    _ReadWriteBarrier();
}
} // namespace audio
} // namespace fn_00252b60


// 0x00252b90 audio::SeqEventVarTempo::vfunc_0 (65 B): matches/0x00252b90.cpp
// sym: ?vfunc_0@SeqEventVarTempo@audio@@UAEHPAX@Z
int audio::SeqEventVarTempo::vfunc_0(void* __p0) { void * p = (void *)__p0;

    if (((SeqEventB*)this)->SeqEventB::vfunc_0(p) && ((TempoCheck*)((char*)this + 8))->check_00261a80(p) &&
        FUN_0025ac10(p, (char*)this + 0x10))
        return 1;
    return 0;
}

namespace fn_f0c0637a {

// 0x00252be0 audio::SeqEventVarTempo::vfunc_3 (6 B): matches/0x00252be0.cpp
// sym: _FUN_00252be0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00252be0() {
    return &(*(int*)&DAT_004e6f88);
}

} // namespace fn_f0c0637a

// 0x00252bf0 audio::SeqActionVarTempo::vfunc_6 (34 B): matches/0x00252bf0.cpp
// sym: ?vfunc_6@SeqActionVarTempo@audio@@UAEXH@Z
// Same code shape as 0x0024ea30 (propagated; names are from that function)
void audio::SeqActionVarTempo::vfunc_6(hulk_intptr ) {
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


// 0x00252c20 audio::SeqActionVarTempo::vfunc_2 (10 B): matches/0x00252c20.cpp
// sym: ?vfunc_2@SeqActionVarTempo@audio@@UAEXHH@Z
// Same code shape as 0x0024ea60 (propagated; names are from that function)
void audio::SeqActionVarTempo::vfunc_2(int , int ) {
    this->f_0c = 1;
}


// 0x00252c30 audio::SeqActionVarTempo::vfunc_1 (40 B): matches/0x00252c30.cpp
// sym: ?vfunc_1@SeqActionVarTempo@audio@@UAEXPAX@Z
void audio::SeqActionVarTempo::vfunc_1(void* __p0) { void * param = (void *)__p0;

    *(int*)(*(hulk_intptr*)((char*)param + 4) + 0x28) = this->f_08 + 0x10;
    *(int*)(*(hulk_intptr*)((char*)param + 4) + 0x30) = this->f_08 + 8;
    this->f_0c = 0;
}


// 0x00252c60 audio::SeqActionVarTempo::vfunc_3 (10 B): matches/0x00252c60.cpp
// sym: ?vfunc_3@SeqActionVarTempo@audio@@UAEXH@Z
// Same code shape as 0x0024ea70 (propagated; names are from that function)
void audio::SeqActionVarTempo::vfunc_3(hulk_intptr ) {
    *(int*)((char*)&this->f_0c) = 4;
}


// 0x00252c70 audio::SeqActionVarTempo::vfunc_4 (10 B): matches/0x00252c70.cpp
// sym: ?vfunc_4@SeqActionVarTempo@audio@@UAEXH@Z
// Same code shape as 0x0024ea80 (propagated; names are from that function)
void audio::SeqActionVarTempo::vfunc_4(int ) {
    *(int*)((char*)&this->f_0c) = 5;
}


// 0x00252c80 audio::SeqActionVarTempo::vfunc_5 (6 B): matches/0x00252c80.cpp
// sym: ?vfunc_5@SeqActionVarTempo@audio@@UAEHH@Z
// Same code shape as 0x002514e0 (propagated; names are from that function)
int audio::SeqActionVarTempo::vfunc_5(int ) {
    return this->f_0c;
}

namespace fn_f0c0637a {

// 0x00252c90 FUN_00252c90 (66 B): matches/0x00252c90.cpp
// sym: _FUN_00252c90
extern "C" char FUN_00252c90(char** s, char* p, void * r) {
    char* value = *s;
    if (parse_00246f50(value, "%s ", p) && ((Reader *)r)->consume_00261c20(s)) {
        value = *s;
        return parse2_00246f50(value, "\n");
    }
    return 0;
}


// 0x00252d00 FUN_00252d00 (86 B): matches/0x00252d00.cpp
// sym: ??0SeqEventVarTempoType_252d00@fn_f0c0637a@@QAE@XZ
SeqEventVarTempoType_252d00::SeqEventVarTempoType_252d00()
    : FUN_002605e0(FUN_00240060().FUN_0023fc40("4/4", 0), FUN_002672f0("SeqEventVarTempo", 0, 0), (int)sizeof(AudioSeqEventVarTempo), (int)__alignof(AudioSeqEventVarTempo)) { HULK_SIZE32(AudioSeqEventVarTempo, 0x14); }

} // namespace fn_f0c0637a

// 0x00252d60 audio::SeqEventVarTempoType::vfunc_2 (30 B): matches/0x00252d60.cpp
// sym: ??_GSeqEventVarTempoType@audio@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
audio::SeqEventVarTempoType::~SeqEventVarTempoType() {}


// 0x00252d80 audio::SeqEventVarTempoType::vfunc_3 (59 B): equivalent/0x00252d80.cpp
// sym: ?vfunc_3@SeqEventVarTempoType@audio@@UAEPAXXZ @c1a26a6681f0 @w215a0e0068d3
// STATUS: equivalent (tools/equiv.py level 3: 19941 inputs, branch coverage 2/2)
// audio::SeqEventVarTempoType::vfunc_3 @ 0x00252d80
void* audio::SeqEventVarTempoType::vfunc_3() {
    void* memory = FUN_00247530(((char*)&DAT_004e6f88));
    if (!memory) return (void*)(0);
    ((SeqEventVarTempo_252d80*)memory)->FUN_0025fd00();
    SeqEventVarTempo_252d80* event = new(memory) SeqEventVarTempo_252d80;
    event->field8 = 4;
    event->fieldc = 4;
    event->tempo = 120.0f;
    return (void*)(event);
}

namespace fn_f0c0637a {

// 0x00252dc0 audio::SeqEventVarTempo::vfunc_4 (35 B): matches/0x00252dc0.cpp
// sym: ?f4@SeqEventVarTempo@fn_f0c0637a@@UAEPAV12@H@Z
SeqEventVarTempo* SeqEventVarTempo::f4(int flags) {
    SeqEvent::setup_0025fd10();
    if (flags & 1)
        FUN_00247550(((char*)&DAT_004e6f88), this);
    return this;
}

} // namespace fn_f0c0637a

// 0x00252df0 audio::SeqEventVarTempo::vfunc_1 (129 B): equivalent/0x00252df0.cpp [wrapped: conflict: audio::SeqEvent; audio::SeqEventVarTempo]
// sym: ?vfunc_1@SeqEventVarTempo@audio@fn_00252df0@@QAEHPAUWriter_252df0@3@@Z @ede2080b92ad @w706c3e9c50d2
namespace fn_00252df0 {
// STATUS: equivalent (tools/equiv.py level 3: 1534 inputs, branch coverage 10/10)
// audio::SeqEventVarTempo::vfunc_1 @ 0x00252df0
// 0x00252df0: audio::SeqEventVarTempo::vfunc_1: write the event (base fields, then two named values) to a text stream
struct Stream {
    char pad00[0x24];
    int indent;
};

struct Writer_252df0 {
    Stream* out;
};

char FUN_00246f50(Stream* s, const char* fmt, ...);
extern "C++" __declspec(nothrow) char __cdecl FUN_00252c90(char **, char *, void *);
extern "C" char FUN_00252470(Writer_252df0* w, const char* name, void* value);

namespace audio {

class SeqEvent {
public:
    virtual void v0();
    char vfunc_1_0025fd40(Writer_252df0* w);
    char pad04[4];
};

class SeqEventVarTempo : public SeqEvent {
public:
    char field_08[4];
    char field_0c[4];
    char field_10[4];
    int vfunc_1(Writer_252df0* w);
};

int SeqEventVarTempo::vfunc_1(Writer_252df0* w)
{
    if (!SeqEvent::vfunc_1_0025fd40(w))
        return 0;
    if (!FUN_00246f50(w->out, "\n[\n"))
        return 0;
    w->out->indent++;
    if (!FUN_00252c90((char **)(Writer_252df0 *)w, (char *)(const char *)"mTimeSignature", &field_08))
        return 0;
    if (!FUN_00252470(w, "mTempo", &field_10))
        return 0;
    w->out->indent--;
    if (!FUN_00246f50(w->out, "]\n"))
        return 0;
    return 1;
}

}
} // namespace fn_00252df0

namespace fn_f0c0637a {

// 0x00252ea0 audio::SeqActionVarTempo::vfunc_0 (36 B): matches/0x00252ea0.cpp
// sym: ?f0@SeqActionVarTempo_252ea0@fn_f0c0637a@@QAEPAV12@E@Z
// data: g_pool_252ea0 = DAT_004e6f40
SeqActionVarTempo_252ea0* SeqActionVarTempo_252ea0::f0(unsigned char flags) {
    vptr = hulk_at_004298fc;
    if (flags & 1)
        Free(((char*)((char*)&DAT_004e6f40)), this);
    return this;
}

} // namespace fn_f0c0637a

// 0x00252ed0 audio::SeqEventVarTempo::vfunc_2 (66 B): equivalent/0x00252ed0.cpp [wrapped: conflict: audio::SeqActionVarTempo; audio::SeqEvent; audio::SeqEventVarTempo]
// sym: ?vfunc_2@SeqEventVarTempo@audio@fn_00252ed0@@UAEXPAX@Z @c3be45bf9e6a @w0f2fecb2ca9f
namespace fn_00252ed0 {
// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 2/2)
// audio::SeqEventVarTempo::vfunc_2 @ 0x00252ed0

namespace audio {
struct SeqEvent { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(void*); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); };
struct SeqActionVarTempo { virtual void vfunc_0(); char pad[4]; SeqEvent* event; int value; };
struct SeqEventVarTempo : SeqEvent { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(void*); virtual void vfunc_3(); virtual void vfunc_4(); };
}
extern char DAT_0042a090;
extern "C" void* __cdecl FUN_00247530(void*);
struct Receiver { void FUN_0025dc20(audio::SeqActionVarTempo*); };
void audio::SeqEventVarTempo::vfunc_2(void* receiver) {
    audio::SeqActionVarTempo* action = (audio::SeqActionVarTempo*)FUN_00247530(((char*)((char*)&DAT_004e6f40)));
    if (action) {
        *(void**)action = &DAT_0042a090;
        action->event = this;
        action->value = 0;
    }
    ((Receiver*)receiver)->FUN_0025dc20(action);
}
} // namespace fn_00252ed0

