// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00252780..0x00252b30 (kind game, layer engine, confidence high), dominant class audio::SeqEventVarVolume
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "gen/audio.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fa65be09 {
#define TREE_TU_END }
namespace fn_fa65be09 {} using namespace fn_fa65be09;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_fa65be09 {
extern "C" char DAT_00429fac[];
class SeqEvent_2527b0 {
  public:
    void Init();
};
class SeqEventVarVolume : public SeqEvent_2527b0 {
  public:
    hulk_intptr vtable;
    int pad;
    float volume;
    SeqEventVarVolume* Build();
};
extern "C" int FUN_0025ac10(int, void*);
class SeqEventVarVolume_2527d0 : public audio::SeqEvent {
  public:
    virtual int vfunc_0(int);
};
class SeqAction_252840 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1(void*);
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
};
class SeqAction_252860 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
class SeqAction_252870 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(int);
    virtual void f5();
    virtual void f6();
};
typedef unsigned __int64 U64;
} // namespace fn_fa65be09
extern "C" U64 __cdecl FUN_002672f0(const char*, int, int) throw();
namespace fn_fa65be09 {
class FUN_00240060 {
    char data[12];

  public:
    ~FUN_00240060() throw();
};
class FUN_002605e0 {
  public:
    FUN_002605e0(FUN_00240060*, const U64&, int, int) throw();
    virtual void v();
};
class SeqEventVarVolumeType_2528b0 : public FUN_002605e0 {
  public:
    SeqEventVarVolumeType_2528b0() throw();
    virtual void v();
};
typedef unsigned int u32_252930;
} // namespace fn_fa65be09
namespace audio {
class SeqEventType_252930 {
  public:
    virtual ~SeqEventType_252930();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};
}
namespace audio {
class SeqEventVarVolume_252930 {
  public:
    void* vptr;
    u32_252930 pad;
    float volume;
    void Init();
};
}
namespace fn_fa65be09 {
extern "C" audio::SeqEventVarVolume_252930* FUN_00247530(void*);
struct Stm_252990 {
    char pad[0x24];
    int depth;
};
extern bool Match(Stm_252990*, const char*, ...);
extern "C" bool FUN_00252470(Stm_252990**, const char*, void*);
class SeqEvent {
  public:
    virtual void v0();
    virtual bool v1(Stm_252990**);
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class SeqEventVarVolume_252990 : public SeqEvent {
    char pad[8];

  public:
    int vfunc_1(Stm_252990**);
};
extern "C" void FUN_00247550(void*, void*);
class SeqActionVarVolume_252a20 : public audio::SeqAction {
  public:
    SeqActionVarVolume_252a20* vfunc_0(int);
};

// 0x00252780 audio::SeqEventVarVolumeType::vfunc_0 (5 B): not yet verified
// 0x00252790 audio::SeqEventVarVolumeType::vfunc_1 (5 B): not yet verified

// 0x002527a0 FUN_002527a0 (6 B): matches/0x002527a0.cpp
// sym: _FUN_002527a0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_002527a0() {
    return &(*(int*)&DAT_004e6ed8);
}


// 0x002527b0 FUN_002527b0 (25 B): matches/0x002527b0.cpp
// sym: ?Build@SeqEventVarVolume@fn_fa65be09@@QAEPAV12@XZ
SeqEventVarVolume* SeqEventVarVolume::Build() {
    Init();
    vtable = ((hulk_intptr)DAT_00429fac);
    volume = 1.0f;
    return this;
}


// 0x002527d0 audio::SeqEventVarVolume::vfunc_0 (32 B): matches/0x002527d0.cpp
// sym: ?vfunc_0@SeqEventVarVolume_2527d0@fn_fa65be09@@UAEHH@Z
int SeqEventVarVolume_2527d0::vfunc_0(int value) {
    audio::SeqEvent::vfunc_0((void *)(value));
    return FUN_0025ac10(value, (char*)this + 8);
}


// 0x002527f0 audio::SeqEventVarVolume::vfunc_3 (6 B): matches/0x002527f0.cpp
// sym: _FUN_002527f0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_002527f0() {
    return &(*(int*)&DAT_004e6ed8);
}

} // namespace fn_fa65be09

