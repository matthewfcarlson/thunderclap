// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000fdab0..0x000ff230 (kind game, layer game, confidence high), dominant class CCharacterGolem
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"
#include "compat/fixedint.h"


// 0x000febc0 FUN_000febc0 (158 B): matches/0x000febc0.cpp [isolated: compile error C2664: 'fn_000febc0::Owner_febc0::Find' : cannot convert parameter 1 from 'const type_info' to 'const fn_000febc0::type_info &']
// sym: ?FUN_000febc0@@YAXPAVOwner_febc0@@PAPAVCPathAgent@@@Z
class type_info;
// the game's classes (RTTI 0x004a19e0 CAgent, 0x004a1bc0 CPathAgent): gen/global.h's (sweep3: the allocation is its size)
class Owner_febc0 {
  public:
    CAgent* Find_000fdd30(const type_info&);
};
class CPathAgent_febc0 {
  public:
    CPathAgent* Make_001047b0(Owner_febc0*);
};
extern "C" int32_t __cdecl FUN_00266da0(int32_t);   // (x64t16, D70) the heap id: a 32-bit integer
extern "C" void* __cdecl FUN_0008d690(int);
void __cdecl FUN_000febc0(Owner_febc0* owner, CPathAgent** out) {
    CAgent* p = owner->Find_000fdd30(typeid(CPathAgent));
    if (p) {
        CPathAgent* q = dynamic_cast<CPathAgent*>(p);
        if (q)
            q->vfunc_0();
        if (*out)
            (*out)->vfunc_1();
        *out = q;
    }
    if (!*out) {
        int32_t b = FUN_00266da0(0xc);
        void* a = FUN_0008d690((int)sizeof(::CPathAgent));
        CPathAgent* q;
        if (a)
            q = ((CPathAgent_febc0*)a)->Make_001047b0(owner);
        else
            q = 0;
        if (q)
            q->vfunc_0();
        if (*out)
            (*out)->vfunc_1();
        *out = q;
        FUN_00266da0(b);
    }
}

