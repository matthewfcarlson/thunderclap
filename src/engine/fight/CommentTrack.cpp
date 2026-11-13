// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0023d810..0x0023df40 (kind game, layer engine, confidence high), dominant class fight::CommentTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/fight.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f40d2254 {
#define TREE_TU_END }
namespace fn_f40d2254 {} using namespace fn_f40d2254;
namespace fn_f40d2254 {
struct FactoryCtor { void init_002343b0(); void init_00236a90(); };   // (unb4) the factory constructors InitHelper::init stood for
void thunk_delete_00263f30(void*);   // (unb4) the `jmp` thunk to free this TU's thunk_delete reaches
}
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f40d2254 {
extern "C" void FUN_00234810(void*, void*);
extern int* hulk_at_004e5c5c;
class CCondition_23d830 {
  public:
    virtual int vfunc_0(int);
};
class CommentCondition_23d860 {
  public:
    int a, b;
    virtual ~CommentCondition_23d860();
    int d;
    virtual bool hulk_slot_F_00234270(void*); void FnF_002345b0();
};
extern "C" void __cdecl FreeMem_0008d340(void*);
extern int* hulk_at_004e5c64;
class CCondition_23d900 {
  public:
    virtual int vfunc_0(int);
};
class Track {
  public:
    Track();
    virtual void f();
    char pad[4];
};
class CommentTrack : public Track {
  public:
    CommentTrack();
    virtual void f();
    int a;
    int b;
};
class CommentTrack_23d950 {
  public:
    int a, b;
    virtual ~CommentTrack_23d950();
    int d;
    virtual bool hulk_slot_F_00234270(void*); void FnF_00236d60();
};
extern "C" void __cdecl release(void*);
extern "C" void* __cdecl FUN_0008d6d0(unsigned int);
class Obj {
  public:
    char _m_pad_0[0xc];
    char* str;
    char Set(const char* s);
    void use_00236760(void*);
};
inline void copy(char* d, const char* s) {
    char c;
    do {
        c = *s;
        ++s;
        *d = c;
        ++d;
    } while (c);
}
extern const VFT hulk_at_00428bf8;
class CommentCondition_23dab0 {
  public:
    virtual void vfunc_0();
    virtual void p_vfunc_1();
    virtual void p_vfunc_2();
    virtual void c_vfunc_3();
    virtual void p_vfunc_4();
    void* vfunc_5(unsigned char flag);
    virtual void vfunc_6();
    void Cleanup_002345b0();
    char pad[8];
    void* m_p;
};
extern const VFT hulk_at_00428c18;
class CommentTrack_23daf0 {
  public:
    virtual void vfunc_0();
    virtual void p_vfunc_1();
    virtual void p_vfunc_2();
    virtual void c_vfunc_3();
    virtual void p_vfunc_4();
    void* vfunc_5(unsigned char flag);
    virtual void vfunc_6();
    void Cleanup_00236d60();
    char pad[8];
    void* m_p;
};
class CStageCondition_23db70;
class ParamValue_23db70 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_23db70 : public ParamValue_23db70 {
  public:
    int pad;
};
class CStageCondition_23dbc0;
class ParamValue_23dbc0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_23dbc0 : public ParamValue_23dbc0 {
  public:
    int pad;
};
extern int hulk_at_00491ca8;
extern int hulk_at_0049850c;
class ConditionFactoryCasterTemplate_23dd90 {
  public:
    virtual bool cast_0023dbe0(void*);
};
extern "C" void* lookup(void*, ConditionFactoryCasterTemplate_23dd90*);
} // namespace fn_f40d2254
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_f40d2254 {
class TrackFactoryTemplate_23ddf0 {
  public:
    TrackFactoryTemplate_23ddf0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" char DAT_00428bf8[];
extern void* __cdecl alloc_0008d690(unsigned int);
class CommentCondition_23de30 {
  public:
    hulk_intptr vtable;
    char pad[8];
    int value;
    void Init_00234590(int);
};
extern int hulk_at_00428ca0;
struct ConditionFactoryTemplate_23de60 {
    void* m_vptr;
    void base1_dtor_0023d810();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
class TrackFactoryTemplate_23de90 {
  public:
    TrackFactoryTemplate_23de90() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern int hulk_at_00428cbc;


// 0x0023d810 FUN_0023d810 (19 B): matches/0x0023d810.cpp
// sym: ?FUN_0023d810@fn_f40d2254@@YAXPAX@Z
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0023d810(void* /*this, unused: callers pass it (unb4)*/) {
    FUN_00234810(((char*)&DAT_004e5c5c), ((char*)&DAT_004e5c60));
}

} // namespace fn_f40d2254

// 0x0023d830 fight::CommentCondition::vfunc_0 (16 B): matches/0x0023d830.cpp
// sym: ?vfunc_0@CommentCondition@fight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr fight::CommentCondition::vfunc_0(int index) {
    int* p = hulk_at_004e5c5c;
    return p[index];
}

namespace fn_f40d2254 {

// 0x0023d860 FUN_0023d860 (29 B): matches/0x0023d860.cpp
// sym: ??1CommentCondition_23d860@fn_f40d2254@@UAE@XZ
// Same code shape as 0x0011c270 (propagated; names are from that function)
CommentCondition_23d860::~CommentCondition_23d860() {
    Cleanup(d);
    FnF_002345b0();
}

} // namespace fn_f40d2254

// 0x0023d880 FUN_0023d880 (82 B): matches/0x0023d880.cpp
// sym: ?FUN_0023d880@Obj_23d880@owners@@QAEDPBD@Z
char owners::Obj_23d880::FUN_0023d880(const char* s) {
    FreeMem_0008d340(text);
    if (!s) {
        text = 0;
        return 1;
    }
    text = (char*)AllocMem(strlen(s) + 1);
    strcpy(text, s);
    return 1;
}

namespace fn_f40d2254 {

// 0x0023d8e0 FUN_0023d8e0 (19 B): matches/0x0023d8e0.cpp
// sym: ?FUN_0023d8e0@fn_f40d2254@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0023d8e0() {
    FUN_00234810(((char*)&DAT_004e5c64), ((char*)&DAT_004e5c68));
}

} // namespace fn_f40d2254

// 0x0023d900 fight::CommentTrack::vfunc_0 (16 B): matches/0x0023d900.cpp
// sym: ?vfunc_0@CommentTrack@fight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr fight::CommentTrack::vfunc_0(int index) {
    int* p = hulk_at_004e5c64;
    return p[index];
}