// 0x00252800 audio::SeqActionVarVolume::vfunc_6 (34 B): matches/0x00252800.cpp
// sym: ?vfunc_6@SeqActionVarVolume@audio@@UAEXH@Z
// Same code shape as 0x0024ea30 (propagated; names are from that function)
void audio::SeqActionVarVolume::vfunc_6(hulk_intptr ) {
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


// 0x00252830 audio::SeqActionVarVolume::vfunc_2 (10 B): matches/0x00252830.cpp
// sym: ?vfunc_2@SeqActionVarVolume@audio@@UAEXHH@Z
// Same code shape as 0x0024ea60 (propagated; names are from that function)
void audio::SeqActionVarVolume::vfunc_2(int , int ) {
    this->f_0c = 1;
}


// 0x00252840 audio::SeqActionVarVolume::vfunc_1 (26 B): matches/0x00252840.cpp
// sym: ?vfunc_1@SeqActionVarVolume@audio@@UAEXPAX@Z
void audio::SeqActionVarVolume::vfunc_1(void* __p0) { void * p = (void *)__p0;

    *(int*)((char*)*(hulk_intptr*)((char*)p + 4) + 0x18) = this->f_08 + 8;
    this->f_0c = 0;
}


// 0x00252860 audio::SeqActionVarVolume::vfunc_3 (10 B): matches/0x00252860.cpp
// sym: ?vfunc_3@SeqActionVarVolume@audio@@UAEXH@Z
// Same code shape as 0x0024ea70 (propagated; names are from that function)
void audio::SeqActionVarVolume::vfunc_3(hulk_intptr ) {
    *(int*)((char*)this + 0xc) = 4;
}


// 0x00252870 audio::SeqActionVarVolume::vfunc_4 (10 B): matches/0x00252870.cpp
// sym: ?vfunc_4@SeqActionVarVolume@audio@@UAEXH@Z
// Same code shape as 0x0024ea80 (propagated; names are from that function)
void audio::SeqActionVarVolume::vfunc_4(int ) {
    *(int*)((char*)this + 0xc) = 5;
}


// 0x00252880 audio::SeqActionVarVolume::vfunc_5 (6 B): matches/0x00252880.cpp
// sym: ?vfunc_5@SeqActionVarVolume@audio@@UAEHH@Z
// Same code shape as 0x002514e0 (propagated; names are from that function)
int audio::SeqActionVarVolume::vfunc_5(int ) {
    return this->f_0c;
}

namespace fn_fa65be09 {

// 0x002528b0 FUN_002528b0 (86 B): matches/0x002528b0.cpp
// sym: ??0SeqEventVarVolumeType_2528b0@fn_fa65be09@@QAE@XZ
SeqEventVarVolumeType_2528b0::SeqEventVarVolumeType_2528b0() throw()
    : FUN_002605e0(((FUN_00240060 *)((owners::String_23fc40 *)&(FUN_00240060()))->FUN_0023fc40("Vol", (hulk_intptr)0)), FUN_002672f0("SeqEventVarVolume", 0, 0), (int)sizeof(AudioSeqEventVarVolume), (int)__alignof(AudioSeqEventVarVolume)) { HULK_SIZE32(AudioSeqEventVarVolume, 0xc); }

} // namespace fn_fa65be09

// 0x00252910 audio::SeqEventVarVolumeType::vfunc_2 (30 B): matches/0x00252910.cpp
// sym: ??_GSeqEventVarVolumeType@audio@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
audio::SeqEventVarVolumeType::~SeqEventVarVolumeType() {}


// 0x00252930 audio::SeqEventVarVolumeType::vfunc_3 (48 B): matches/0x00252930.cpp
// sym: ?vfunc_3@SeqEventVarVolumeType@audio@@UAEPAXXZ
// data: g_seqVarVolumeHeap = DAT_004e6ed8
void* audio::SeqEventVarVolumeType::vfunc_3() {
    audio::SeqEventVarVolume_252930* p = FUN_00247530((void*)((char*)&DAT_004e6ed8));
    if (p) {
        p->Init();
        p->vptr = (void*)((hulk_intptr)DAT_00429fac);
        p->volume = 1.0f;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fa65be09 {

// 0x00252990 audio::SeqEventVarVolume::vfunc_1 (111 B): matches/0x00252990.cpp
// sym: ?vfunc_1@SeqEventVarVolume_252990@fn_fa65be09@@QAEHPAPAUStm_252990@2@@Z
// data: sClose = DAT_004298dc, sName_00429ff0 = DAT_00429ff0, sOpen = DAT_004298f4
int SeqEventVarVolume_252990::vfunc_1(Stm_252990** p) {
    if (SeqEvent::v1(p)) {
        if (Match(*p, DAT_004298f4)) {
            (*p)->depth++;
            if (FUN_00252470(p, DAT_00429ff0, (char*)this + 8)) {
                (*p)->depth--;
                Stm_252990* s = *p;
                if (Match(s, DAT_004298dc))
                    return 1;
            }
        }
    }
    return 0;
}


// 0x00252a20 audio::SeqActionVarVolume::vfunc_0 (36 B): matches/0x00252a20.cpp
// sym: ?vfunc_0@SeqActionVarVolume_252a20@fn_fa65be09@@QAEPAV12@H@Z
SeqActionVarVolume_252a20* SeqActionVarVolume_252a20::vfunc_0(int x) {
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_004298fc);
    if (x & 1)
        FUN_00247550((void*)((hulk_intptr)DAT_004e6e90), this);
    return this;
}

} // namespace fn_fa65be09
