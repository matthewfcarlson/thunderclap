// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00250d90..0x002513a0 (kind game, layer engine, confidence high), dominant class audio::SeqActionStopTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "gen/audio.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fe889925 {
#define TREE_TU_END }
namespace fn_fe889925 {} using namespace fn_fe889925;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_fe889925 {
class Name_250dc0 {
  public:
    int a;
    int b;
    int c;
};
class SeqEvent_250dc0 {
  public:
    SeqEvent_250dc0();
    virtual void Foo();
    char pad[4];
};
class SeqEventStopTrack : public SeqEvent_250dc0 {
  public:
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    SeqEventStopTrack();
    int b;
    int c;
    Name_250dc0 name;
    char flag;
    char _m_pad_1d[0x3];
    SeqEventStopTrack* f4_impl(unsigned char);
};
extern "C" char __cdecl FUN_0025abd0(void*, void*);
extern "C" char __cdecl FUN_0025bce0(void*, void*);
extern "C" char __cdecl FUN_0025aa80(void*, void*);
class SeqEventStopTrack_250e00 : public audio::SeqEvent {
  public:
    char m8[4];
    char mC[4];
    char m10[12];
    virtual int vfunc_0(int*);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
class SeqAction_250ec0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
class SeqAction_250ed0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(int);
    virtual void f5();
    virtual void f6();
};
extern "C" bool Check(const char*, const char*, ...);
extern "C" bool CheckByte(void*, unsigned char);
extern "C" bool EndCheck(const char*, const char*, ...);
struct Obj_250ef0 {
    const char* mName;
};
} // namespace fn_fe889925
extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int);
namespace fn_fe889925 {
struct Arg {
    __int64 val;
    Arg() throw() : val(FUN_002672f0("SeqEventStopTrack", 0, 0)) {}
};
class FUN_00240060 {
  public:
    char pad[12];
    FUN_00240060* FUN_0023fc40(const char*, int) throw();
    ~FUN_00240060() throw();
};
class FUN_002605e0 {
  public:
    FUN_002605e0(FUN_00240060*, const Arg&, int, int) throw();
    virtual void f();
};
class SeqEventStopTrackType_250f60 : public FUN_002605e0 {
  public:
    SeqEventStopTrackType_250f60();
    virtual void f();
};
extern "C" char DAT_00429d1c[];
typedef unsigned int u32_250fe0;
struct E_250fe0 {
    void init();
};
struct S_250fe0 {
};
extern "C" void* FUN_00247530(void*);
struct H1 {
    void run();
};
struct H2_251030 {
    void run();
};
extern void __cdecl FUN_00247550(void*, SeqEventStopTrack*);
struct Str_251170 {
    char* data;
    short mode;
    short pad6;
    short len;
    short pad10;
    Str_251170* FUN_0023fac0();
    const char* FUN_0023fb00();
};
struct Table_251170 { char pad[0x10]; };
struct Node_251170;
struct Pair_251170 { int a; int b; };
struct Mgr_251170 {
    char pad[0x5c];
    Table_251170 table;
};
struct Ctx_251170 {
    char pad[0x3c];
    Mgr_251170* mgr;
};
struct StopData {
    char pad[8];
    int w8;
    int wc;
    Str_251170 name;
    char flag1c;
};
extern "C" void FUN_002613b0(Table_251170* t, Str_251170* out, Str_251170* in);
extern "C" int FUN_002673a0(const char* s, int seed);
Node_251170* FUN_0024a370(Mgr_251170* m, int* key);
extern "C" Node_251170* FUN_002495c0(Mgr_251170* m);
extern "C" Item* FUN_002495f0(Node_251170* n);
extern "C" int FUN_00247930(Mgr_251170* m, Item* it);
extern "C" Item* FUN_00249600(Node_251170* n, Item* it);
extern "C" void FUN_00247b30(Mgr_251170* m, Item* it, Pair_251170* p, int z);
Node_251170* FUN_002495e0(Mgr_251170* m, Node_251170* n);

// 0x00250d90 audio::SeqEventStopTrackType::vfunc_0 (5 B): not yet verified
// 0x00250da0 audio::SeqEventStopTrackType::vfunc_1 (5 B): not yet verified

// 0x00250db0 FUN_00250db0 (6 B): matches/0x00250db0.cpp
// sym: _FUN_00250db0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00250db0() {
    return &(*(int*)&DAT_004e6bc8);
}