namespace fn_f40d2254 {

// 0x0023d910 FUN_0023d910 (32 B): matches/0x0023d910.cpp
// sym: ??0CommentTrack@fn_f40d2254@@QAE@XZ
CommentTrack::CommentTrack() : Track() {
    b = 0;
    a = 1;
}

} // namespace fn_f40d2254

// 0x0023d930 fight::CommentTrack::vfunc_6 (7 B): matches/0x0023d930.cpp
// sym: ?vfunc_6@CommentTrack@fight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg fight::CommentTrack::vfunc_6() {
    return DAT_003f32e0;
}


// 0x0023d940 fight::CommentTrack::vfunc_7 (7 B): matches/0x0023d940.cpp
// sym: ?vfunc_7@CommentTrack@fight@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg fight::CommentTrack::vfunc_7() {
    return DAT_003f32e0;
}

namespace fn_f40d2254 {

// 0x0023d950 FUN_0023d950 (29 B): matches/0x0023d950.cpp
// sym: ??1CommentTrack_23d950@fn_f40d2254@@UAE@XZ
// Same code shape as 0x0011c270 (propagated; names are from that function)
CommentTrack_23d950::~CommentTrack_23d950() {
    Cleanup(d);
    FnF_00236d60();
}


// 0x0023d970 FUN_0023d970 (82 B): matches/0x0023d970.cpp
// sym: ?Set@Obj@fn_f40d2254@@QAEDPBD@Z
char Obj::Set(const char* s) {
    release(str);
    if (!s) {
        str = (char*)s;
        return 1;
    }
    str = (char*)FUN_0008d6d0(strlen(s) + 1);
    copy(str, s);
    return 1;
}

} // namespace fn_f40d2254

// 0x0023d9d0 fight::CommentCondition::vfunc_6 (5 B): matches/0x0023d9d0.cpp
// sym: ?vfunc_6@CommentCondition@fight@@UAE_NPAX00@Z
// Same code shape as 0x0012fb00 (propagated; names are from that function)
bool fight::CommentCondition::vfunc_6(void* __p0, void* __p1, void* __p2) {
    return true;
}


