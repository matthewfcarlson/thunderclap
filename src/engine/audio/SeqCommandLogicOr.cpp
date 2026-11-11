// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00254e50..0x00255460 (kind game, layer engine, confidence high), dominant class audio::SeqCommandLogicOr
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "gen/audio.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fee5f112 {
#define TREE_TU_END }
namespace fn_fee5f112 {} using namespace fn_fee5f112;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_fee5f112 {
class SeqEvent_254e80 {
  public:
    bool vfunc_0(void*);
};
class SeqEventContainer_254e80 {
  public:
    bool vfunc_0(void*);
};
extern "C" bool FUN_0025ac10(void*, void*);
} // namespace fn_fee5f112
extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int) throw();
namespace fn_fee5f112 {
class FUN_00240060 {
    char pad[12];

  public:
    ~FUN_00240060() throw();
};
class FUN_002605e0 {
  public:
    FUN_002605e0(FUN_00240060*, const __int64&, int, int) throw();
    virtual void f();
};
class SeqEventLogicOrType_254f40 : public FUN_002605e0 {
  public:
    SeqEventLogicOrType_254f40() throw();
    virtual void g();
};
extern void* g_vftable_255060[];
class SeqCommandLogicOr_255060 {
  public:
    void* vptr;
    SeqCommandLogicOr_255060* f2(unsigned char flags);
};
extern "C" char DAT_0042a45c[];
class SeqEventContainer_2551b0 {
  public:
    SeqEventContainer_2551b0();
};
class SeqEventLogicOr : public SeqEventContainer_2551b0 {
  public:
    char pad[8];
    int b, c, d;
    float f;
    SeqEventLogicOr();
};
} // namespace fn_fee5f112
inline void* __cdecl operator new(size_t, void* ptr) { return ptr; }
namespace fn_fee5f112 {
void* __cdecl FUN_00247530(void*);
struct SeqCommandLogicOr_255210 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    char reserved[4];
    audio::SeqEventLogicOr* event;
};
struct Context_255210 {  };
struct RandomState_255250 { unsigned first, second; };
} // namespace fn_fee5f112
namespace audio {
struct Context_255250 { void FUN_0025dbd0(audio::SeqCommandLogicOr* command); };
}
namespace audio {
struct Link_255250 { Link_255250* next; };
}
namespace audio {
struct Command_255250 {
 virtual void slot0();
 virtual void slot1();
 virtual void execute(Context_255250* context);
 Link_255250 link;
};
}
namespace audio {
struct CommandList_255250 { char pad[8]; unsigned count; Link_255250* head; Link_255250* tail; float fraction; };
}
namespace audio {
struct SeqCommand_255250 { virtual void vfunc_0(Context_255250*); virtual void vfunc_1(); unsigned unknown; CommandList_255250* list; };
}
namespace fn_fee5f112 {
void* __cdecl Alloc(char*);
} // namespace fn_fee5f112
namespace audio {
class SeqEventBase {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    int pad;
    SeqEventBase();
};
}
namespace audio {
class SeqEventMid : public SeqEventBase {
  public:
    int a, b, c;
    SeqEventMid() : a(0), b(0), c(0) {}
};
}
namespace audio {
class SeqEventLogicOr_255350 : public SeqEventMid {
  public:
    float value;
    virtual void f0();
    SeqEventLogicOr_255350() : value(0.5f) {}
};
}

// 0x00254e50 audio::SeqEventLogicOrType::vfunc_0 (5 B): not yet verified
// 0x00254e60 audio::SeqEventLogicOrType::vfunc_1 (5 B): not yet verified
namespace fn_fee5f112 {

// 0x00254e70 FUN_00254e70 (6 B): matches/0x00254e70.cpp
// sym: _FUN_00254e70
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
// DAT_004e7458: a static om type (records.h)
extern "C" int* FUN_00254e70() {
    return &(*(int*)&DAT_004e7458);
}

} // namespace fn_fee5f112

// 0x00254e80 audio::SeqEventLogicOr::vfunc_0 (64 B): matches/0x00254e80.cpp
// sym: ?vfunc_0@SeqEventLogicOr@audio@@UAEHPAX@Z
int audio::SeqEventLogicOr::vfunc_0(void* __p0) { void * arg = (void *)__p0;

    if (((SeqEvent_254e80*)this)->vfunc_0(arg) && FUN_0025ac10(arg, (char*)this + 0x14) &&
        ((SeqEventContainer_254e80*)this)->vfunc_0(arg))
        return 1;
    return 0;
}

