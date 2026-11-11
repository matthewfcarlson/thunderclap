// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00252f90..0x00253370 (kind game, layer engine, confidence high), dominant class audio::SeqEventVarPosDist
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "gen/audio.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fe1510ce {
#define TREE_TU_END }
namespace fn_fe1510ce {} using namespace fn_fe1510ce;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_fe1510ce {
class SeqEvent_252fc0 {
  public:
    virtual int Fnf_00252fe0(void*);
    SeqEvent_252fc0();
};
class SeqEventVarPosDist : public SeqEvent_252fc0 {
  public:
    virtual int Fng_00253210(void*);
    int pad;
    float x;
    float y;
    SeqEventVarPosDist();
};
class SeqEvent_252fe0 {
  public:
    bool vfunc_0_0025fd20(void*);
};
class SeqAction_253060 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1(void*);
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
};
struct Obj_253060 {
    char pad[0x38];
    int value;
};
class SeqAction_253080 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
class SeqAction_253090 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(int);
    virtual void f5();
    virtual void f6();
};
extern "C" char __cdecl Scan_00246f50(const char*, const char*, ...);
struct Node {
    const char* text;
};
class Checker {
  public:
    char Check_0025cb40(Node*);
};
} // namespace fn_fe1510ce
extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int) throw();
namespace fn_fe1510ce {
class FUN_00240060 {
  public:
    ~FUN_00240060() throw();
    char pad[12];
};
class FUN_002605e0 {
  public:
    FUN_002605e0(FUN_00240060*, const __int64&, int, int) throw();
    virtual void a();
};
class SeqEventVarPosDistType_253120 : public FUN_002605e0 {
  public:
    SeqEventVarPosDistType_253120() throw();
    virtual void a();
};
} // namespace fn_fe1510ce
namespace audio {
class Base {
  public:
    virtual int v0_00252fe0(void*);
    Base();
};
}
namespace audio {
class SeqEventVarPosDist_2531a0 : public Base {
  public:
    char pad[4];
    float a, b;
    SeqEventVarPosDist_2531a0() : Base(), a(1.0f), b(100.0f) {}
    static void* operator new(size_t, void* p) { return p; }
};
}
namespace fn_fe1510ce {
extern "C" void* FUN_00247530(void*);
struct Stm_253210 {
    char pad[0x24];
    int depth;
};
extern bool Match_00246f50(Stm_253210*, const char*, ...);
extern bool ReadTrack_002530b0(Stm_253210**, const char*, void*);
class SeqEvent {
  public:
    virtual void v0();
    virtual bool v1(Stm_253210**);
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class SeqEventVarPosDist_253210 : public SeqEvent {
    char pad[8];

  public:
    int vfunc_1(Stm_253210**);
};

// 0x00252f90 audio::SeqEventVarPosDistType::vfunc_0 (5 B): not yet verified
// 0x00252fa0 audio::SeqEventVarPosDistType::vfunc_1 (5 B): not yet verified

// 0x00252fb0 FUN_00252fb0 (6 B): matches/0x00252fb0.cpp
// sym: _FUN_00252fb0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
// DAT_004e7038: a static om type (records.h)
extern "C" int* FUN_00252fb0() {
    return &(*(int*)&DAT_004e7038);
}


// 0x00252fc0 FUN_00252fc0 (32 B): matches/0x00252fc0.cpp
// sym: ??0SeqEventVarPosDist@fn_fe1510ce@@QAE@XZ
SeqEventVarPosDist::SeqEventVarPosDist() : SeqEvent_252fc0(), x(1.0f), y(100.0f) {}

} // namespace fn_fe1510ce

// 0x00252fe0 audio::SeqEventVarPosDist::vfunc_0 (48 B): matches/0x00252fe0.cpp
// sym: ?vfunc_0@SeqEventVarPosDist@audio@@UAEHPAX@Z
int audio::SeqEventVarPosDist::vfunc_0(void* __p0) { void * p = (void *)__p0;

    if (((SeqEvent_252fe0*)this)->vfunc_0_0025fd20(p)) {
        if (((PosHelper*)((char*)this + 8))->test(p))
            return 1;
    }
    return 0;
}

namespace fn_fe1510ce {

// 0x00253010 audio::SeqEventVarPosDist::vfunc_3 (6 B): matches/0x00253010.cpp
// sym: _FUN_00253010
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
// DAT_004e7038: a static om type (records.h)
extern "C" int* FUN_00253010() {
    return &(*(int*)&DAT_004e7038);
}

} // namespace fn_fe1510ce

// 0x00253020 audio::SeqActionVarPosDist::vfunc_6 (34 B): matches/0x00253020.cpp
// sym: ?vfunc_6@SeqActionVarPosDist@audio@@UAEXH@Z
// Same code shape as 0x0024ea30 (propagated; names are from that function)
void audio::SeqActionVarPosDist::vfunc_6(hulk_intptr ) {
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


// 0x00253050 audio::SeqActionVarPosDist::vfunc_2 (10 B): matches/0x00253050.cpp
// sym: ?vfunc_2@SeqActionVarPosDist@audio@@UAEXHH@Z
// Same code shape as 0x0024ea60 (propagated; names are from that function)
void audio::SeqActionVarPosDist::vfunc_2(int , int ) {
    this->f_0c = 1;
}


// 0x00253060 audio::SeqActionVarPosDist::vfunc_1 (26 B): matches/0x00253060.cpp
// sym: ?vfunc_1@SeqActionVarPosDist@audio@@UAEXPAX@Z
void audio::SeqActionVarPosDist::vfunc_1(void* __p0) { void * param = (void *)__p0;

    *(int*)((char*)*(hulk_intptr*)((char*)param + 4) + 0x38) = *(int*)((char*)this + 8) + 8;
    *(int*)((char*)this + 0xc) = 0;
}


// 0x00253080 audio::SeqActionVarPosDist::vfunc_3 (10 B): matches/0x00253080.cpp
// sym: ?vfunc_3@SeqActionVarPosDist@audio@@UAEXH@Z
// Same code shape as 0x0024ea70 (propagated; names are from that function)
void audio::SeqActionVarPosDist::vfunc_3(hulk_intptr ) {
    *(int*)((char*)this + 0xc) = 4;
}


// 0x00253090 audio::SeqActionVarPosDist::vfunc_4 (10 B): matches/0x00253090.cpp
// sym: ?vfunc_4@SeqActionVarPosDist@audio@@UAEXH@Z
// Same code shape as 0x0024ea80 (propagated; names are from that function)
void audio::SeqActionVarPosDist::vfunc_4(int ) {
    *(int*)((char*)this + 0xc) = 5;
}


// 0x002530a0 audio::SeqActionVarPosDist::vfunc_5 (6 B): matches/0x002530a0.cpp
// sym: ?vfunc_5@SeqActionVarPosDist@audio@@UAEHH@Z
// Same code shape as 0x002514e0 (propagated; names are from that function)
int audio::SeqActionVarPosDist::vfunc_5(int ) {
    return this->f_0c;
}

namespace fn_fe1510ce {

// 0x002530b0 FUN_002530b0 (66 B): matches/0x002530b0.cpp
// sym: ?target@fn_fe1510ce@@YADPAUNode@1@PADPAVChecker@1@@Z
char __cdecl target(Node* node, char* word, Checker* checker) {
    char* w = word;
    const char* text = node->text;
    if (Scan_00246f50(text, DAT_004298a8, w) && checker->Check_0025cb40(node)) {
        const char* again = node->text;
        return Scan_00246f50(again, DAT_00422518);
    }
    return 0;
}


// 0x00253120 FUN_00253120 (86 B): matches/0x00253120.cpp
// sym: ??0SeqEventVarPosDistType_253120@fn_fe1510ce@@QAE@XZ
SeqEventVarPosDistType_253120::SeqEventVarPosDistType_253120() throw()
    : FUN_002605e0(((FUN_00240060 *)((owners::String_23fc40 *)&(FUN_00240060()))->FUN_0023fc40("3d", (hulk_intptr)0)), FUN_002672f0("SeqEventVarPosDist", 0, 0), (int)sizeof(AudioSeqEventVarPosDist), (int)__alignof(AudioSeqEventVarPosDist)) { HULK_SIZE32(AudioSeqEventVarPosDist, 0x10); }

} // namespace fn_fe1510ce

// 0x00253180 audio::SeqEventVarPosDistType::vfunc_2 (30 B): matches/0x00253180.cpp
// sym: ??_GSeqEventVarPosDistType@audio@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
audio::SeqEventVarPosDistType::~SeqEventVarPosDistType() {}


// 0x002531a0 audio::SeqEventVarPosDistType::vfunc_3 (55 B): matches/0x002531a0.cpp
// sym: ?vfunc_3@SeqEventVarPosDistType@audio@@UAEPAXXZ
// data: heap = DAT_004e7038
void* audio::SeqEventVarPosDistType::vfunc_3() {
    void* p = FUN_00247530(((char*)((char*)&DAT_004e7038)));
    audio::SeqEventVarPosDist_2531a0* q;
    if (p)
        q = new (p) audio::SeqEventVarPosDist_2531a0;
    else
        q = 0;
    return (void*)(q);
}


// 0x002531e0 audio::SeqEventVarPosDist::vfunc_4 (35 B): matches/0x002531e0.cpp [wrapped: conflict: SeqEventVarPosDist]
// sym: ?f4@SeqEventVarPosDist@fn_002531e0@@UAEPAV12@H@Z
namespace fn_002531e0 {

class SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};
class SeqEventVarPosDist : public SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual SeqEventVarPosDist* f4(int);
    void Prep_0025fd10();
};
extern void FUN_00247550(void*, SeqEventVarPosDist*);
SeqEventVarPosDist* SeqEventVarPosDist::f4(int flags) {
    Prep_0025fd10();
    if (flags & 1)
        FUN_00247550((void*)((hulk_intptr)((char*)((char*)&DAT_004e7038))), this);
    return this;
}
} // namespace fn_002531e0

