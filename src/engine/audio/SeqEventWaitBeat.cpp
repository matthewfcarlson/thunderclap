// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002504b0..0x00250960 (kind game, layer engine, confidence high), dominant class audio::SeqEventWaitBeat
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "gen/audio.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f289a90f {
#define TREE_TU_END }
namespace fn_f289a90f {} using namespace fn_f289a90f;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_f289a90f {
struct Obj_2504b0 {
    void Do_00261e60(int a);
};
class Obj_2504e0 {
  public:
    char pad[8];
    void* Get();
};
class SeqAction_250600 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(int);
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
extern "C" int __cdecl FUN_00246f50(char *, const char *, ...);
struct Context { int FUN_00261e60(char **); };
} // namespace fn_f289a90f
extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int) throw();
namespace fn_f289a90f {
struct FUN_00240060 {
    char data[12];
    FUN_00240060* FUN_0023fc40(const char*, int) throw();
    ~FUN_00240060() throw();
};
struct FUN_002605e0 {
    virtual void vf();
    FUN_002605e0(FUN_00240060*, const __int64&, int, int) throw();
};
struct SeqEventWaitBeatType : FUN_002605e0 {
    SeqEventWaitBeatType();
    virtual void vf();
};
} // namespace fn_f289a90f
namespace audio {
class SeqActionWaitBeat_250770;
}
namespace fn_f289a90f {
extern "C" void __cdecl FUN_00247550(void*, void*);
} // namespace fn_f289a90f
namespace audio {
class SeqActionWaitBeat_250770 : public ::audio::SeqAction {
  public:
    virtual SeqActionWaitBeat_250770* vfunc_0(int);
};
}
namespace fn_f289a90f {
struct FUN_0025fd00 { FUN_0025fd00(); virtual void slot0(); int dummy; };
struct SeqEventWaitBeat : FUN_0025fd00 { virtual void slot0(); int field8; int fieldC; int field10; SeqEventWaitBeat(); };
extern "C" int __cdecl FUN_002673a0(const char *, int);
class SeqEvent_250870 {
  public:
    virtual int vfunc_0(void*);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
extern "C" bool FUN_0024f010(void*, void*);
class Inner_250870 {
  public:
};
class Helper_250870 {
  public:
    bool Probe_0025fd20(void*);
};


// 0x002504b0 FUN_002504b0 (15 B): matches/0x002504b0.cpp
// sym: ?FUN_002504b0@fn_f289a90f@@YAXHH@Z
void __cdecl FUN_002504b0(int a, hulk_intptr b) {
    Obj_2504b0* p = (Obj_2504b0*)b;
    p->Do_00261e60(a);
}


// 0x002504e0 FUN_002504e0 (4 B): matches/0x002504e0.cpp
// sym: ?Get@Obj_2504e0@fn_f289a90f@@QAEPAXXZ
void* Obj_2504e0::Get() {
    return (char*)this + 8;
}

// 0x00250520 audio::SeqEventWaitBeatType::vfunc_0 (5 B): not yet verified
// 0x00250530 audio::SeqEventWaitBeatType::vfunc_1 (5 B): not yet verified

// 0x00250540 FUN_00250540 (6 B): matches/0x00250540.cpp
// sym: _FUN_00250540
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
// DAT_004e6a68: a static om type (records.h)
extern "C" int* FUN_00250540() {
    return &(*(int*)&DAT_004e6a68);
}


// 0x00250550 audio::SeqEventWaitBeat::vfunc_3 (6 B): matches/0x00250550.cpp
// sym: _FUN_00250550
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
// DAT_004e6a68: a static om type (records.h)
extern "C" int* FUN_00250550() {
    return &(*(int*)&DAT_004e6a68);
}

} // namespace fn_f289a90f

// 0x00250560 audio::SeqActionWaitBeat::vfunc_6 (77 B): equivalent/0x00250560.cpp [wrapped: conflict: audio::SeqActionWaitBeat]
// sym: ?vfunc_6@SeqActionWaitBeat@audio@fn_00250560@@QAEXH@Z @383b476975c6 @w0e6a33ed69b8
namespace fn_00250560 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// audio::SeqActionWaitBeat::vfunc_6 @ 0x00250560
namespace audio {
struct BeatSource { char pad[0x2c]; int beat; };
struct SeqActionWaitBeat {
    void *vptr;
    char pad04[4];
    char *sequence;
    int state;
    int previousBeat;
    BeatSource *source;
    void vfunc_6(int unused);
};
}
extern "C" char __cdecl FUN_00261f90(char *sequence, int previousBeat, int currentBeat);
void audio::SeqActionWaitBeat::vfunc_6(int unused) {
    if (state == 3) {
        if (!source) {
            state = 0;
            return;
        }
        int beat = source->beat;
        if (FUN_00261f90(sequence + 8, previousBeat, beat))
            state = 0;
        previousBeat = beat;
    }
}
} // namespace fn_00250560