// 0x0023d9e0 fight::CommentTrack::vfunc_10 (5 B): matches/0x0023d9e0.cpp
// sym: ?vfunc_10@CommentTrack@fight@@UAEHHHH@Z
hulk_intptr fight::CommentTrack::vfunc_10(hulk_intptr , hulk_intptr , hulk_intptr ) {
    return 0;
}

namespace fn_f40d2254 {

// 0x0023dab0 fight::CommentCondition::vfunc_5 (50 B): matches/0x0023dab0.cpp
// sym: ?vfunc_5@CommentCondition_23dab0@fn_f40d2254@@QAEPAXE@Z
// Same code shape as 0x0011cbc0 (propagated; names are from that function)
void* CommentCondition_23dab0::vfunc_5(unsigned char flag) {
    *(const VFT**)this = &hulk_at_00428bf8;
    ai_free(m_p);
    Cleanup_002345b0();
    if (flag & 1) {
        ai_delete(this);
    }
    return this;
}


// 0x0023daf0 fight::CommentTrack::vfunc_5 (50 B): matches/0x0023daf0.cpp
// sym: ?vfunc_5@CommentTrack_23daf0@fn_f40d2254@@QAEPAXE@Z
// Same code shape as 0x0011cbc0 (propagated; names are from that function)
void* CommentTrack_23daf0::vfunc_5(unsigned char flag) {
    *(const VFT**)this = &hulk_at_00428c18;
    ai_free(m_p);
    Cleanup_00236d60();
    if (flag & 1) {
        ai_delete(this);
    }
    return this;
}

} // namespace fn_f40d2254

// 0x0023db50 fight::ParamString<fight::CommentCondition>::vfunc_6 (26 B): matches/0x0023db50.cpp
// sym: ?vfunc_6@?$ParamString@VCommentCondition@fight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamString<fight::CommentCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamString<fight::CommentCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<fight::CommentCondition>*)a)->*(*(bool (fight::ParamString<fight::CommentCondition>::**)(int))&this->f_10))(b);
}


// 0x0023db70 fight::ParamString<fight::CommentCondition>::vfunc_2 (11 B): matches/0x0023db70.cpp
// sym: ?vfunc_2@?$ParamString@VCommentCondition@fight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamString<fight::CommentCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0023dba0 fight::ParamString<fight::CommentTrack>::vfunc_6 (26 B): matches/0x0023dba0.cpp
// sym: ?vfunc_6@?$ParamString@VCommentCondition@fight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamString<fight::CommentTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamString<fight::CommentTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<fight::CommentTrack>*)a)->*(*(bool (fight::ParamString<fight::CommentTrack>::**)(int))&this->f_10))(b);
}


// 0x0023dbc0 fight::ParamString<fight::CommentTrack>::vfunc_2 (11 B): matches/0x0023dbc0.cpp
// sym: ?vfunc_2@?$ParamString@VCommentCondition@fight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamString<fight::CommentTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x0023dbe0 fight::ConditionFactoryCasterTemplate<fight::CommentCondition>::vfunc_0 (36 B): matches/0x0023dbe0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VCommentCondition@fight@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::ConditionFactoryCasterTemplate<fight::CommentCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&hulk_at_00491ca8, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x0023dc10 fight::ParamString<fight::CommentCondition>::vfunc_0 (30 B): matches/0x0023dc10.cpp
// sym: ??_G?$ParamString@VCommentCondition@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamString<fight::CommentCondition>::~ParamString() {}
#if defined(HULK_PTR64)
template class fight::ParamString<fight::CommentCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x23dc10)
#endif


// 0x0023dc40 fight::TrackFactoryCasterTemplate<fight::CommentTrack>::vfunc_0 (36 B): matches/0x0023dc40.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VCommentTrack@fight@@@fight@@UAE_NPAX@Z
// Same code shape as 0x000508c0 (propagated; names are from that function)
template <> bool fight::TrackFactoryCasterTemplate<fight::CommentTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74((hulk_intptr)p, 0, (hulk_intptr)&hulk_at_0049850c, (hulk_intptr)&gTypeB, 0) != 0;
}


