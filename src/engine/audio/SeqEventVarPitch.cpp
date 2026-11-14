// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x00253750..0x00253a90 (kind game, layer engine, confidence high), dominant class audio::SeqEventVarPitch
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "gen/audio.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fd3c3557 {
#define TREE_TU_END }
namespace fn_fd3c3557 {} using namespace fn_fd3c3557;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_fd3c3557 {
extern "C" char DAT_0042a1f0[];
class SeqEvent_253780 {
  public:
    int a;
    int b;
    SeqEvent_253780();
};
class SeqEventVarPitch : public SeqEvent_253780 {
  public:
    float value;
    SeqEventVarPitch();
};
} // namespace fn_fd3c3557
namespace audio {
class SeqEventNestTrack_2537a0 : public ::audio::SeqEvent {
  public:
    virtual int vfunc_0(void*);
    AudioSeqEventLink link;                 // records.h AudioSeqEventVarPitch past the vftable
    float pitch;
};
}
namespace fn_fd3c3557 {
extern bool __cdecl FUN_0025ac10(void*, void*);
class SeqAction_253830 {
  public:
    virtual void f0();
    virtual void f1(void*);
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
class Holder_253830 {
  public:
    char pad[0x1c];
    int value;
};
class SeqAction_253850 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
class SeqAction_253860 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(int);
    virtual void f5();
    virtual void f6();
};
struct Pitch {
    char pad[12];
};
struct SeqEventVarPitchType_2538a0 {
    void* vtable;
    SeqEventVarPitchType_2538a0* FUN_002538a0();
    void FUN_002605e0(Pitch*, unsigned __int64*, int, int);
};
extern void* DAT_0042a20c[];
void* Alloc_00247530(char*);
} // namespace fn_fd3c3557
inline void* operator new(size_t, void* p) {
    return p;
}
namespace audio {
class SeqEvent_253920 {
  public:
    SeqEvent_253920();
    virtual void a();
    virtual int Fnb_00253980(void*);
    virtual void Fnc_00253a40(hulk_intptr);
    virtual void d();
    int unknown;
    float pitch;
};
}
namespace audio {
class SeqEventVarPitch_253920 : public SeqEvent_253920 {
  public:
    SeqEventVarPitch_253920() { pitch = 1.0f; }
    virtual void a();
};
}
namespace audio {
class SeqEventVarPitch_253950 : public ::audio::SeqEvent {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual SeqEventVarPitch_253950* vfunc_4(int);
    void Helper_0025fd10();
};
}
namespace fn_fd3c3557 {
extern void FUN_00247550(void*, audio::SeqEventVarPitch_253950*);
struct Stm_253980 {
    char pad[0x24];
    int depth;
};
extern bool Match_00246f50(Stm_253980*, const char*, ...);
extern "C" bool FUN_00252470(Stm_253980**, const char*, void*);
class SeqEvent {
  public:
    virtual void v0();
    virtual bool v1(Stm_253980**);
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class SeqEventVarPitch_253980 : public SeqEvent {
    AudioSeqEventLink link;                 // records.h AudioSeqEventVarPitch past the vftable
    float pitch;

  public:
    int vfunc_1(Stm_253980**);
};
extern int SeqActionVftable;
extern void __cdecl FUN_00247550(void*, void*);
class SeqAction {
  public:
    int* vptr;
};
class SeqActionVarPitch : public SeqAction {
  public:
    SeqAction* vfunc_0(int);
};
} // namespace fn_fd3c3557
namespace audio {
struct Sequencer;
}
namespace audio {
struct SeqActionVarPitch_253a40 {
    void** vtable;
    int unknown;
    audio::SeqEventVarPitch* event;
    int value;
};
}
namespace audio {
struct Sequencer { void FUN_0025dc20(SeqActionVarPitch_253a40* action); };
}
namespace fn_fd3c3557 {
extern void* DAT_0042a244;
void* __cdecl FUN_00247530(void*);

// 0x00253750 audio::SeqEventVarPitchType::vfunc_0 (5 B): not yet verified
// 0x00253760 audio::SeqEventVarPitchType::vfunc_1 (5 B): not yet verified

// 0x00253770 FUN_00253770 (6 B): matches/0x00253770.cpp
// sym: _FUN_00253770
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00253770() {
    return &(*(int*)&DAT_004e7198);
}


// 0x00253780 FUN_00253780 (25 B): matches/0x00253780.cpp
// sym: ??0SeqEventVarPitch@fn_fd3c3557@@QAE@XZ
SeqEventVarPitch::SeqEventVarPitch() {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0042a1f0);
    value = 1.0f;
}

} // namespace fn_fd3c3557