// 0x002505b0 audio::SeqActionWaitBeat::vfunc_2 (50 B): matches/0x002505b0.cpp [wrapped: conflict: audio::SeqAction; audio::SeqActionWaitBeat]
// sym: ?vfunc_2@SeqActionWaitBeat@audio@fn_002505b0@@UAEXPAXH@Z
namespace fn_002505b0 {
typedef unsigned int u32_2505b0;
namespace audio {
struct SeqAction {
    virtual void f0();
    virtual void f1();
    virtual void vfunc_2(void*, int);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    char pad[4];
};
struct SeqActionWaitBeat : SeqAction {
    hulk_uintptr m8;
    u32_2505b0 mc;
    u32_2505b0 m10;
    hulk_uintptr m14;
    void vfunc_2(void*, int);
};
} // namespace audio
extern "C" void* __cdecl FUN_0024a390(u32_2505b0, void*);
void audio::SeqActionWaitBeat::vfunc_2(void* param, int unused) {
    u32_2505b0 value = *(u32_2505b0*)((char*)param + 0x3c);
    void* result = FUN_0024a390(value, (char*)m8 + 0x10);
    m14 = (hulk_uintptr)result;
    if (result)
        m10 = *(u32_2505b0*)((char*)result + 0x2c);
    mc = 2;
}
} // namespace fn_002505b0


// 0x002505f0 audio::SeqActionWaitBeat::vfunc_1 (10 B): matches/0x002505f0.cpp
// sym: ?vfunc_1@SeqActionWaitBeat@audio@@UAEXPAX@Z
// Same code shape as 0x00250230 (propagated; names are from that function)
 // namespace audio
void audio::SeqActionWaitBeat::vfunc_1(void* __p0) {
    this->f_0c = 3;
}


// 0x00250600 audio::SeqActionWaitBeat::vfunc_3 (10 B): matches/0x00250600.cpp
// sym: ?vfunc_3@SeqActionWaitBeat@audio@@UAEXH@Z
void audio::SeqActionWaitBeat::vfunc_3(hulk_intptr ) {
    *(int*)((char*)&this->f_0c) = 2;
}


// 0x00250610 audio::SeqActionWaitBeat::vfunc_4 (10 B): matches/0x00250610.cpp
// sym: ?vfunc_4@SeqActionWaitBeat@audio@@UAEXH@Z
void audio::SeqActionWaitBeat::vfunc_4(int ) {
    this->f_0c = 0;
}


// 0x00250620 audio::SeqActionWaitBeat::vfunc_5 (6 B): matches/0x00250620.cpp
// sym: ?vfunc_5@SeqActionWaitBeat@audio@@UAEHH@Z
// Same code shape as 0x002514e0 (propagated; names are from that function)
int audio::SeqActionWaitBeat::vfunc_5(int ) {
    return this->f_0c;
}

namespace fn_f289a90f {

// 0x00250640 FUN_00250640 (66 B): equivalent/0x00250640.cpp
// sym: _FUN_00250640 @6d01b1fb79bf @w6bab0353120b
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00250640 @ 0x00250640
extern "C" int __cdecl FUN_00250640(char **buffer, int value, Context *context) {
    int result = FUN_00246f50(*buffer, ((char*)&DAT_004298a8), value);
    if ((unsigned char)result != 0) {
        result = context->FUN_00261e60(buffer);
        if ((unsigned char)result != 0)
            return FUN_00246f50(*buffer, ((char*)&DAT_00422518));
    }
    return result & 0xffffff00;
}


// 0x002506d0 FUN_002506d0 (86 B): matches/0x002506d0.cpp
// sym: ??0SeqEventWaitBeatType@fn_f289a90f@@QAE@XZ
SeqEventWaitBeatType::SeqEventWaitBeatType()
    : FUN_002605e0(FUN_00240060().FUN_0023fc40("Beat", 0), FUN_002672f0("SeqEventWaitBeat", 0, 0), (int)sizeof(AudioSeqEventWaitBeat), (int)__alignof(AudioSeqEventWaitBeat)) { HULK_SIZE32(AudioSeqEventWaitBeat, 0x14); }

} // namespace fn_f289a90f

