// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0012d920..0x0012dfe0 (kind game, layer game, confidence high), dominant class hulkfight::PostEvent_StringTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_facdac2a {
#define TREE_TU_END }
namespace fn_facdac2a {} using namespace fn_facdac2a;
#include "game/hulkfight.h"

// ---- declarations shared by the functions below
namespace fn_facdac2a {
class A_12d920 {
  public:
    char Set(int x);
    char mPad[12];
    int mVal;
};
struct Sub_12d930 {
    int x;
};
struct A_12d930 {
    char pad[16];
    Sub_12d930 sub;
    Sub_12d930* Get();
};
class Foo_12d950 {
  public:
    char Set(char x);
    char pad[0x18];
    char m18;
};
class Obj {
  public:
    char _m_pad_0[0x19];
    char flag;
    bool SetFlag(char v);
    void Use_002367c0(void*);
};
extern int* hulk_at_004e0e44;
class CCondition_12d9a0 {
  public:
    virtual int vfunc_0(int);
};
class Track_12d9b0 {
  public:
    Track_12d9b0();
    virtual void f();
    char fields[8];
};
class Member {
  public:
    Member();
};
class PostEvent_StringTrack : public Track_12d9b0 {
  public:
    PostEvent_StringTrack();
    virtual void f();
    int n;
    Member member;
    char pad[7];
    char a, b;
};
extern void* hulk_at_004110e0[];
class Str_12da00 {
  public:
    void Init_0027af50();
};
class Track_12da00 {
  public:
    void* vptr;
    char pad[12];
    Str_12da00 s;
    void Fin_00236d60();
};
class PostEvent_StringTrack_12da00 : public Track_12da00 {
  public:
    ~PostEvent_StringTrack_12da00();
};
class Action_12da20 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
struct Key {
    int lo, hi;
    Key() throw() {}
    Key(const Key &other) throw();
};
struct StatusCheck {
    char pad00[1];
    char FUN_001ccff0();
};
struct EventQueue {
    char pad00[1];
    char FUN_001cb990(Key id);
    void FUN_001cbc20(void *event);
};
struct EventBuilder {
    char data[0x20];
    void FUN_001cadf0(Key id);
};
} // namespace fn_facdac2a
struct World {
    char pad00[0x2c];
    StatusCheck *status;     // 0x2c
    EventQueue *queue;       // 0x30
};
namespace fn_facdac2a {
struct ActionParams_12da30 {
    char pad00[0x10];
    Key id;                 // 0x10
    char requireStatus;      // 0x18
    char requireNotQueued;   // 0x19
};
class PostEvent_StringAction {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual bool vfunc_5(int a, int b);
    char pad04[0x18];
    ActionParams_12da30 *params;    // 0x1c
};
extern char threat_vftable_12db20;
struct PostEvent_StringTrack_nv_12db20 {
    void f1_0027af50();
    void f2_00236d60();
};
extern void thunk_FUN_00267090(hulkfight::PostEvent_StringTrack*);
class PostEvent_StringTrack_12db20 {
  public:
    void* vftable;
    char pad[0x0c];
    PostEvent_StringTrack_12db20* vfunc_5(unsigned char);
};
extern "C" char DAT_00411110[];
class Ref_12dba0 {
  public:
    virtual void f();
    virtual void Release();
};
class Action_12dba0 {
  public:
    virtual void Dummy();
    void Finish();
};
struct PostEvent_StringAction_nv_12dba0 {
    void Finish_002326a0();
};
class CStageCondition_12dc10;
class ParamValue_12dc10 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_12dc10 : public ParamValue_12dc10 {
  public:
    int pad;
};
class CStageCondition_12dc60;
class ParamValue_12dc60 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_12dc60 : public ParamValue_12dc60 {
  public:
    int pad;
};
extern char DAT_004a9b10;
extern "C" int FUN_00344e74(hulk_intptr, int, hulk_intptr, hulk_intptr, int);
class TrackFactoryCaster_12dc80 {
  public:
    virtual int vfunc_0(int);
    virtual void vfunc_1();
};
struct Ref_12dcf0 {
    virtual void f0();
    virtual void f1();
};
extern void* Alloc_0008d690(hulk_uintptr);
struct Memory_12dcf0 {
    void Init_00232660();
};
extern void* hulk_at_00411110[];
class Ref_12dd50 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_12dd50 {
  public:
    void* vptr;
};
class PostEvent_StringAction_12dd50 : public Action_12dd50 {
  public:
    char pad[32 - 4];
    Ref_12dd50* m;
    PostEvent_StringAction_12dd50* f2(unsigned char flags);
};
class ParamValueBranch {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class ParamValue {};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
class TrackFactoryCaster_12de00 {
  public:
    virtual void Cast();
};
class TrackFactoryCasterTemplate_12de00 : public TrackFactoryCaster_12de00 {
  public:
    virtual void Cast();
};
extern "C" void* __cdecl FUN_00236ac0(void*, TrackFactoryCaster_12de00*);
} // namespace fn_facdac2a
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_facdac2a {
class TrackFactoryTemplate_12df30 {
  public:
    TrackFactoryTemplate_12df30() {}
    virtual void vf0();
    virtual void vf1();
    int mPad;
    TrackImpl mTrack;
};
extern "C++" __declspec(nothrow) void FUN_0012de30();
extern void* FUN_0008d690(unsigned int);
extern void* PostEvent_StringTrack_vtable;
struct Helper_12df70 {
    void FUN_00236d40();
};
struct SubHelper {
    void FUN_0027af00();
};
extern int hulk_at_004111b8;


// 0x0012d920 FUN_0012d920 (12 B): matches/0x0012d920.cpp
// sym: ?Set@A_12d920@fn_facdac2a@@QAEDH@Z
char A_12d920::Set(int x) {
    mVal = x;
    return 1;
}


// 0x0012d930 FUN_0012d930 (4 B): matches/0x0012d930.cpp
// sym: ?Get@A_12d930@fn_facdac2a@@QAEPAUSub_12d930@2@XZ
Sub_12d930* A_12d930::Get() {
    return &sub;
}


// 0x0012d950 FUN_0012d950 (12 B): matches/0x0012d950.cpp
// sym: ?Set@Foo_12d950@fn_facdac2a@@QAEDD@Z
char Foo_12d950::Set(char x) {
    m18 = x;
    return 1;
}


// 0x0012d970 FUN_0012d970 (12 B): matches/0x0012d970.cpp
// sym: ?SetFlag@Obj@fn_facdac2a@@QAE_ND@Z
bool Obj::SetFlag(char v) {
    flag = v;
    return true;
}


// 0x0012d980 FUN_0012d980 (19 B): matches/0x0012d980.cpp
// sym: ?FUN_0012d980@fn_facdac2a@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0012d980() {
    FUN_00234810(((char*)&DAT_004e0e44), ((char*)&DAT_004e0e48));
}

} // namespace fn_facdac2a

