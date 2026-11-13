// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002513a0..0x00251850 (kind game, layer engine, confidence high), dominant class audio::SeqEventPlayTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "gen/audio.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f9a4f3e3 {
#define TREE_TU_END }
namespace fn_f9a4f3e3 {} using namespace fn_f9a4f3e3;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_f9a4f3e3 {
extern "C" char DAT_00429dcc[];
struct SeqEventPlayTrack_nv_2513d0 {
    void Init_0025fd00();
};
class Track_2513d0 {
  public:
};
class SeqEventPlayTrack_2513d0 {
  public:
    hulk_intptr vptr;
    char pad4[4];
    int a;
    int b;
    unsigned char c;
    char pad11[3];
    Track_2513d0 track;
};
class SeqEvent {
  public:
    virtual int dummy();
    bool vfunc_0_0025fd20(void*);
};
extern "C" bool __cdecl FUN_0025abd0(void*, void*);
extern "C" bool __cdecl FUN_0025aa80(void*, void*);
extern "C" bool __cdecl FUN_0025bce0(void*, void*);
class SeqEventPlayTrack : public SeqEvent {
  public:
    char pad[4];
    int a, b, c, d;
    virtual int vfunc_0(void*);
};
class SeqAction_2514c0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
class SeqAction_2514d0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(int);
    virtual void f5();
    virtual void f6();
};
typedef unsigned long long U64;
} // namespace fn_f9a4f3e3
extern "C" U64 __cdecl FUN_002672f0(const char*, int, int) throw();
namespace fn_f9a4f3e3 {
class FUN_00240060 {
  public:
    FUN_00240060* FUN_0023fc40(const char*, int) throw();
    ~FUN_00240060() throw();
    char pad[12];
};
class FUN_002605e0 {
  public:
    FUN_002605e0(FUN_00240060*, const U64&, int, int) throw();
    virtual void v0();
};
class SeqEventPlayTrackType : public FUN_002605e0 {
  public:
    SeqEventPlayTrackType();
    virtual void v0();
};
class SeqEvent_2515e0 {                     // records.h AudioSeqEventPlayTrack past the vftable
  public:
    AudioSeqEventLink link;
    unsigned int fadeTimeMs;
    unsigned int delayTimeMs;
    unsigned char targetResume;
    unsigned char pad11[3];
    OmString seqTrackName;
};
class SeqEventPlayTrack_2515e0 : public SeqEvent_2515e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual SeqEventPlayTrack_2515e0* vfunc_4(unsigned char);
    virtual void v5();
};
class A_2515e0 {
  public:
    void Fnf_00240060();
};
struct SeqEventPlayTrack_nv_2515e0 {
    void Fnf_0025fd10();
};
void __cdecl f47550_00247550(void*, SeqEventPlayTrack_2515e0*);
class SeqActionPlayTrack {
  public:
    int* vptr;
    SeqActionPlayTrack* vfunc_0(int);
};
struct Temp_251720 { char data[12]; void FUN_0023fac0();   unsigned FUN_0023fb00(); };
struct Settings_251720 { char pad[8]; unsigned value8; unsigned valueC; unsigned char flag; char pad2[3]; char name[1]; };
struct Owner_251720 { char pad[0x5c]; char tracks[1]; };
struct Context_251720 { char pad[0x3c]; Owner_251720* owner; };
extern "C" void __cdecl FUN_002613b0(void*,Temp_251720*,Temp_251720*);
extern "C" unsigned __cdecl FUN_002673a0(unsigned,unsigned);
void* __cdecl FUN_0024a370(Owner_251720*,unsigned*);
extern "C" void __cdecl FUN_0024ac40(Owner_251720*,void*,bool,unsigned,void*);
struct Frame_251720 {
 union { Temp_251720 key; unsigned values[2]; } u;
 Temp_251720 result;
};

// 0x002513a0 audio::SeqEventPlayTrackType::vfunc_0 (5 B): not yet verified
// 0x002513b0 audio::SeqEventPlayTrackType::vfunc_1 (5 B): not yet verified