// 0x00250dc0 FUN_00250dc0 (51 B): matches/0x00250dc0.cpp
// sym: ??0SeqEventStopTrack@fn_fe889925@@QAE@XZ
SeqEventStopTrack::SeqEventStopTrack() : SeqEvent_250dc0() {
    b = 0;
    c = 0;
    ((owners::String_23fc40 *)&name)->FUN_0023fc40("MySeqTrack", (hulk_intptr)2);
    flag = 0;
}


// 0x00250e00 audio::SeqEventStopTrack::vfunc_0 (103 B): matches/0x00250e00.cpp
// sym: ?vfunc_0@SeqEventStopTrack_250e00@fn_fe889925@@UAEHPAH@Z
int SeqEventStopTrack_250e00::vfunc_0(int* p) {
    if (((char)(audio::SeqEvent::vfunc_0(p)))) {
        if (FUN_0025abd0(p, (char*)this + 8)) {
            if (FUN_0025abd0(p, (char*)this + 12)) {
                if (FUN_0025bce0(p, (char*)this + 16)) {
                    if (FUN_0025aa80(p, (char*)this + 28))
                        return 1;
                }
            }
        }
    }
    return 0;
}


// 0x00250e70 audio::SeqEventStopTrack::vfunc_3 (6 B): matches/0x00250e70.cpp
// sym: _FUN_00250e70
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00250e70() {
    return &(*(int*)&DAT_004e6bc8);
}

} // namespace fn_fe889925