namespace fn_fee5f112 {

// 0x00254ec0 audio::SeqEventLogicOr::vfunc_3 (6 B): matches/0x00254ec0.cpp
// sym: _FUN_00254ec0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
// DAT_004e7458: a static om type (records.h)
extern "C" int* FUN_00254ec0() {
    return &(*(int*)&DAT_004e7458);
}


// 0x00254f40 FUN_00254f40 (86 B): matches/0x00254f40.cpp
// sym: ??0SeqEventLogicOrType_254f40@fn_fee5f112@@QAE@XZ
SeqEventLogicOrType_254f40::SeqEventLogicOrType_254f40() throw()
    : FUN_002605e0(((FUN_00240060 *)((owners::String_23fc40 *)&(FUN_00240060()))->FUN_0023fc40(((char*)&DAT_00426608), (hulk_intptr)0)), FUN_002672f0("SeqEventLogicOr", 0, 0), (int)sizeof(AudioSeqEventLogicOr), (int)__alignof(AudioSeqEventLogicOr)) { HULK_SIZE32(AudioSeqEventLogicOr, 0x18); }

} // namespace fn_fee5f112

// 0x00254fa0 audio::SeqEventLogicOrType::vfunc_2 (30 B): matches/0x00254fa0.cpp
// sym: ??_GSeqEventLogicOrType@audio@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
audio::SeqEventLogicOrType::~SeqEventLogicOrType() {}


// 0x00254fc0 audio::SeqEventLogicOr::vfunc_1 (119 B): equivalent/0x00254fc0.cpp [wrapped: conflict: audio::SeqEvent; audio::SeqEventContainer; audio::SeqEventLogicOr]
// sym: ?vfunc_1@SeqEventLogicOr@audio@fn_00254fc0@@UAEDPAUArchive_254fc0@3@@Z
namespace fn_00254fc0 {
// STATUS: equivalent (tools/equiv.py level 3: 1186 inputs, branch coverage 10/10)
// audio::SeqEventLogicOr::vfunc_1 @ 0x00254fc0
struct Writer_254fc0 {
    char pad0[0x24];
    int indent;
};

struct Archive_254fc0 {
    Writer_254fc0 *writer;
};

struct Spread {
    char data[4];
};

char FUN_00246f50(Writer_254fc0 *writer, const char *fmt, ...);
extern "C" char FUN_00252470(Archive_254fc0 *ar, const char *name, Spread *value);

namespace audio {

class SeqEvent {
public:
    virtual char vfunc_0(Archive_254fc0 *ar);
    virtual char vfunc_1(Archive_254fc0 *ar);
    virtual char vfunc_2(Archive_254fc0 *ar);
    virtual char vfunc_3(Archive_254fc0 *ar);
    virtual char vfunc_4(Archive_254fc0 *ar);
    char pad04[0x10];
};

class SeqEventContainer {
public:
    char vfunc_1(Archive_254fc0 *ar);
};

class SeqEventLogicOr : public SeqEvent {
public:
    virtual char vfunc_1(Archive_254fc0 *ar);
    Spread spread;
};

char SeqEventLogicOr::vfunc_1(Archive_254fc0 *ar)
{
    if (!SeqEvent::vfunc_1(ar))
        return 0;
    if (!FUN_00246f50(ar->writer, "\n[\n"))
        return 0;
    ar->writer->indent++;
    if (!FUN_00252470(ar, "mSpread", &spread))
        return 0;
    if (!((SeqEventContainer *)this)->vfunc_1(ar))
        return 0;
    ar->writer->indent--;
    if (!FUN_00246f50(ar->writer, "]\n"))
        return 0;
    return 1;
}

}
} // namespace fn_00254fc0

namespace fn_fee5f112 {

// 0x00255060 audio::SeqCommandLogicOr::vfunc_1 (36 B): matches/0x00255060.cpp
// sym: ?f2@SeqCommandLogicOr_255060@fn_fee5f112@@QAEPAV12@E@Z
// data: g_bss = DAT_004e7410
SeqCommandLogicOr_255060* SeqCommandLogicOr_255060::f2(unsigned char flags) {
    vptr = g_vftable_255060;

    if (flags & 1)
        Free(((char*)&DAT_004e7410), this);
    return this;
}


// 0x002551b0 FUN_002551b0 (36 B): matches/0x002551b0.cpp
// sym: ??0SeqEventLogicOr@fn_fee5f112@@QAE@XZ
SeqEventLogicOr::SeqEventLogicOr() {
    b = 0;
    c = 0;
    d = 0;
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0042a45c);
    f = 0.5f;
}

} // namespace fn_fee5f112

