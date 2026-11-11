// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00022020..0x000220e0 (kind game, layer game, confidence medium), dominant class CSmartPropRemoveInstanceAction
#include "tree_prelude.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f513c711 {
#define TREE_TU_END }
namespace fn_f513c711 {} using namespace fn_f513c711;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f513c711 {
extern int CAction_vftable;
class Ref_22020 {
  public:
    virtual void a();
    virtual void b();
};
class CSmartPropDropAction {
  public:
    int* vptr;
    char pad[0x18];
    Ref_22020* member;
    void cleanup();
    CSmartPropDropAction* vfunc_2(int);
};
void __cdecl thunk_FUN_00267090(CSmartPropDropAction*);
extern void* g_vftable_22060[];
class Ref_22060 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_22060 {
  public:
    void* vptr;
};
class CSmartPropEventAction_22060 : public CAction_22060 {
  public:
    char pad[0x1c - 4];
    Ref_22060* m;
    CSmartPropEventAction_22060* f2(unsigned char flags);
};
extern void* g_vftable_220a0[];
class Ref_220a0 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_220a0 {
  public:
    void* vptr;
};
class CSmartPropRemoveInstanceAction_220a0 : public CAction_220a0 {
  public:
    char pad[0x1c - 4];
    Ref_220a0* m;
    CSmartPropRemoveInstanceAction_220a0* f2(unsigned char flags);
};


// 0x00022020 CSmartPropDropAction::vfunc_2 (57 B): matches/0x00022020.cpp
// sym: ?vfunc_2@CSmartPropDropAction@fn_f513c711@@QAEPAV12@H@Z
CSmartPropDropAction* CSmartPropDropAction::vfunc_2(int flag) {
    vptr = &CAction_vftable;
    _ReadWriteBarrier();
    if (member) {
        member->b();
        member = 0;
    }
    cleanup();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}


// 0x00022060 CSmartPropEventAction::vfunc_2 (57 B): matches/0x00022060.cpp
// sym: ?f2@CSmartPropEventAction_22060@fn_f513c711@@QAEPAV12@E@Z
CSmartPropEventAction_22060* CSmartPropEventAction_22060::f2(unsigned char flags) {
    vptr = g_vftable_22060;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(CAction_22060 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x000220a0 CSmartPropRemoveInstanceAction::vfunc_2 (57 B): matches/0x000220a0.cpp
// sym: ?f2@CSmartPropRemoveInstanceAction_220a0@fn_f513c711@@QAEPAV12@E@Z
CSmartPropRemoveInstanceAction_220a0* CSmartPropRemoveInstanceAction_220a0::f2(unsigned char flags) {
    vptr = g_vftable_220a0;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(CAction_220a0 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_f513c711