namespace fn_fe1510ce {

// 0x00253210 audio::SeqEventVarPosDist::vfunc_1 (111 B): matches/0x00253210.cpp
// sym: ?vfunc_1@SeqEventVarPosDist_253210@fn_fe1510ce@@QAEHPAPAUStm_253210@2@@Z
// data: sClose = DAT_004298dc, sName_0042a108 = DAT_0042a108, sOpen = DAT_004298f4
int SeqEventVarPosDist_253210::vfunc_1(Stm_253210** p) {
    if (SeqEvent::v1(p)) {
        if (Match_00246f50(*p, DAT_004298f4)) {
            (*p)->depth++;
            if (ReadTrack_002530b0(p, DAT_0042a108, (char*)this + 8)) {
                (*p)->depth--;
                Stm_253210* s = *p;
                if (Match_00246f50(s, DAT_004298dc))
                    return 1;
            }
        }
    }
    return 0;
}

} // namespace fn_fe1510ce

// 0x002532a0 audio::SeqActionVarPosDist::vfunc_0 (36 B): matches/0x002532a0.cpp [wrapped: conflict: audio::SeqAction; audio::SeqActionVarPosDist]
// sym: ?vfunc_0@SeqActionVarPosDist@audio@fn_002532a0@@UAEPAV123@H@Z
namespace fn_002532a0 {

extern "C" char DAT_004298fc[];
namespace audio {
class SeqAction;
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
class SeqActionVarPosDist : public SeqAction {
  public:
    virtual SeqActionVarPosDist* vfunc_0(int);
};
} // namespace audio
extern void FUN_00247550(void*, void*);
audio::SeqActionVarPosDist* audio::SeqActionVarPosDist::vfunc_0(int x) {
    int* p = (int*)this;
    *(hulk_intptr*)p = ((hulk_intptr)DAT_004298fc);
    if (x & 1)
        FUN_00247550((void*)((hulk_intptr)DAT_004e6ff0), this);
    return this;
}
} // namespace fn_002532a0