// 0x00250730 audio::SeqEventWaitBeatType::vfunc_2 (30 B): matches/0x00250730.cpp
// sym: ??_GSeqEventWaitBeatType@audio@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
audio::SeqEventWaitBeatType::~SeqEventWaitBeatType() {}


// 0x00250770 audio::SeqActionWaitBeat::vfunc_0 (36 B): matches/0x00250770.cpp
// sym: ?vfunc_0@SeqActionWaitBeat_250770@audio@@UAEPAV12@H@Z
namespace audio {
SeqActionWaitBeat_250770* SeqActionWaitBeat_250770::vfunc_0(int flag) {
    SeqActionWaitBeat_250770* s = this;
    *(hulk_intptr*)s = ((hulk_intptr)DAT_004298fc);
    if (flag & 1)
        FUN_00247550((void*)((hulk_intptr)DAT_004e6a18), s);
    return s;
}
}

namespace fn_f289a90f {

// 0x002507c0 FUN_002507c0 (43 B): equivalent/0x002507c0.cpp
// sym: ??0SeqEventWaitBeat@fn_f289a90f@@QAE@XZ @ec8f98f0f364 @wfa6725a6ab04
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002507c0 @ 0x002507c0
SeqEventWaitBeat::SeqEventWaitBeat() { field8=0; fieldC=0; field10=FUN_002673a0("stitched",0); }

} // namespace fn_f289a90f

// 0x002507f0 audio::SeqEventWaitBeat::vfunc_4 (45 B): matches/0x002507f0.cpp [wrapped: conflict: SeqEventWaitBeat]
// sym: ?f4@SeqEventWaitBeat@fn_002507f0@@UAEPAV12@H@Z
namespace fn_002507f0 {

class SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual SeqEvent* f4(int);
    virtual void f5();
};
class H {
  public:
    void FUN_00262020();
};
class SeqEventWaitBeat : public SeqEvent {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual SeqEventWaitBeat* f4(int);
    void FUN_0025fd10();
};
extern "C" void __cdecl FUN_00247550(void*, void*);
SeqEventWaitBeat* SeqEventWaitBeat::f4(int x) {
    H* h = (H*)((char*)this + 8);
    h->FUN_00262020();
    FUN_0025fd10();
    if (x & 1)
        FUN_00247550(((char*)((char*)&DAT_004e6a68)), this);
    return this;
}
} // namespace fn_002507f0


// 0x00250820 audio::SeqEventWaitBeat::vfunc_1 (71 B): equivalent/0x00250820.cpp [wrapped: conflict: audio::SeqEvent; audio::SeqEventWaitBeat]
// sym: ?vfunc_1@SeqEventWaitBeat@audio@fn_00250820@@UAE_NPAUSeqEventArg@23@@Z @4c9290bf2650 @w3594e5a13bea
namespace fn_00250820 {
// STATUS: equivalent (tools/equiv.py level 3: 2823 inputs, branch coverage 4/4)
// audio::SeqEventWaitBeat::vfunc_1 @ 0x00250820
namespace audio {
struct SeqEvent {
    virtual void vfunc_0();
    virtual bool vfunc_1(struct SeqEventArg* arg);
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
struct SeqEventWaitBeat : SeqEvent {
    virtual void vfunc_0();
    virtual bool vfunc_1(struct SeqEventArg* arg);
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
struct SeqEventData {
    char pad[0x24];
    int layerCount;
};
struct SeqEventArg { SeqEventData* data; };
}
extern bool __cdecl FUN_00246f50(audio::SeqEventData*, const char*, ...);
bool audio::SeqEventWaitBeat::vfunc_1(audio::SeqEventArg* arg) {
    if (audio::SeqEvent::vfunc_1(arg) && FUN_00246f50(arg->data, "\n[\n")) {
        ++arg->data->layerCount;
        FUN_00246f50(arg->data, "%s ", "mLayerNameBuf");
    }
    return false;
}
} // namespace fn_00250820


// 0x00250870 audio::SeqEventWaitBeat::vfunc_0 (65 B): matches/0x00250870.cpp
// sym: ?vfunc_0@SeqEventWaitBeat@audio@@UAEHPAX@Z
int audio::SeqEventWaitBeat::vfunc_0(void* __p0) { void * arg = (void *)__p0;

    if (((Helper_250870*)this)->Probe_0025fd20(arg) && FUN_0024f010(arg, &this->f_10) && ((owners::Obj_261ef0 *)(((Inner_250870*)((char*)&this->f_08))))->FUN_00261ef0((const char *)arg))
        return 1;
    return 0;
}