// 0x002537a0 audio::SeqEventVarPitch::vfunc_0 (52 B): matches/0x002537a0.cpp
// sym: ?vfunc_0@SeqEventNestTrack_2537a0@audio@@UAEHPAX@Z
// Same code shape as 0x0024e590 (propagated; names are from that function)
int audio::SeqEventNestTrack_2537a0::vfunc_0(void* param) {
    if ((unsigned char)::audio::SeqEvent::vfunc_0(param)) {
        if (FUN_0025ac10(param, &this->pitch))
            return 1;
    }
    return 0;
}

namespace fn_fd3c3557 {

// 0x002537e0 audio::SeqEventVarPitch::vfunc_3 (6 B): matches/0x002537e0.cpp
// sym: _FUN_002537e0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_002537e0() {
    return &(*(int*)&DAT_004e7198);
}

} // namespace fn_fd3c3557

// 0x002537f0 audio::SeqActionVarPitch::vfunc_6 (34 B): matches/0x002537f0.cpp
// sym: ?vfunc_6@SeqActionVarPitch@audio@@UAEXH@Z
// Same code shape as 0x0024ea30 (propagated; names are from that function)
void audio::SeqActionVarPitch::vfunc_6(hulk_intptr ) {
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


// 0x00253820 audio::SeqActionVarPitch::vfunc_2 (10 B): matches/0x00253820.cpp
// sym: ?vfunc_2@SeqActionVarPitch@audio@@UAEXHH@Z
// Same code shape as 0x0024ea60 (propagated; names are from that function)
void audio::SeqActionVarPitch::vfunc_2(int , int ) {
    this->f_0c = 1;
}


// 0x00253830 audio::SeqActionVarPitch::vfunc_1 (26 B): matches/0x00253830.cpp
// sym: ?vfunc_1@SeqActionVarPitch@audio@@UAEXPAX@Z
void audio::SeqActionVarPitch::vfunc_1(void* __p0) { void * param = (void *)__p0;

    Holder_253830* h = *(Holder_253830**)((char*)param + 4);
    h->value = *(int*)((char*)this + 8) + 8;
    *(int*)((char*)&this->f_0c) = 0;
}


// 0x00253850 audio::SeqActionVarPitch::vfunc_3 (10 B): matches/0x00253850.cpp
// sym: ?vfunc_3@SeqActionVarPitch@audio@@UAEXH@Z
// Same code shape as 0x0024ea70 (propagated; names are from that function)
void audio::SeqActionVarPitch::vfunc_3(hulk_intptr ) {
    *(int*)((char*)&this->f_0c) = 4;
}


// 0x00253860 audio::SeqActionVarPitch::vfunc_4 (10 B): matches/0x00253860.cpp
// sym: ?vfunc_4@SeqActionVarPitch@audio@@UAEXH@Z
// Same code shape as 0x0024ea80 (propagated; names are from that function)
void audio::SeqActionVarPitch::vfunc_4(int ) {
    *(int*)((char*)&this->f_0c) = 5;
}


// 0x00253870 audio::SeqActionVarPitch::vfunc_5 (6 B): matches/0x00253870.cpp
// sym: ?vfunc_5@SeqActionVarPitch@audio@@UAEHH@Z
// Same code shape as 0x002514e0 (propagated; names are from that function)
int audio::SeqActionVarPitch::vfunc_5(int ) {
    return this->f_0c;
}

namespace fn_fd3c3557 {

// 0x002538a0 FUN_002538a0 (86 B): equivalent/0x002538a0.cpp
// sym: ?FUN_002538a0@SeqEventVarPitchType_2538a0@fn_fd3c3557@@QAEPAU12@XZ @0f89d369f220 @w1c41e1dff2cb
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002538a0 @ 0x002538a0
SeqEventVarPitchType_2538a0* SeqEventVarPitchType_2538a0::FUN_002538a0() {
    HULK_SIZE32(AudioSeqEventVarPitch, 0xc);
    unsigned __int64 value = FUN_002672f0("SeqEventVarPitch",0,0);
    Pitch pitch;
    Pitch* p = ((Pitch *)((owners::String_23fc40 *)&pitch)->FUN_0023fc40("Pitch", (hulk_intptr)0));
    FUN_002605e0(p,&value,(int)sizeof(AudioSeqEventVarPitch),(int)__alignof(AudioSeqEventVarPitch));
    ((owners::Str_240060 *)&pitch)->FUN_00240060();
    vtable = DAT_0042a20c;
    return this;
}

} // namespace fn_fd3c3557

// 0x00253900 audio::SeqEventVarPitchType::vfunc_2 (30 B): matches/0x00253900.cpp
// sym: ??_GSeqEventVarPitchType@audio@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
audio::SeqEventVarPitchType::~SeqEventVarPitchType() {}


// 0x00253920 audio::SeqEventVarPitchType::vfunc_3 (48 B): matches/0x00253920.cpp
// sym: ?vfunc_3@SeqEventVarPitchType@audio@@UAEPAXXZ
// data: gHeap = DAT_004e7198
 // namespace audio
void* audio::SeqEventVarPitchType::vfunc_3() {
    void* p = Alloc_00247530(((char*)&DAT_004e7198));
    if (p)
        return (void*)(new (p) audio::SeqEventVarPitch_253920);
    return (void*)(0);
}


// 0x00253950 audio::SeqEventVarPitch::vfunc_4 (35 B): matches/0x00253950.cpp
// sym: ?vfunc_4@SeqEventVarPitch_253950@audio@@UAEPAV12@H@Z
audio::SeqEventVarPitch_253950* audio::SeqEventVarPitch_253950::vfunc_4(int x) {
    Helper_0025fd10();
    if (x & 1)
        FUN_00247550(((char*)&DAT_004e7198), this);
    return this;
}

namespace fn_fd3c3557 {

// 0x00253980 audio::SeqEventVarPitch::vfunc_1 (111 B): matches/0x00253980.cpp
// sym: ?vfunc_1@SeqEventVarPitch_253980@fn_fd3c3557@@QAEHPAPAUStm_253980@2@@Z
// data: sClose = DAT_004298dc, sName_0042a238 = DAT_0042a238, sOpen = DAT_004298f4
int SeqEventVarPitch_253980::vfunc_1(Stm_253980** p) {
    if (SeqEvent::v1(p)) {
        if (Match_00246f50(*p, DAT_004298f4)) {
            (*p)->depth++;
            if (FUN_00252470(p, DAT_0042a238, &this->pitch)) {
                (*p)->depth--;
                Stm_253980* s = *p;
                if (Match_00246f50(s, DAT_004298dc))
                    return 1;
            }
        }
    }
    return 0;
}


// 0x00253a10 audio::SeqActionVarPitch::vfunc_0 (36 B): matches/0x00253a10.cpp
// sym: ?vfunc_0@SeqActionVarPitch@fn_fd3c3557@@QAEPAVSeqAction@2@H@Z
SeqAction* SeqActionVarPitch::vfunc_0(int flag) {
    SeqAction* self = this;
    vptr = (int*)((hulk_intptr)DAT_004298fc);
    if (flag & 1)
        FUN_00247550(((int*)((char*)&DAT_004e7150)), self);
    return self;
}

} // namespace fn_fd3c3557

// 0x00253a40 audio::SeqEventVarPitch::vfunc_2 (66 B): equivalent/0x00253a40.cpp
// sym: ?vfunc_2@SeqEventVarPitch@audio@@UAEXH@Z @4fc50972ef3f @w71d8f4483c5d
// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 2/2)
// audio::SeqEventVarPitch::vfunc_2 @ 0x00253a40
void audio::SeqEventVarPitch::vfunc_2(hulk_intptr __p0) { audio::Sequencer * sequencer = (audio::Sequencer *)__p0;

    audio::SeqActionVarPitch_253a40* action = (audio::SeqActionVarPitch_253a40*)FUN_00247530(((char*)((char*)&DAT_004e7150)));
    if (action) {
        action->vtable = &DAT_0042a244;
        action->event = this;
        action->value = 0;
    }
    sequencer->FUN_0025dc20(action);
}