// 0x00250e80 audio::SeqActionStopTrack::vfunc_6 (34 B): matches/0x00250e80.cpp
// sym: ?vfunc_6@SeqActionStopTrack@audio@@UAEXH@Z
// Same code shape as 0x0024ea30 (propagated; names are from that function)
void audio::SeqActionStopTrack::vfunc_6(hulk_intptr ) {
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


// 0x00250eb0 audio::SeqActionStopTrack::vfunc_2 (10 B): matches/0x00250eb0.cpp
// sym: ?vfunc_2@SeqActionStopTrack@audio@@UAEXHH@Z
// Same code shape as 0x0024ea60 (propagated; names are from that function)
void audio::SeqActionStopTrack::vfunc_2(int , int ) {
    this->f_0c = 1;
}


// 0x00250ec0 audio::SeqActionStopTrack::vfunc_3 (10 B): matches/0x00250ec0.cpp
// sym: ?vfunc_3@SeqActionStopTrack@audio@@UAEXH@Z
// Same code shape as 0x0024ea70 (propagated; names are from that function)
void audio::SeqActionStopTrack::vfunc_3(hulk_intptr ) {
    *(int*)((char*)this + 0xc) = 4;
}


// 0x00250ed0 audio::SeqActionStopTrack::vfunc_4 (10 B): matches/0x00250ed0.cpp
// sym: ?vfunc_4@SeqActionStopTrack@audio@@UAEXH@Z
// Same code shape as 0x0024ea80 (propagated; names are from that function)
void audio::SeqActionStopTrack::vfunc_4(int ) {
    *(int*)((char*)this + 0xc) = 5;
}


// 0x00250ee0 audio::SeqActionStopTrack::vfunc_5 (6 B): matches/0x00250ee0.cpp
// sym: ?vfunc_5@SeqActionStopTrack@audio@@UAEHH@Z
// Same code shape as 0x002514e0 (propagated; names are from that function)
int audio::SeqActionStopTrack::vfunc_5(int ) {
    return this->f_0c;
}

namespace fn_fe889925 {

// 0x00250ef0 FUN_00250ef0 (74 B): matches/0x00250ef0.cpp
// sym: _FUN_00250ef0
extern "C" bool FUN_00250ef0(Obj_250ef0* p, hulk_intptr arg, unsigned char* ch) {
    int a = arg;
    const char* s = p->mName;
    if (Check(s, (const char*)((hulk_intptr)((char*)&DAT_004298a8)), a)) {
        if (CheckByte(p, *ch)) {
            p = (Obj_250ef0*)p->mName;
            return EndCheck((const char*)p, (const char*)((hulk_intptr)((char*)&DAT_00422518)));
        }
    }
    return false;
}


// 0x00250f60 FUN_00250f60 (86 B): matches/0x00250f60.cpp
// sym: ??0SeqEventStopTrackType_250f60@fn_fe889925@@QAE@XZ
SeqEventStopTrackType_250f60::SeqEventStopTrackType_250f60() : FUN_002605e0(FUN_00240060().FUN_0023fc40("Stop", 0), Arg(), (int)sizeof(AudioSeqEventStopTrack), (int)__alignof(AudioSeqEventStopTrack)) { HULK_SIZE32(AudioSeqEventStopTrack, 0x20); }

} // namespace fn_fe889925

// 0x00250fc0 audio::SeqEventStopTrackType::vfunc_2 (30 B): matches/0x00250fc0.cpp
// sym: ??_GSeqEventStopTrackType@audio@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
audio::SeqEventStopTrackType::~SeqEventStopTrackType() {}


// 0x00250fe0 audio::SeqEventStopTrackType::vfunc_3 (74 B): matches/0x00250fe0.cpp
// sym: ?vfunc_3@SeqEventStopTrackType@audio@@UAEPAXXZ
// data: name_250fe0 = DAT_0042989c, pool_250fe0 = DAT_004e6bc8
void* audio::SeqEventStopTrackType::vfunc_3() {
    E_250fe0* p = (E_250fe0*)FUN_00247530(((char*)&DAT_004e6bc8));
    if (p) {
        p->init();
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_00429d1c);
        ((u32_250fe0*)p)[2] = 0;
        ((u32_250fe0*)p)[3] = 0;
        ((owners::String_23fc40 *)(((S_250fe0*)((char*)p + 0x10))))->FUN_0023fc40((const char *)(((char*)&DAT_0042989c)), (hulk_intptr)2);
        *((char*)p + 0x1c) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fe889925 {

// 0x00251030 audio::SeqEventStopTrack::vfunc_4 (45 B): matches/0x00251030.cpp
// sym: ?f4_impl@SeqEventStopTrack@fn_fe889925@@QAEPAV12@E@Z
SeqEventStopTrack* SeqEventStopTrack::f4_impl(unsigned char flags) {
    ((H1*)((char*)this + 0x10))->run();
    ((H2_251030*)this)->run();
    if (flags & 1)
        FUN_00247550(((char*)&DAT_004e6bc8), this);
    return this;
}

} // namespace fn_fe889925

// 0x00251060 audio::SeqEventStopTrack::vfunc_1 (181 B): equivalent/0x00251060.cpp [wrapped: conflict: FUN_00250ef0; audio::SeqEvent; audio::SeqEventStopTrack]
// sym: ?vfunc_1@SeqEventStopTrack@audio@fn_00251060@@UAEHPAPAUStream@3@@Z
namespace fn_00251060 {
// STATUS: equivalent (tools/equiv.py level 3: 1600 inputs, branch coverage 14/14)
// audio::SeqEventStopTrack::vfunc_1 @ 0x00251060
struct Stream { char pad[0x24]; unsigned int depth; };
char __cdecl FUN_00246f50(Stream*, const char*, ...);
extern "C" char __cdecl FUN_0024eb60(Stream**, const char*, unsigned int*);
struct NameBuffer { char data[12]; };
extern "C" char __cdecl FUN_0024e600(Stream**, const char*, NameBuffer*);
char __cdecl FUN_00250ef0(Stream**, const char*, unsigned char*);
namespace audio {
struct SeqEvent {
 virtual void vfunc_0();
 virtual int vfunc_1(Stream**);
 virtual void vfunc_2();
 virtual void vfunc_3();
 virtual void vfunc_4();
 virtual void vfunc_5();
 unsigned int field4;
};
struct SeqEventStopTrack : SeqEvent {
 virtual void vfunc_0();
 virtual int vfunc_1(Stream**);
 virtual void vfunc_2();
 virtual void vfunc_3();
 virtual void vfunc_4();
 unsigned int fadeTimeMs;
 unsigned int delayTimeMs;
 NameBuffer trackName;
 unsigned char stopOtherTracks;
};
int SeqEventStopTrack::vfunc_1(Stream** stream) {
 if (!(unsigned char)SeqEvent::vfunc_1(stream)) return 0;
 if (!FUN_00246f50(*stream,"\n[\n")) return 0;
 ++(*stream)->depth;
 if (!FUN_0024eb60(stream,"mFadeTimeMs",&fadeTimeMs)) return 0;
 if (!FUN_0024eb60(stream,"mDelayTimeMs",&delayTimeMs)) return 0;
 if (!FUN_0024e600(stream,"mSeqTrackNameBuf",&trackName)) return 0;
 if (!FUN_00250ef0(stream,"mStopOtherTracks",&stopOtherTracks)) return 0;
 --(*stream)->depth;
 if (!FUN_00246f50(*stream,"]\n")) return 0;
 return 1;
}
}
} // namespace fn_00251060


// 0x00251140 audio::SeqActionStopTrack::vfunc_0 (36 B): matches/0x00251140.cpp [wrapped: conflict: audio::SeqActionStopTrack]
// sym: ?vfunc_0@SeqActionStopTrack@audio@fn_00251140@@UAEPAVSeqAction@3@H@Z
namespace fn_00251140 {
// data: seqActionBss = DAT_004e6b80

extern void* seqActionVtable;
extern void __cdecl FUN_00247550(void*, void*);
class SeqAction {
  public:
    virtual SeqAction* vfunc_0(int);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
};
namespace audio {
class SeqActionStopTrack : public SeqAction {
  public:
    virtual SeqAction* vfunc_0(int);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
};
} // namespace audio
SeqAction* audio::SeqActionStopTrack::vfunc_0(int flags) {
    *(void**)this = &seqActionVtable;
    if (flags & 1)
        FUN_00247550(((char*)&DAT_004e6b80), this);
    return this;
}
} // namespace fn_00251140


// 0x00251170 audio::SeqActionStopTrack::vfunc_1 (366 B): equivalent/0x00251170.cpp
// sym: ?vfunc_1@SeqActionStopTrack@audio@@UAEXPAX@Z
// STATUS: equivalent (tools/equiv.py level 3: 2971 inputs, branch coverage 26/26)
// audio::SeqActionStopTrack::vfunc_1 @ 0x00251170
void audio::SeqActionStopTrack::vfunc_1(void* __p0) { Ctx_251170 * ctx = (Ctx_251170 *)__p0;

    Mgr_251170* mgr = ctx->mgr;
    Str_251170 track;
    track.FUN_0023fac0();
    Str_251170 src;
    ((Str_251170 *)((owners::Thing_240170 *)&src)->FUN_00240170((hulk_intptr)(const Str_251170 *)(&(*(StopData * *)&this->f_08)->name)));
    FUN_002613b0(&ctx->mgr->table, &track, &src);
    ((owners::Str_240060 *)&src)->FUN_00240060();
    int key = FUN_002673a0(track.FUN_0023fb00(), 0);
    Node_251170* target = FUN_0024a370(ctx->mgr, &key);
    if (target != 0) {
        Pair_251170 p;
        p.a = (*(StopData * *)&this->f_08)->wc;
        p.b = (*(StopData * *)&this->f_08)->w8;
        if ((*(StopData * *)&this->f_08)->flag1c != 0) {
            Node_251170* n = FUN_002495c0(mgr);
            while (n != 0) {
                if (n != target) {
                    Item* it = FUN_002495f0(n);
                    while (it != 0) {
                        int k = FUN_00247930(mgr, it);
                        if (k != 0 && k != 5) {
                            FUN_00247b30(mgr, it, &p, 0);
                            break;
                        }
                        it = FUN_00249600(n, it);
                    }
                }
                n = FUN_002495e0(mgr, n);
            }
        } else {
            Item* it = FUN_002495f0(target);
            while (it != 0) {
                int k = FUN_00247930(mgr, it);
                if (k != 0 && k != 5) {
                    FUN_00247b30(mgr, it, &p, 0);
                    break;
                }
                it = FUN_00249600(target, it);
            }
        }
    }
    this->f_0c = 0;
    ((owners::Str_240060 *)&track)->FUN_00240060();
}


// 0x002512e0 audio::SeqEventStopTrack::vfunc_2 (66 B): matches/0x002512e0.cpp [wrapped: conflict: audio::SeqActionStopTrack; audio::SeqEvent; audio::SeqEventStopTrack]
// sym: ?vfunc_2@SeqEventStopTrack@audio@fn_002512e0@@UAEXPAX@Z
inline void* operator new(size_t, char* p) {
    return FUN_00247530(p);
}
namespace fn_002512e0 {
extern "C" unsigned char DAT_004e6b78[112];
// data: bss = DAT_004e6a68

namespace audio {
class SeqEvent {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
class SeqActionStopTrack {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    char pad[4];
    SeqEvent* event;
    int field;
    SeqActionStopTrack(SeqEvent* e) : event(e), field(0) {}
};
class Track {
  public:
    void action(SeqActionStopTrack*);
};
class SeqEventStopTrack : public SeqEvent {
  public:
    virtual void vfunc_2(void*);
};
} // namespace audio
extern "C" void* __cdecl FUN_00247530(void*);

void audio::SeqEventStopTrack::vfunc_2(void* p) {
    ((Track*)p)->action(new (((char*)((char*)&(*(unsigned char(*)[112])&DAT_004e6b78) + 8))) SeqActionStopTrack(this));
}
} // namespace fn_002512e0