// 0x0012d9a0 hulkfight::PostEvent_StringTrack::vfunc_0 (16 B): matches/0x0012d9a0.cpp
// sym: ?vfunc_0@PostEvent_StringTrack@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::PostEvent_StringTrack::vfunc_0(int index) {
    int* p = hulk_at_004e0e44;
    return p[index];
}

namespace fn_facdac2a {

// 0x0012d9b0 FUN_0012d9b0 (41 B): matches/0x0012d9b0.cpp
// sym: ??0PostEvent_StringTrack@fn_facdac2a@@QAE@XZ
PostEvent_StringTrack::PostEvent_StringTrack() : Track_12d9b0(), n(0), member(), a(0), b(0) {}

} // namespace fn_facdac2a

// 0x0012d9e0 hulkfight::PostEvent_StringTrack::vfunc_6 (4 B): matches/0x0012d9e0.cpp
// sym: ?vfunc_6@PostEvent_StringTrack@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::PostEvent_StringTrack::vfunc_6() {
    return this->f_0c;
}


// 0x0012d9f0 hulkfight::PostEvent_StringTrack::vfunc_7 (7 B): matches/0x0012d9f0.cpp
// sym: ?vfunc_7@PostEvent_StringTrack@hulkfight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg hulkfight::PostEvent_StringTrack::vfunc_7() {
    return DAT_003f32e0;
}

namespace fn_facdac2a {

// 0x0012da00 FUN_0012da00 (25 B): matches/0x0012da00.cpp
// sym: ??1PostEvent_StringTrack_12da00@fn_facdac2a@@QAE@XZ
PostEvent_StringTrack_12da00::~PostEvent_StringTrack_12da00() {
    vptr = hulk_at_004110e0;
    s.Init_0027af50();
    Fin_00236d60();
}

} // namespace fn_facdac2a

// 0x0012da20 hulkfight::PostEvent_StringAction::vfunc_3 (5 B): matches/0x0012da20.cpp
// sym: ?vfunc_3@PostEvent_StringAction@hulkfight@@UAE_NHH@Z
bool hulkfight::PostEvent_StringAction::vfunc_3(hulk_intptr a, hulk_intptr b) {
    return (bool)(1);
}