// 0x002551e0 audio::SeqEventLogicOr::vfunc_4 (35 B): matches/0x002551e0.cpp [wrapped: conflict: SeqEventLogicOr]
// sym: ?v4@SeqEventLogicOr@fn_002551e0@@UAEPAV12@H@Z
namespace fn_002551e0 {

class SeqEventContainer {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    void Init();
};
class SeqEventLogicOr : public SeqEventContainer {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual SeqEventLogicOr* v4(int);
};
extern void __cdecl FUN_00247550(void*, SeqEventLogicOr*);
SeqEventLogicOr* SeqEventLogicOr::v4(int flags) {
    Init();
    if (flags & 1)
        FUN_00247550(((char*)((char*)&DAT_004e7458)), this);
    return this;
}
} // namespace fn_002551e0


// 0x00255210 audio::SeqEventLogicOr::vfunc_2 (59 B): equivalent/0x00255210.cpp
// sym: ?vfunc_2@SeqEventLogicOr@audio@@UAEXH@Z
// STATUS: equivalent (tools/equiv.py level 3: 19941 inputs, branch coverage 2/2)
// audio::SeqEventLogicOr::vfunc_2 @ 0x00255210
void audio::SeqEventLogicOr::vfunc_2(hulk_intptr __p0) { Context_255210 * context = (Context_255210 *)__p0;

    SeqCommandLogicOr_255210* command = (SeqCommandLogicOr_255210*)FUN_00247530(((char*)&DAT_004e7410));
    if (command) {
        new(command) SeqCommandLogicOr_255210;
        command->event = this;
    }
    ((owners::Queue_25dba0 *)context)->FUN_0025dba0((int *)(SeqCommandLogicOr_255210 *)command);
}


// 0x00255250 audio::SeqCommandLogicOr::vfunc_0 (254 B): equivalent/0x00255250.cpp
// sym: ?vfunc_0@SeqCommandLogicOr@audio@@UAEXH@Z
// STATUS: equivalent (tools/equiv.py level 3: 18813 inputs, branch coverage 18/18)
// audio::SeqCommandLogicOr::vfunc_0 @ 0x00255250
void audio::SeqCommandLogicOr::vfunc_0(int __p0) { Context_255250 * context = (Context_255250 *)__p0;

 CommandList_255250* l = (*(CommandList_255250 * *)&this->f_08);
 if (l->count != 0) {
  unsigned range = (unsigned)(int)(__int64)((double)(int)(__int64)l->count * (double)l->fraction);
  if (!range) range = 1;
  RandomState_255250* r = (*(RandomState_255250**)&DAT_004e5acc);
  r->first = 36969u * (r->first & 65535u) + (r->first >> 16);
  r->second = 18000u * (r->second & 65535u) + (r->second >> 16);
  unsigned index = ((r->first << 16) + (r->second & 65535u)) % range;
  l = (*(CommandList_255250 * *)&this->f_08);
  Link_255250* selected = l->head;
  while (index--) selected = selected->next;
  Command_255250* command = reinterpret_cast<Command_255250*>(reinterpret_cast<char*>(selected) - 4);
  Link_255250* prev = 0;
  Link_255250* cur = l->head;
  while (cur != selected) { prev = cur; cur = cur->next; }
  if (prev) prev->next = selected->next; else l->head = selected->next;
  if (!selected->next) l->tail = prev;
  --l->count;
  l = (*(CommandList_255250 * *)&this->f_08);
  selected->next = 0;
  if (l->tail) l->tail->next = selected; else l->head = selected;
  l->tail = selected;
  ++l->count;
  context->FUN_0025dbd0(this);
  command->execute(context);
 } else context->FUN_0025dbd0(this);
}


// 0x00255350 audio::SeqEventLogicOrType::vfunc_3 (69 B): matches/0x00255350.cpp
// sym: ?vfunc_3@SeqEventLogicOrType@audio@@UAEPAXXZ
// data: bss = DAT_004e7458
 // namespace audio
void* audio::SeqEventLogicOrType::vfunc_3() {
    void* p = Alloc(((char*)((char*)&DAT_004e7458)));
    return (void*)(p ? new (p) SeqEventLogicOr_255350 : 0);
}

