// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000fdab0..0x000ff230 (kind game, layer game, confidence high), dominant class CCharacterGolem
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x000febc0 FUN_000febc0 (158 B): matches/0x000febc0.cpp [isolated: compile error C2664: 'fn_000febc0::Owner_febc0::Find' : cannot convert parameter 1 from 'const type_info' to 'const fn_000febc0::type_info &']
// sym: ?FUN_000febc0@@YAXPAVOwner_febc0@@PAPAVCPathAgent@@@Z
class type_info;
class CAgent {
  public:
    virtual void F();
    virtual void D();
};
// the game's classes (RTTI 0x004a19e0 CAgent, 0x004a1bc0 CPathAgent): typeid and dynamic_cast compare them by name
class CPathAgent : public CAgent {};
class Owner_febc0 {
  public:
    CAgent* Find_000fdd30(const type_info&);
};
class CPathAgent_febc0 {
  public:
    CPathAgent* Make_001047b0(Owner_febc0*);
};
extern "C" void* __cdecl FUN_00266da0(hulk_intptr);
extern "C" void* __cdecl FUN_0008d690(int);
void __cdecl FUN_000febc0(Owner_febc0* owner, CPathAgent** out) {
    CAgent* p = owner->Find_000fdd30(typeid(CPathAgent));
    if (p) {
        CPathAgent* q = dynamic_cast<CPathAgent*>(p);
        if (q)
            q->F();
        if (*out)
            (*out)->D();
        *out = q;
    }
    if (!*out) {
        void* b = FUN_00266da0(0xc);
        void* a = FUN_0008d690(0xfc);
        CPathAgent* q;
        if (a)
            q = ((CPathAgent_febc0*)a)->Make_001047b0(owner);
        else
            q = 0;
        if (q)
            q->F();
        if (*out)
            (*out)->D();
        *out = q;
        FUN_00266da0((hulk_intptr)b);
    }
}