// 0x002532d0 audio::SeqEventVarPosDist::vfunc_2 (66 B): equivalent/0x002532d0.cpp [wrapped: conflict: audio::SeqActionVarPosDist; audio::SeqEventVarPosDist]
// sym: ?vfunc_2@SeqEventVarPosDist@audio@fn_002532d0@@UAEHPAX@Z @05d423abcc10 @w6735d15eb135
inline void * __cdecl operator new(size_t, void *p) { return p; }
namespace fn_002532d0 {
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// audio::SeqEventVarPosDist::vfunc_2 @ 0x002532d0

namespace audio {
class SeqEventVarPosDist;
class SeqActionVarPosDist {
public:
    virtual void* vfunc_0_002532a0(int);
    virtual void vfunc_1_00253060(void*);
    virtual void vfunc_2_00253050(int, int);
    char padding[4];
    SeqEventVarPosDist *event;
    int value;
};
class SeqEventVarPosDist {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual int vfunc_2(void *);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
}
extern "C" void * __cdecl FUN_00247530(void *);
struct ActionList { int FUN_0025dc20(audio::SeqActionVarPosDist *); };

int audio::SeqEventVarPosDist::vfunc_2(void *list) {
    void *memory = FUN_00247530(((char*)&DAT_004e6ff0));
    audio::SeqActionVarPosDist *action = 0;
    if (memory) {
        action = new (memory) audio::SeqActionVarPosDist;
        action->event = this;
        action->value = 0;
    }
    return ((ActionList *)list)->FUN_0025dc20(action);
}
} // namespace fn_002532d0

