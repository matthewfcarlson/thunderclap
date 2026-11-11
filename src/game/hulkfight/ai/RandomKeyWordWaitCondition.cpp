// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0010db80..0x0010dcf0 (kind game, layer game, confidence medium), dominant class hulkfight::ai::RandomKeyWordWaitCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f0e089ff {
#define TREE_TU_END }
namespace fn_f0e089ff {} using namespace fn_f0e089ff;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
namespace fn_f0e089ff {
extern void* __fastcall FUN_000592a0(void*);
extern "C" void __fastcall FUN_00059a30(void*);
extern void* FUN_000678d0();
extern void __fastcall FUN_00067730(void*);
extern void* __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
extern const int hulk_at_00494b44;
extern const int hulk_at_00494b60;
struct Holder_10dbb0 {
    char pad[0x14];
    Holder_10dbb0* next;
};
struct Sub_10dbb0 {
    Holder_10dbb0* h;
    bool Valid_00231ee0();
};
struct Owner_10dbb0 {
    char pad[0xb4];
    Sub_10dbb0 sub;
};
struct Mid_10dbb0 {
    Owner_10dbb0* GetOwner_00059a30();
};
struct P_10dbb0 {
};
extern TypeDescriptor DAT_00494b44;
extern TypeDescriptor DAT_00494b60;
extern "C" void* __cdecl FUN_00344e74(void*, int, TypeDescriptor*, TypeDescriptor*, int);
struct State_10dc30 { char pad[0x39c]; int value; };
struct Context_10dc30 { State_10dc30* FUN_00059a30(); };
struct Actor_10dc30 {  };

} // namespace fn_f0e089ff

// 0x0010db80 hulkfight::ai::HulkAction::vfunc_5 (40 B): matches/0x0010db80.cpp
// sym: ?vfunc_5@HulkAction@ai@hulkfight@@UAE_NHH@Z
bool hulkfight::ai::HulkAction::vfunc_5(hulk_intptr arg, int unused) {
    if (arg == 0) {
        void* p = FUN_000592a0(*(void**)((char*)this + 0x20));
        FUN_00059a30(p);
        p = FUN_000678d0();
        FUN_00067730(p);
    }
    return true;
}


// 0x0010dbb0 hulkfight::ai::AIFightNodeCondition::vfunc_6 (121 B): matches/0x0010dbb0.cpp
// sym: ?vfunc_6@AIFightNodeCondition@ai@hulkfight@@UAE_NPAX00@Z
bool hulkfight::ai::AIFightNodeCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { P_10dbb0 * p = (P_10dbb0 *)__p1;

    if (FUN_00344e74(p, 0, &hulk_at_00494b44, &hulk_at_00494b60, 0)) {
        Owner_10dbb0* o = ((Mid_10dbb0 *)((owners::Object_592a0 *)p)->FUN_000592a0())->GetOwner_00059a30();
        if (o) {
            Holder_10dbb0* n = (*(Holder_10dbb0 * *)&this->f_0c);
            if (n) {
                Sub_10dbb0* s = &o->sub;
                if (s) {
                    Holder_10dbb0* h = s->h;
                    if (h) {
                        if (s->Valid_00231ee0()) {
                            Holder_10dbb0* c = h->next;
                            while (c) {
                                if (c == n)
                                    return true;
                                c = c->next;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}


// 0x0010dc30 hulkfight::ai::RandomKeyWordWaitCondition::vfunc_6 (168 B): equivalent/0x0010dc30.cpp
// sym: ?vfunc_6@RandomKeyWordWaitCondition@ai@hulkfight@@UAE_NPAX00@Z @18c8c470b64c @wc47f5e13d44d
// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 24/24)
// hulkfight::ai::RandomKeyWordWaitCondition::vfunc_6 @ 0x0010dc30
bool hulkfight::ai::RandomKeyWordWaitCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { Actor_10dc30 * actor = (Actor_10dc30 *)__p1;

 if (!FUN_00344e74(actor,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 State_10dc30* state = ((Context_10dc30 *)((owners::Object_592a0 *)actor)->FUN_000592a0())->FUN_00059a30();
 if (!state) return false;
 int value = state->value;
 switch((*(unsigned int *)&this->f_0c)) {
 case 0: return value < this->f_10;
 case 1: return value <= this->f_10;
 case 2: return value == this->f_10;
 case 3: return value != this->f_10;
 case 4: return value >= this->f_10;
 case 5: return value > this->f_10;
 default: return false;
 }
}