// 0x002513c0 FUN_002513c0 (6 B): matches/0x002513c0.cpp
// sym: _FUN_002513c0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
// DAT_004e6c78: a static om type (records.h)
extern "C" int* FUN_002513c0() {
    return &(*(int*)&DAT_004e6c78);
}


// 0x002513d0 FUN_002513d0 (44 B): matches/0x002513d0.cpp
// sym: ?Target@fn_f9a4f3e3@@YIPAVSeqEventPlayTrack_2513d0@1@PAV21@@Z
SeqEventPlayTrack_2513d0* __fastcall Target(SeqEventPlayTrack_2513d0* self) {
    ((SeqEventPlayTrack_nv_2513d0*)(((audio::SeqEventPlayTrack*)self)))->Init_0025fd00();
    self->vptr = ((hulk_intptr)DAT_00429dcc);
    self->a = 0;
    self->b = 0;
    self->c = 0;
    ((owners::String_23fc40 *)&(self->track))->FUN_0023fc40("MySeqTrack", (hulk_intptr)2);
    return self;
}


// 0x00251400 audio::SeqEventPlayTrack::vfunc_0 (103 B): matches/0x00251400.cpp
// sym: ?vfunc_0@SeqEventPlayTrack@fn_f9a4f3e3@@UAEHPAX@Z
int SeqEventPlayTrack::vfunc_0(void* p) {
    if (SeqEvent::vfunc_0_0025fd20(p) && FUN_0025abd0(p, &a) && FUN_0025abd0(p, &b) && FUN_0025aa80(p, &c) && FUN_0025bce0(p, &d))
        return 1;
    return 0;
}


// 0x00251470 audio::SeqEventPlayTrack::vfunc_3 (6 B): matches/0x00251470.cpp
// sym: _FUN_00251470
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
// DAT_004e6c78: a static om type (records.h)
extern "C" int* FUN_00251470() {
    return &(*(int*)&DAT_004e6c78);
}

} // namespace fn_f9a4f3e3