// 0x0023dc70 fight::ParamString<fight::CommentTrack>::vfunc_0 (30 B): matches/0x0023dc70.cpp
// sym: ??_G?$ParamString@VCommentTrack@fight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamString<fight::CommentTrack>::~ParamString() {}
#if defined(HULK_PTR64)
template class fight::ParamString<fight::CommentTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x23dc70)
#endif

namespace fn_f40d2254 {

// 0x0023dd90 FUN_0023dd90 (38 B): matches/0x0023dd90.cpp
// sym: _FUN_0023dd90
extern "C" void FUN_0023dd90(Obj* a, void* b) {
    ConditionFactoryCasterTemplate_23dd90 caster;
    a->use_00236760(lookup(b, &caster));
}

} // namespace fn_f40d2254

// 0x0023ddc0 FUN_0023ddc0 (38 B): matches/0x0023ddc0.cpp [wrapped: conflict: Track]
// sym: _FUN_0023ddc0
namespace fn_0023ddc0 {
extern char hulk_at_00428c94[];
struct Track {
    virtual void V();
};
extern "C" Track* __cdecl FUN_00236ac0(int, Track*);
struct Receiver_23ddc0 {
    void Finish_002367c0(Track*);
};
extern "C" void FUN_0023ddc0(Receiver_23ddc0* c, int b) {
    Track t;
    *(void**)&t = hulk_at_00428c94;
    Track* p = FUN_00236ac0(b, &t);
    c->Finish_002367c0(p);
}
} // namespace fn_0023ddc0


// 0x0023ddf0 fight::ConditionFactoryCasterTemplate<fight::CommentCondition>::vfunc_1 (60 B): matches/0x0023ddf0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VCommentCondition@fight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<fight::CommentCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_23ddf0));
    if (mem) {
        ((FactoryCtor*)mem)->init_002343b0();
        TrackFactoryTemplate_23ddf0* t = new (mem) TrackFactoryTemplate_23ddf0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0023de30 fight::ConditionFactoryTemplate<fight::CommentCondition>::vfunc_5 (47 B): matches/0x0023de30.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VCommentCondition@fight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<fight::CommentCondition>::vfunc_5() {
    CommentCondition_23de30* p = (CommentCondition_23de30*)alloc_0008d690(0x10);
    if (p) {
        p->Init_00234590(3);
        p->vtable = ((hulk_intptr)DAT_00428bf8);
        p->value = 0;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f40d2254 {

// 0x0023de60 fight::ConditionFactoryTemplate<fight::CommentCondition>::vfunc_2 (43 B): matches/0x0023de60.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_23de60@fn_f40d2254@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_23de60::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00428ca0;
    base1_dtor_0023d810();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f40d2254

// 0x0023de90 fight::TrackFactoryCasterTemplate<fight::CommentTrack>::vfunc_1 (60 B): matches/0x0023de90.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VCommentTrack@fight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<fight::CommentTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_23de90));
    if (mem) {
        ((FactoryCtor*)mem)->init_00236a90();
        TrackFactoryTemplate_23de90* t = new (mem) TrackFactoryTemplate_23de90();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x0023ded0 fight::TrackFactoryTemplate<fight::CommentTrack>::vfunc_5 (52 B): matches/0x0023ded0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?vfunc_5@TrackFactoryTemplate@fight@fn_0023ded0@@UAEPAVTrack@23@XZ
void* operator new(size_t);
namespace fn_0023ded0 {
/* size_t: tree_prelude.h */

namespace fight {
class Track {
  public:
    Track() throw();
    virtual void f0();
    char pad[4];
    int a;
    int b;
};
class CommentTrack : public Track {
  public:
    CommentTrack() throw();
    virtual void f0();
};
class TrackFactoryTemplate {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual Track* vfunc_5();
};
Track* TrackFactoryTemplate::vfunc_5() {
    return new CommentTrack;
}
CommentTrack::CommentTrack() throw() : Track() {
    b = 0;
    a = 1;
}
} // namespace fight
} // namespace fn_0023ded0

namespace fn_f40d2254 {

// 0x0023df10 fight::TrackFactoryTemplate<fight::CommentTrack>::vfunc_2 (43 B): matches/0x0023df10.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_f40d2254@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_00428cbc;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}

} // namespace fn_f40d2254
