#include "compat/ptr.h"
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
    CAgent* Find(const type_info&);
};
class CPathAgent_febc0 {
  public:
    CPathAgent* Make(Owner_febc0*);
};
extern "C" void* __cdecl FUN_00266da0(hulk_intptr);
extern "C" void* __cdecl FUN_0008d690(int);
void __cdecl FUN_000febc0(Owner_febc0* owner, CPathAgent** out) {
    CAgent* p = owner->Find(typeid(CPathAgent));
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
            q = ((CPathAgent_febc0*)a)->Make(owner);
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
