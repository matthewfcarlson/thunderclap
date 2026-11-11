// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0024f7f0..0x0024fbe0 (kind game, layer engine, confidence high), dominant class audio::SeqEventChannelSends
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "gen/audio.h"
#define TREE_TU_BEGIN namespace fn_f2b964a3 {
#define TREE_TU_END }
namespace fn_f2b964a3 {} using namespace fn_f2b964a3;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_f2b964a3 {
typedef unsigned int u32_24f870;
struct Arg_24f870 {
    char pad[0x3c];
    u32_24f870 value;
};
struct Result_24f870 {
    char pad[0x44];
    hulk_uintptr link;
};
extern "C" Result_24f870* __cdecl FUN_0024a940(u32_24f870, void*);
class SeqAction_24f8b0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
class SeqAction_24f8c0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(int);
    virtual void f5();
    virtual void f6();
};
} // namespace fn_f2b964a3
extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int) throw();
namespace fn_f2b964a3 {
class FUN_00240060 {
  public:
    FUN_00240060* FUN_0023fc40(const char*, int) throw();
    ~FUN_00240060() throw();
    char pad[12];
};
class FUN_002605e0 {
  public:
    FUN_002605e0(FUN_00240060*, const __int64&, int, int) throw();
    virtual void v0();
};
class SeqEventChannelSendsType_24f950 : public FUN_002605e0 {
  public:
    SeqEventChannelSendsType_24f950();
    virtual void v0();
};
typedef unsigned int u32_24f9d0;
extern "C" u32_24f9d0 __cdecl FUN_002673a0(const char*, int);
extern u32_24f9d0 hulk_at_00429a60;
class SeqEventChannelSends_24f9d0 {
  public:
    void Ctor_0025fd00();
};
class SeqEventChannelSends {
  public:
    u32_24f9d0* vt;
    u32_24f9d0 pad;
    u32_24f9d0 values[64];
    u32_24f9d0 result;
    SeqEventChannelSends();
};
extern "C" void* __cdecl Alloc(void*);
extern "C" int __cdecl Lookup(const char*, int);
} // namespace fn_f2b964a3
namespace audio {
class SeqEventType_24fa90 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void* vfunc_3();
    SeqEventType_24fa90();
};
}
namespace audio {
class SeqEventChannelSends_24fa90 : public SeqEventType_24fa90 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void* vfunc_3();
    char pad[4];
    int data[64];
    int member;
    SeqEventChannelSends_24fa90() : SeqEventType_24fa90() {
        member = Lookup("this", 0);
        for (int i = 0; i < 64; ++i)
            data[i] = 0;
    }
};
}
namespace audio {
struct SeqActionChannelSends_24fb80 {
    virtual void* vfunc_0_0024fa60(int);
    virtual void vfunc_1_0024f870(void*);
    char pad[4];
    void *event;
    int value;
    SeqActionChannelSends_24fb80(void *e) : event(e), value(0) {}
};
}
namespace fn_f2b964a3 {
extern "C" void * __cdecl FUN_00247530(void *);
struct Channel_24fb80 { void FUN_0025dc20(audio::SeqActionChannelSends_24fb80 *); };

// 0x0024f7f0 audio::SeqEventChannelSendsType::vfunc_0 (5 B): not yet verified
// 0x0024f800 audio::SeqEventChannelSendsType::vfunc_1 (5 B): not yet verified

// 0x0024f810 FUN_0024f810 (6 B): matches/0x0024f810.cpp
// sym: _FUN_0024f810
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
// DAT_004e6848: a static om type (records.h)
extern "C" int* FUN_0024f810() {
    return &(*(int*)&DAT_004e6848);
}


// 0x0024f820 audio::SeqEventChannelSends::vfunc_3 (6 B): matches/0x0024f820.cpp
// sym: _FUN_0024f820
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
// DAT_004e6848: a static om type (records.h)
extern "C" int* FUN_0024f820() {
    return &(*(int*)&DAT_004e6848);
}

} // namespace fn_f2b964a3