namespace fn_facdac2a {

// 0x0012da30 hulkfight::PostEvent_StringAction::vfunc_5 (142 B): equivalent/0x0012da30.cpp
// sym: ?vfunc_5@PostEvent_StringAction@fn_facdac2a@@UAE_NHH@Z @10c9f1424451 @wbc849a787a60
// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 16/16)
// hulkfight::PostEvent_StringAction::vfunc_5 @ 0x0012da30
// equiv-map: ??0Key@@QAE@ABU0@@Z = 0x0027af30
bool PostEvent_StringAction::vfunc_5(int a, int b) {
    World *game = DAT_004dd700;
    if (game) {
        if (params->requireStatus) {
            if (!game->status || !game->status->FUN_001ccff0())
                return false;
        }
        if (params->requireNotQueued) {
            EventQueue *q = game->queue;
            if (!q || q->FUN_001cb990(params->id))
                return false;
        }
        EventQueue *q = game->queue;
        if (q) {
            EventBuilder ev;
            ev.FUN_001cadf0(params->id);
            q->FUN_001cbc20(&ev);
        }
    }
    return false;
}


// 0x0012dac0 hulkfight::PostEvent_StringAction::vfunc_4 (1 B): matches/0x0012dac0.cpp
// sym: ?FUN_0012dac0@fn_facdac2a@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_0012dac0() {}


// 0x0012db20 hulkfight::PostEvent_StringTrack::vfunc_5 (46 B): matches/0x0012db20.cpp
// sym: ?vfunc_5@PostEvent_StringTrack_12db20@fn_facdac2a@@QAEPAV12@E@Z
// Same code shape as 0x0012bc00 (propagated; names are from that function)
PostEvent_StringTrack_12db20* PostEvent_StringTrack_12db20::vfunc_5(unsigned char param) {
    PostEvent_StringTrack_12db20* p = this;
    *(char**)p = &threat_vftable_12db20;
    ((PostEvent_StringTrack_nv_12db20*)(((hulkfight::PostEvent_StringTrack*)((char*)p + 0x10))))->f1_0027af50();
    ((PostEvent_StringTrack_nv_12db20*)(((hulkfight::PostEvent_StringTrack*)p)))->f2_00236d60();
    if (param & 1)
        thunk_FUN_00267090((hulkfight::PostEvent_StringTrack*)p);
    return p;
}

} // namespace fn_facdac2a

// 0x0012db50 FUN_0012db50 (65 B): matches/0x0012db50.cpp [wrapped: conflict: PostEvent_StringAction]
// sym: ?Build@PostEvent_StringAction@fn_0012db50@@QAEPAU12@HPAUObj_12db50@2@@Z
namespace fn_0012db50 {
struct Obj_12db50 {
    virtual void F();
    virtual void R();
};
extern int PostEvent_StringAction_vftable;
struct PostEvent_StringAction {
    void* vf;
    int pad[6];
    int arg;
    Obj_12db50* object;
    void Init_00232660();
    PostEvent_StringAction* Build(int, Obj_12db50*);
};
PostEvent_StringAction* PostEvent_StringAction::Build(int a, Obj_12db50* p) {
    Init_00232660();
    vf = &PostEvent_StringAction_vftable;
    object = 0;
    arg = a;
    if (p)
        p->F();
    if (object)
        object->R();
    object = p;
    return this;
}
} // namespace fn_0012db50


// 0x0012dba0 FUN_0012dba0 (36 B): matches/0x0012dba0.cpp
// sym: ?FUN_0012dba0@PostEvent_StringAction@hulkfight@@QAEXXZ
void hulkfight::PostEvent_StringAction::FUN_0012dba0() {
    *(void**)this = (void*)((hulk_intptr)DAT_00411110);
    _ReadWriteBarrier();
    if ((*(Ref_12dba0 * *)&this->f_20)) {
        (*(Ref_12dba0 * *)&this->f_20)->Release();
        (*(Ref_12dba0 * *)&this->f_20) = 0;
    }
    ((PostEvent_StringAction_nv_12dba0*)this)->Finish_002326a0();
}


// 0x0012dbf0 fight::ParamFloatConstRange<hulkfight::PostEvent_StringTrack>::vfunc_6 (26 B): matches/0x0012dbf0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VPostEvent_StringTrack@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::PostEvent_StringTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::PostEvent_StringTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::PostEvent_StringTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::PostEvent_StringTrack>::**)(int))&this->f_10))(b);
}