// 0x00251480 audio::SeqActionPlayTrack::vfunc_6 (34 B): matches/0x00251480.cpp
// sym: ?vfunc_6@SeqActionPlayTrack@audio@@UAEXH@Z
// Same code shape as 0x0024ea30 (propagated; names are from that function)
void audio::SeqActionPlayTrack::vfunc_6(hulk_intptr ) {
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


// 0x002514b0 audio::SeqActionPlayTrack::vfunc_2 (10 B): matches/0x002514b0.cpp
// sym: ?vfunc_2@SeqActionPlayTrack@audio@@UAEXHH@Z
// Same code shape as 0x0024ea60 (propagated; names are from that function)
void audio::SeqActionPlayTrack::vfunc_2(int , int ) {
    this->f_0c = 1;
}


// 0x002514c0 audio::SeqActionPlayTrack::vfunc_3 (10 B): matches/0x002514c0.cpp
// sym: ?vfunc_3@SeqActionPlayTrack@audio@@UAEXH@Z
// Same code shape as 0x0024ea70 (propagated; names are from that function)
void audio::SeqActionPlayTrack::vfunc_3(hulk_intptr ) {
    *(int*)((char*)&this->f_0c) = 4;
}


// 0x002514d0 audio::SeqActionPlayTrack::vfunc_4 (10 B): matches/0x002514d0.cpp
// sym: ?vfunc_4@SeqActionPlayTrack@audio@@UAEXH@Z
// Same code shape as 0x0024ea80 (propagated; names are from that function)
void audio::SeqActionPlayTrack::vfunc_4(int ) {
    *(int*)((char*)&this->f_0c) = 5;
}


// 0x002514e0 audio::SeqActionPlayTrack::vfunc_5 (6 B): matches/0x002514e0.cpp
// sym: ?vfunc_5@SeqActionPlayTrack@audio@@UAEHH@Z
int audio::SeqActionPlayTrack::vfunc_5(int ) {
    return this->f_0c;
}

namespace fn_f9a4f3e3 {

// 0x00251510 FUN_00251510 (86 B): matches/0x00251510.cpp
// sym: ??0SeqEventPlayTrackType@fn_f9a4f3e3@@QAE@XZ
// data: playName = DAT_00429df8, trackName = DAT_00429e00
SeqEventPlayTrackType::SeqEventPlayTrackType() : FUN_002605e0(FUN_00240060().FUN_0023fc40(DAT_00429df8, 0), FUN_002672f0(DAT_00429e00, 0, 0), (int)sizeof(AudioSeqEventPlayTrack), (int)__alignof(AudioSeqEventPlayTrack)) { HULK_SIZE32(AudioSeqEventPlayTrack, 0x20); }

} // namespace fn_f9a4f3e3

// 0x00251570 audio::SeqEventPlayTrackType::vfunc_2 (30 B): matches/0x00251570.cpp
// sym: ??_GSeqEventPlayTrackType@audio@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
audio::SeqEventPlayTrackType::~SeqEventPlayTrackType() {}

namespace fn_f9a4f3e3 {

// 0x002515e0 audio::SeqEventPlayTrack::vfunc_4 (45 B): matches/0x002515e0.cpp
// sym: ?vfunc_4@SeqEventPlayTrack_2515e0@fn_f9a4f3e3@@UAEPAV12@E@Z
// Same code shape as 0x0024fee0 (propagated; names are from that function)
SeqEventPlayTrack_2515e0* SeqEventPlayTrack_2515e0::vfunc_4(unsigned char flag) {
    ((A_2515e0*)&this->seqTrackName)->Fnf_00240060();
    ((SeqEventPlayTrack_nv_2515e0*)(((audio::SeqEventPlayTrack*)this)))->Fnf_0025fd10();
    if (flag & 1)
        f47550_00247550(((char*)((char*)&DAT_004e6c78)), this);
    return this;
}

} // namespace fn_f9a4f3e3

// 0x00251610 audio::SeqEventPlayTrack::vfunc_1 (181 B): equivalent/0x00251610.cpp [wrapped: conflict: audio::SeqEvent; audio::SeqEventPlayTrack]
// sym: ?vfunc_1@SeqEventPlayTrack@audio@fn_00251610@@UAE_NPAUContext@3@@Z @92997774998b @w0f62c75a38ee
namespace fn_00251610 {
// STATUS: equivalent (tools/equiv.py level 3: 1600 inputs, branch coverage 14/14)
// audio::SeqEventPlayTrack::vfunc_1 @ 0x00251610
struct Stream { char pad[0x24]; unsigned int depth; };
struct Context { Stream* stream; };
bool __cdecl FUN_00246f50(Stream*, const char*, ...);
extern "C" bool __cdecl FUN_0024eb60(Context*, const char*, unsigned int*);
bool __cdecl FUN_00250ef0(Context*, const char*, unsigned int*);
extern "C" bool __cdecl FUN_0024e600(Context*, const char*, char*);
namespace audio {
struct SeqEvent {
 virtual void vfunc_0();
 virtual bool vfunc_1(Context*);
 virtual void vfunc_2();
 virtual void vfunc_3();
 virtual void vfunc_4();
 virtual void vfunc_5();
 unsigned int field4;
};
struct SeqEventPlayTrack : SeqEvent {
 unsigned int fadeTimeMs;
 unsigned int delayTimeMs;
 unsigned int targetResume;
 char seqTrackNameBuf[1];
 virtual bool vfunc_1(Context*);
};
bool SeqEventPlayTrack::vfunc_1(Context* context) {
 if (!SeqEvent::vfunc_1(context)) return false;
 if (!FUN_00246f50(context->stream, "\n[\n")) return false;
 ++context->stream->depth;
 if (!FUN_0024eb60(context, "mFadeTimeMs", &fadeTimeMs)) return false;
 if (!FUN_0024eb60(context, "mDelayTimeMs", &delayTimeMs)) return false;
 if (!FUN_00250ef0(context, "mTargetResume", &targetResume)) return false;
 if (!FUN_0024e600(context, "mSeqTrackNameBuf", seqTrackNameBuf)) return false;
 --context->stream->depth;
 if (!FUN_00246f50(context->stream, "]\n")) return false;
 return true;
}
}
} // namespace fn_00251610

namespace fn_f9a4f3e3 {

// 0x002516f0 audio::SeqActionPlayTrack::vfunc_0 (36 B): matches/0x002516f0.cpp
// sym: ?vfunc_0@SeqActionPlayTrack@fn_f9a4f3e3@@QAEPAV12@H@Z
SeqActionPlayTrack* SeqActionPlayTrack::vfunc_0(int x) {
    SeqActionPlayTrack* self = this;
    vptr = (int*)((hulk_intptr)DAT_004298fc);
    if (x & 1)
        Cleanup((void*)((hulk_intptr)((char*)((char*)&DAT_004e6c30))), self);
    return self;
}

} // namespace fn_f9a4f3e3

// 0x00251720 audio::SeqActionPlayTrack::vfunc_1 (181 B): equivalent/0x00251720.cpp
// sym: ?vfunc_1@SeqActionPlayTrack@audio@@UAEXPAX@Z @007cba4f7629 @wf39630e13d9d
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 4/4)
// audio::SeqActionPlayTrack::vfunc_1 @ 0x00251720
void audio::SeqActionPlayTrack::vfunc_1(void* __p0) { Context_251720 * context = (Context_251720 *)__p0;

 Owner_251720* owner=context->owner;
 Frame_251720 f;
 f.result.FUN_0023fac0();
 ((owners::Thing_240170 *)&(f.u.key))->FUN_00240170((hulk_intptr)((*(Settings_251720 * *)&this->f_08)->name));
 FUN_002613b0(owner->tracks,&f.result,&f.u.key);
 ((owners::Str_240060 *)&(f.u.key))->FUN_00240060();
 unsigned id=FUN_002673a0(f.result.FUN_0023fb00(),0);
 void* track=FUN_0024a370(context->owner,&id);
 if(track) { f.u.values[0]=(*(Settings_251720 * *)&this->f_08)->valueC; f.u.values[1]=(*(Settings_251720 * *)&this->f_08)->value8; FUN_0024ac40(owner,track,(*(Settings_251720 * *)&this->f_08)->flag==0,0,f.u.values); }
 (*(unsigned int *)&this->f_0c)=0;
 ((owners::Str_240060 *)&(f.result))->FUN_00240060();
}