// 0x0024f830 audio::SeqActionChannelSends::vfunc_6 (34 B): matches/0x0024f830.cpp
// sym: ?vfunc_6@SeqActionChannelSends@audio@@UAEXH@Z
// Same code shape as 0x0024ea30 (propagated; names are from that function)
void audio::SeqActionChannelSends::vfunc_6(hulk_intptr ) {
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


// 0x0024f860 audio::SeqActionChannelSends::vfunc_2 (10 B): matches/0x0024f860.cpp
// sym: ?vfunc_2@SeqActionChannelSends@audio@@UAEXHH@Z
// Same code shape as 0x0024ea60 (propagated; names are from that function)
void audio::SeqActionChannelSends::vfunc_2(int , int ) {
    this->f_0c = 1;
}


// 0x0024f870 audio::SeqActionChannelSends::vfunc_1 (49 B): matches/0x0024f870.cpp
// sym: ?vfunc_1@SeqActionChannelSends@audio@@UAEXPAX@Z
void audio::SeqActionChannelSends::vfunc_1(void* __p0) { Arg_24f870 * arg = (Arg_24f870 *)__p0;

    u32_24f870 val = arg->value;
    Result_24f870* r = FUN_0024a940(val, (char*)(*(void * *)&this->f_08) + 0x108);
    r->link = (hulk_uintptr)((char*)(*(void * *)&this->f_08) + 8);
    (*(u32_24f870 *)&this->f_0c) = 0;
}


// 0x0024f8b0 audio::SeqActionChannelSends::vfunc_3 (10 B): matches/0x0024f8b0.cpp
// sym: ?vfunc_3@SeqActionChannelSends@audio@@UAEXH@Z
// Same code shape as 0x0024ea70 (propagated; names are from that function)
void audio::SeqActionChannelSends::vfunc_3(hulk_intptr ) {
    *(int*)((char*)this + 0xc) = 4;
}


// 0x0024f8c0 audio::SeqActionChannelSends::vfunc_4 (10 B): matches/0x0024f8c0.cpp
// sym: ?vfunc_4@SeqActionChannelSends@audio@@UAEXH@Z
// Same code shape as 0x0024ea80 (propagated; names are from that function)
void audio::SeqActionChannelSends::vfunc_4(int ) {
    *(int*)((char*)this + 0xc) = 5;
}


// 0x0024f8d0 audio::SeqActionChannelSends::vfunc_5 (6 B): matches/0x0024f8d0.cpp
// sym: ?vfunc_5@SeqActionChannelSends@audio@@UAEHH@Z
// Same code shape as 0x002514e0 (propagated; names are from that function)
int audio::SeqActionChannelSends::vfunc_5(int ) {
    return this->f_0c;
}

namespace fn_f2b964a3 {

// 0x0024f950 FUN_0024f950 (89 B): matches/0x0024f950.cpp
// sym: ??0SeqEventChannelSendsType_24f950@fn_f2b964a3@@QAE@XZ
SeqEventChannelSendsType_24f950::SeqEventChannelSendsType_24f950()
    : FUN_002605e0(FUN_00240060().FUN_0023fc40("ChSends", 0), FUN_002672f0("SeqEventChannelSends", 0, 0), (int)sizeof(AudioSeqEventChannelSends), (int)__alignof(AudioSeqEventChannelSends)) { HULK_SIZE32(AudioSeqEventChannelSends, 0x10c); }

} // namespace fn_f2b964a3

// 0x0024f9b0 audio::SeqEventChannelSendsType::vfunc_2 (30 B): matches/0x0024f9b0.cpp
// sym: ??_GSeqEventChannelSendsType@audio@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
audio::SeqEventChannelSendsType::~SeqEventChannelSendsType() {}

namespace fn_f2b964a3 {

// 0x0024f9d0 FUN_0024f9d0 (53 B): matches/0x0024f9d0.cpp
// sym: ??0SeqEventChannelSends@fn_f2b964a3@@QAE@XZ
SeqEventChannelSends::SeqEventChannelSends() {
    ((SeqEventChannelSends_24f9d0*)this)->Ctor_0025fd00();
    vt = &hulk_at_00429a60;
    result = FUN_002673a0("this", 0);
    for (int i = 0; i < 64; ++i)
        values[i] = 0;
}

} // namespace fn_f2b964a3

// 0x0024fa10 audio::SeqEventChannelSends::vfunc_4 (35 B): matches/0x0024fa10.cpp [wrapped: conflict: SeqEventChannelSends]
// sym: ?v4@SeqEventChannelSends@fn_0024fa10@@UAEPAV12@H@Z
namespace fn_0024fa10 {
// data: g_bss = DAT_004e6848

class SeqEvent {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    void helper_0025fd10();
};
class SeqEventChannelSends : public SeqEvent {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual SeqEventChannelSends* v4(int);
};
extern "C" void __cdecl FUN_00247550(void*, void*);
SeqEventChannelSends* SeqEventChannelSends::v4(int a) {
    helper_0025fd10();
    if (a & 1)
        FUN_00247550(((char*)((char*)&DAT_004e6848)), this);
    return this;
}
} // namespace fn_0024fa10


// 0x0024fa60 audio::SeqActionChannelSends::vfunc_0 (36 B): matches/0x0024fa60.cpp [wrapped: conflict: audio::SeqAction; audio::SeqActionChannelSends]
// sym: ?vfunc_0@SeqActionChannelSends@audio@fn_0024fa60@@UAEPAV123@H@Z
namespace fn_0024fa60 {
// data: gData_24fa60 = DAT_004e6800

namespace audio {
class SeqAction {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
};
extern void Init_00247550(void*, void*);
extern int hulk_at_004298fc;
class SeqActionChannelSends : public SeqAction {
  public:
    virtual SeqActionChannelSends* vfunc_0(int);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
};
} // namespace audio
audio::SeqActionChannelSends* audio::SeqActionChannelSends::vfunc_0(int x) {
    *(hulk_ulongptr*)this = (hulk_ulongptr)&hulk_at_004298fc;
    if (x & 1)
        Init_00247550(((char*)&DAT_004e6800), this);
    return this;
}
} // namespace fn_0024fa60


// 0x0024fa90 audio::SeqEventChannelSendsType::vfunc_3 (76 B): matches/0x0024fa90.cpp
// sym: ?vfunc_3@SeqEventChannelSendsType@audio@@UAEPAXXZ
// data: bss = DAT_004e6848
 // namespace audio
void* audio::SeqEventChannelSendsType::vfunc_3() {
    SeqEventChannelSends_24fa90* p = (SeqEventChannelSends_24fa90*)Alloc(((int*)((char*)&DAT_004e6848)));
    if (p) {
        p->SeqEventChannelSends_24fa90::SeqEventChannelSends_24fa90();
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x0024fae0 audio::SeqEventChannelSends::vfunc_1 (71 B): equivalent/0x0024fae0.cpp [wrapped: conflict: audio::SeqEvent; audio::SeqEventChannelSends]
// sym: ?vfunc_1@SeqEventChannelSends@audio@fn_0024fae0@@UAEEPAPAX@Z @27da0594fbfc @w9d80ac4f1747
namespace fn_0024fae0 {
// STATUS: equivalent (tools/equiv.py level 3: 2823 inputs, branch coverage 4/4)
// audio::SeqEventChannelSends::vfunc_1 @ 0x0024fae0
namespace audio { struct SeqEvent { virtual void vfunc_0(); virtual unsigned char vfunc_1(void **); }; struct SeqEventChannelSends : SeqEvent { unsigned char vfunc_1(void **); }; }
extern "C" unsigned char __cdecl FUN_00246f50(void *, const char *, ...);
unsigned char audio::SeqEventChannelSends::vfunc_1(void **output) {
    if (SeqEvent::vfunc_1(output) && FUN_00246f50(*output, "\n[\n")) {
        struct Output { char pad[0x24]; int depth; };
        ++((Output *)*output)->depth;
        FUN_00246f50(*output, "%s ", "mLayerName");
    }
    return 0;
}
} // namespace fn_0024fae0


// 0x0024fb30 audio::SeqEventChannelSends::vfunc_0 (72 B): matches/0x0024fb30.cpp [wrapped: conflict: SeqEventChannelSends]
// sym: ?vfunc_0@SeqEventChannelSends@fn_0024fb30@@UAEHPAX@Z
namespace fn_0024fb30 {
class SeqEvent {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    bool baseCheck_0025fd20(void*);
};
class SeqEventChannelSends : public SeqEvent {
  public:
    virtual int vfunc_0(void*);
    char pad[0x104];
};
extern "C" bool __cdecl FUN_0024f010(void*, void*);
extern "C" bool __cdecl FUN_0025c7c0(void*, void*);
int SeqEventChannelSends::vfunc_0(void* p) {
    if (SeqEvent::baseCheck_0025fd20(p))
        if (FUN_0024f010(p, (char*)this + 0x108))
            if (FUN_0025c7c0(p, (char*)this + 8))
                return 1;
    return 0;
}
} // namespace fn_0024fb30


// 0x0024fb80 audio::SeqEventChannelSends::vfunc_2 (66 B): equivalent/0x0024fb80.cpp
// sym: ?vfunc_2@SeqEventChannelSends@audio@@UAEXH@Z @8f3f8711eb25 @w7f965a9e9551
// STATUS: equivalent (tools/equiv.py level 3: 19941 inputs, branch coverage 2/2)
// audio::SeqEventChannelSends::vfunc_2 @ 0x0024fb80
void audio::SeqEventChannelSends::vfunc_2(hulk_intptr __p0) { void * channel = (void *)__p0;

    void *memory = FUN_00247530(((char*)&DAT_004e6800));
    audio::SeqActionChannelSends_24fb80 *action = 0;
    if (memory) {
        action = (audio::SeqActionChannelSends_24fb80 *)memory;
        audio::SeqActionChannelSends_24fb80 source(this);
        const unsigned char *src = (const unsigned char *)&source;
        unsigned char *dst = (unsigned char *)action;
        for (unsigned int i = 0; i < 4; ++i) dst[i] = src[i];
        action->event = this;
        action->value = 0;
    }
    ((Channel_24fb80 *)channel)->FUN_0025dc20(action);
}