// 0x0012dc10 fight::ParamFloatConstRange<hulkfight::PostEvent_StringTrack>::vfunc_2 (11 B): matches/0x0012dc10.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VPostEvent_StringTrack@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::PostEvent_StringTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0012dc40 fight::ParamBool<hulkfight::PostEvent_StringTrack>::vfunc_6 (26 B): matches/0x0012dc40.cpp
// sym: ?vfunc_6@?$ParamBool@VPostEvent_StringTrack@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::PostEvent_StringTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::PostEvent_StringTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::PostEvent_StringTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::PostEvent_StringTrack>::**)(int))&this->f_10))(b);
}


// 0x0012dc60 fight::ParamBool<hulkfight::PostEvent_StringTrack>::vfunc_2 (11 B): matches/0x0012dc60.cpp
// sym: ?vfunc_2@?$ParamBool@VPostEvent_StringTrack@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::PostEvent_StringTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0012dc80 fight::TrackFactoryCasterTemplate<hulkfight::PostEvent_StringTrack>::vfunc_0 (36 B): matches/0x0012dc80.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VPostEvent_StringTrack@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::PostEvent_StringTrack>::vfunc_0(void* __p0) { int a = (int)__p0;

    int result = FUN_00344e74(a, 0, (hulk_intptr)&DAT_0049850c, (hulk_intptr)&DAT_004a9b10, 0);
    return result != 0;
}


// 0x0012dcb0 fight::ParamFloatConstRange<hulkfight::PostEvent_StringTrack>::vfunc_0 (30 B): matches/0x0012dcb0.cpp
// sym: ??_G?$ParamFloatConstRange@VPostEvent_StringTrack@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::PostEvent_StringTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::PostEvent_StringTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x12dcb0)
#endif


// 0x0012dcd0 fight::ParamBool<hulkfight::PostEvent_StringTrack>::vfunc_0 (30 B): matches/0x0012dcd0.cpp
// sym: ??_G?$ParamBool@VPostEvent_StringTrack@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::PostEvent_StringTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::PostEvent_StringTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x12dcd0)
#endif


// 0x0012dcf0 hulkfight::PostEvent_StringTrack::vfunc_10 (86 B): matches/0x0012dcf0.cpp
// sym: ?vfunc_10@PostEvent_StringTrack@hulkfight@@UAEHHHH@Z
hulk_intptr hulkfight::PostEvent_StringTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr __p2) { Ref_12dcf0 * param = (Ref_12dcf0 *)__p2;

    char* p = (char*)Alloc_0008d690(0x24);
    if (p) {
        ((Memory_12dcf0*)p)->Init_00232660();
        *(void**)(p + 0x1c) = this;
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_00411110);
        *(unsigned int*)(p + 0x20) = 0;
        if (param)
            param->f0();
        Ref_12dcf0* old = *(Ref_12dcf0**)(p + 0x20);
        if (old)
            old->f1();
        *(Ref_12dcf0**)(p + 0x20) = param;
        return (hulk_intptr)(p);
    }
    return (int)(0);
}

