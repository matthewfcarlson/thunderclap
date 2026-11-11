// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00061e30..0x00068c80 (kind game, layer game, confidence high), dominant class CWeaponCollisionTrack
#include "tree_prelude.h"


// 0x00064660 FUN_00064660 (227 B): matches/0x00064660.cpp [isolated: compile error C2084: function 'void *operator new(size_t,void *)' already has a body]
// sym: _FUN_00064660
#include "gen/owners.h"
#include "decls/data/game/global.h"
namespace fn_fbe5aec6 {} using namespace fn_fbe5aec6;
namespace fn_fbe5aec6 {

void* __cdecl FUN_0008d690(unsigned);

} // namespace fn_fbe5aec6
inline void* __cdecl operator new(size_t, void* p) {
    return p;
}
namespace fn_fbe5aec6 {

void __cdecl SetTimeBegin_00061f70();
void __cdecl SetAttachmentIndex_00061f80();
void __cdecl SetEvent_00061f90();
void __cdecl FUN_002347b0(void*, void**, int);
class CSmartPropEventTrack;
namespace fight {
template <class T> struct ParamIntConstRange {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    char pad[12];
    void(__cdecl* callback)();
    unsigned tail;
    void FUN_002348e0(const char*);
};
template <class T> struct ParamEnumConstList {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    char pad[12];
    unsigned* list;
    unsigned count;
    void(__cdecl* callback)();
    unsigned tail;
    void FUN_00234cc0(const char*);
};
template <class T> struct ParamFloatConstRange {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    char pad[12];
    void(__cdecl* callback)();
    unsigned tail;
    void FUN_00234960(const char*);
};
} // namespace fight
extern "C" void __cdecl FUN_00064660() {
    if (!DAT_004dc664) {
        void* params[3];
        void* mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange<CSmartPropEventTrack>));
        if (mem) {
            fight::ParamIntConstRange<CSmartPropEventTrack>* p =
                (fight::ParamIntConstRange<CSmartPropEventTrack>*)mem;
            p->FUN_002348e0("attachmentIndex");
            p = new (mem) fight::ParamIntConstRange<CSmartPropEventTrack>;
            p->callback = SetAttachmentIndex_00061f80;
            params[0] = p;
        } else
            params[0] = 0;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList<CSmartPropEventTrack>));
        if (mem) {
            fight::ParamEnumConstList<CSmartPropEventTrack>* p =
                (fight::ParamEnumConstList<CSmartPropEventTrack>*)mem;
            p->FUN_00234cc0("event");
            p = new (mem) fight::ParamEnumConstList<CSmartPropEventTrack>;
            p->list = ((unsigned*)&DAT_00496168);
            p->count = 14;
            p->callback = SetEvent_00061f90;
            params[1] = p;
        } else
            params[1] = 0;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<CSmartPropEventTrack>));
        if (mem) {
            fight::ParamFloatConstRange<CSmartPropEventTrack>* p =
                (fight::ParamFloatConstRange<CSmartPropEventTrack>*)mem;
            p->FUN_00234960("timeBegin");
            p = new (mem) fight::ParamFloatConstRange<CSmartPropEventTrack>;
            p->callback = SetTimeBegin_00061f70;
            params[2] = p;
        } else
            params[2] = 0;
        FUN_002347b0(((void**)&DAT_004dc660), params, 3);
    }
    ++DAT_004dc664;
}
} // namespace fn_fbe5aec6