// 0x002517e0 audio::SeqEventPlayTrack::vfunc_2 (66 B): equivalent/0x002517e0.cpp [wrapped: conflict: audio::SeqActionPlayTrack; audio::SeqEvent; audio::SeqEventPlayTrack]
// sym: ?vfunc_2@SeqEventPlayTrack@audio@fn_002517e0@@UAEPAXPAX@Z @13edbe6acfe7 @w7507a5ed9445
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_002517e0 {
// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 2/2)
// audio::SeqEventPlayTrack::vfunc_2 @ 0x002517e0

/* size_t: tree_prelude.h */

extern "C" void* __cdecl FUN_00247530(void*);
namespace audio {
struct SeqEvent { virtual void vfunc_0(); virtual void vfunc_1(); virtual void* vfunc_2(void*); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); };
struct SeqActionPlayTrack { virtual void* vfunc_0_002516f0(int); char pad[4]; SeqEvent* event; int state; };
struct SeqEventPlayTrack : SeqEvent { virtual void* vfunc_2(void*); };
}
struct TrackPlayer { void* FUN_0025dc20(audio::SeqActionPlayTrack*); };
void* audio::SeqEventPlayTrack::vfunc_2(void* player) {
    audio::SeqActionPlayTrack* action = (audio::SeqActionPlayTrack*)FUN_00247530(((char*)((char*)&DAT_004e6c30)));
    if (action) {
        action = new (action) audio::SeqActionPlayTrack;
        action->event = this;
        action->state = 0;
    }
    return ((TrackPlayer*)player)->FUN_0025dc20(action);
}
} // namespace fn_002517e0

