// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00236940..0x00236a90 (kind game, layer engine, confidence medium), dominant class fight::Params
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_f44dc5d7 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f44dc5d7 {} using namespace fn_f44dc5d7;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f44dc5d7 {
extern "C" void __cdecl FUN_0023dd90(void*, const char*);
extern "C" void __cdecl FUN_0023d710(void*, const char*);
extern "C" void __cdecl FUN_0023d420(void*, const char*);
extern "C" void __cdecl FUN_0023d250(void*, const char*);
extern "C" void __cdecl FUN_0023d220(void*, const char*);
extern "C" void __cdecl FUN_0023ce00(void*, const char*);
extern "C" void __cdecl FUN_002391d0(void*, const char*);
extern "C" void __cdecl FUN_002386e0(void*, const char*);
extern "C" void __cdecl FUN_002386b0(void*, const char*);
extern "C" void __cdecl FUN_0023ca70(void*, const char*);
extern "C" void FUN_0023f500(void* a, const char* s);
extern "C" void FUN_0023ddc0(void* a, const char* s);
extern "C" void FUN_00239c50(void* a, const char* s);
extern "C" void FUN_00237ab0(void* a, const char* s);
extern "C" void FUN_00239200(void* a, const char* s);
extern "C" void FUN_002380a0(void* a, const char* s);
extern "C" void FUN_0023efe0(void* a, const char* s);
extern "C" void FUN_0023e930(void* a, const char* s);
extern "C" void FUN_0023e3f0(void* a, const char* s);
typedef unsigned int U_236a30;
void FUN_00236940(U_236a30);
extern "C" void __cdecl FUN_002369c0(void *);
extern void* IRefCount_vftable_236a50;
extern "C" char DAT_00427f28[];
class Params {
  public:
    void* x;
    int value;
    Params();
};
class NonCopyable_236a70 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
namespace pure3d {
class NonCopyable : public NonCopyable_236a70 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);


// 0x00236940 FUN_00236940 (123 B): matches/0x00236940.cpp
// sym: ?target@fn_f44dc5d7@@YAXPAXH@Z
void __cdecl target(void* self, int unused) {
    FUN_0023dd90(self, "comment");
    FUN_0023d710(self, "debug");
    FUN_0023d420(self, "false");
    FUN_0023d250(self, "or");
    FUN_0023d220(self, "not");
    FUN_0023ce00(self, "platform");
    FUN_002391d0(self, "print");
    FUN_002386e0(self, "random");
    FUN_002386b0(self, "maybe");
    FUN_0023ca70(self, "subConditionGroup");
}


// 0x002369c0 FUN_002369c0 (112 B): matches/0x002369c0.cpp
// sym: _FUN_002369c0
extern "C" void FUN_002369c0(void* p) {
    FUN_0023f500(p, "breakPoint");
    FUN_0023ddc0(p, "comment");
    FUN_00239c50(p, "execute");
    FUN_00237ab0(p, "opportunity");
    FUN_00239200(p, "print");
    FUN_002380a0(p, "sequence");
    FUN_0023efe0(p, "spawn");
    FUN_0023e930(p, "stop");
    FUN_0023e3f0(p, "wait");
}


// 0x00236a30 FUN_00236a30 (22 B): matches/0x00236a30.cpp
// sym: ?FUN_00236a30@fn_f44dc5d7@@YAXI@Z
void FUN_00236a30(U_236a30 x) {
    FUN_00236940(x);
    FUN_002369c0((void *)(hulk_uintptr)(unsigned int)x);
}


// 0x00236a50 FUN_00236a50 (7 B): matches/0x00236a50.cpp
// sym: ?FUN_00236a50@fn_f44dc5d7@@YIXPAX@Z
// Same code shape as 0x001b6820 (propagated; names are from that function)
void __fastcall FUN_00236a50(void* self) {
    *(void**)self = &IRefCount_vftable_236a50;
}


// 0x00236a60 FUN_00236a60 (16 B): matches/0x00236a60.cpp
// sym: ??0Params@fn_f44dc5d7@@QAE@XZ
Params::Params() : x(0), value(0) {
    x = (void*)((hulk_intptr)DAT_00427f28);
}


// 0x00236a70 fight::Params::vfunc_2 (31 B): matches/0x00236a70.cpp
// sym: ?f2@NonCopyable@pure3d@fn_f44dc5d7@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f44dc5d7