namespace fn_facdac2a {

// 0x0012dd50 hulkfight::PostEvent_StringAction::vfunc_2 (57 B): matches/0x0012dd50.cpp
// sym: ?f2@PostEvent_StringAction_12dd50@fn_facdac2a@@QAEPAV12@E@Z
PostEvent_StringAction_12dd50* PostEvent_StringAction_12dd50::f2(unsigned char flags) {
    vptr = hulk_at_00411110;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_12dd50 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x0012ddd0 fight::ParamName<hulkfight::PostEvent_StringTrack>::vfunc_7 (12 B): matches/0x0012ddd0.cpp
// sym: ?vfunc_6@ParamBranch@fn_facdac2a@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_facdac2a

// 0x0012dde0 fight::ParamName<hulkfight::PostEvent_StringTrack>::vfunc_0 (30 B): matches/0x0012dde0.cpp
// sym: ??_G?$ParamName@VPostEvent_StringTrack@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::PostEvent_StringTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::PostEvent_StringTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x12dde0)
#endif

namespace fn_facdac2a {

// 0x0012de00 FUN_0012de00 (38 B): matches/0x0012de00.cpp
// sym: _FUN_0012de00
extern "C" void __cdecl FUN_0012de00(Obj* obj, void* key) {
    TrackFactoryCasterTemplate_12de00 caster;
    obj->Use_002367c0(FUN_00236ac0(key, &caster));
}

} // namespace fn_facdac2a

// 0x0012de30 FUN_0012de30 (256 B): matches/0x0012de30.cpp [wrapped: conflict: fight::ParamBool; fight::ParamFloatConstRange; fight::ParamName]
// sym: _FUN_0012de30
namespace fn_0012de30 {

void* __cdecl FUN_0008d690(unsigned int);
void __cdecl FUN_0012d920();
void __cdecl FUN_0012d930();
void __cdecl FUN_0012d950();
void __cdecl FUN_0012d970();
struct FUN_00234960 {
    FUN_00234960(const char* s = "timeBegin");
    virtual void slot0();
    char pad[12];
    void(__cdecl* callback)();
    char tail[4];
};
struct FUN_00234a90 {
    FUN_00234a90(const char* s = "text");
    virtual void slot0();
    char pad[12];
    void(__cdecl* callback)();
    char tail[4];
};
struct FUN_00234860 {
    FUN_00234860(const char* s = "onlyInTutorialMode");
    virtual void slot0();
    char pad[12];
    void(__cdecl* callback)();
    char tail[4];
};
namespace hulkfight {
class PostEvent_StringTrack;
}
namespace fight {
template <class T> struct ParamFloatConstRange : FUN_00234960 {
    virtual void slot0();
};
template <class T> struct ParamName : FUN_00234a90 {
    virtual void slot0();
};
template <class T> struct ParamBool : FUN_00234860 {
    virtual void slot0();
    ParamBool(const char* s = "onlyInTutorialMode") : FUN_00234860(s) {}
};
} // namespace fight

extern "C" void __cdecl FUN_002347b0(int*, void**, int);
extern "C" void FUN_0012de30() {
    if (DAT_004e0e48 == 0) {
        void* items[4];
        void* p = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<hulkfight::PostEvent_StringTrack>));
        if (p) {
            fight::ParamFloatConstRange<hulkfight::PostEvent_StringTrack>* a =
                new (p) fight::ParamFloatConstRange<hulkfight::PostEvent_StringTrack>;
            a->callback = FUN_0012d920;
            items[0] = a;
        } else
            items[0] = 0;
        p = FUN_0008d690((int)sizeof(fight::ParamName<hulkfight::PostEvent_StringTrack>));
        if (p) {
            fight::ParamName<hulkfight::PostEvent_StringTrack>* a =
                new (p) fight::ParamName<hulkfight::PostEvent_StringTrack>;
            a->callback = FUN_0012d930;
            items[1] = a;
        } else
            items[1] = 0;
        p = FUN_0008d690((int)sizeof(fight::ParamBool<hulkfight::PostEvent_StringTrack>));
        if (p) {
            fight::ParamBool<hulkfight::PostEvent_StringTrack>* a =
                new (p) fight::ParamBool<hulkfight::PostEvent_StringTrack>("onlyInTutorialMode");
            a->callback = FUN_0012d950;
            items[2] = a;
        } else
            items[2] = 0;
        p = FUN_0008d690((int)sizeof(fight::ParamBool<hulkfight::PostEvent_StringTrack>));
        if (p) {
            fight::ParamBool<hulkfight::PostEvent_StringTrack>* a =
                new (p) fight::ParamBool<hulkfight::PostEvent_StringTrack>("unique");
            a->callback = FUN_0012d970;
            items[3] = a;
        } else
            items[3] = 0;
        FUN_002347b0(&DAT_004e0e44, items, 4);
    }
    ++DAT_004e0e48;
}
} // namespace fn_0012de30


// 0x0012df30 fight::TrackFactoryCasterTemplate<hulkfight::PostEvent_StringTrack>::vfunc_1 (60 B): matches/0x0012df30.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VPostEvent_StringTrack@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::PostEvent_StringTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_12df30));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_12df30* t = new (mem) TrackFactoryTemplate_12df30();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        FUN_0012de30();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0012df70 fight::TrackFactoryTemplate<hulkfight::PostEvent_StringTrack>::vfunc_5 (61 B): matches/0x0012df70.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VPostEvent_StringTrack@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::PostEvent_StringTrack>::vfunc_5() {
    char* p = (char*)FUN_0008d690(0x20);
    if (p) {
        ((Helper_12df70*)p)->FUN_00236d40();
        *(void**)p = &PostEvent_StringTrack_vtable;
        *(unsigned int*)(p + 0xc) = 0;
        ((SubHelper*)(p + 0x10))->FUN_0027af00();
        p[0x18] = 0;
        p[0x19] = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_facdac2a {

// 0x0012dfb0 fight::TrackFactoryTemplate<hulkfight::PostEvent_StringTrack>::vfunc_2 (43 B): matches/0x0012dfb0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_facdac2a@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_004111b8;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_facdac2a
