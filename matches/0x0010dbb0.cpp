#include "gen/hulkfight.h"

extern void* __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
extern const int RTTI_Params_10dbb0;
extern const int RTTI_CFightParams_10dbb0;
struct Holder_10dbb0 {
    char pad[0x14];
    Holder_10dbb0* next;
};
struct Sub_10dbb0 {
    Holder_10dbb0* h;
    bool Valid();
};
struct Owner_10dbb0 {
    char pad[0xb4];
    Sub_10dbb0 sub;
};
struct Mid_10dbb0 {
    Owner_10dbb0* GetOwner();
};
struct P_10dbb0 {
    Mid_10dbb0* GetMid();
};

bool hulkfight::ai::AIFightNodeCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { P_10dbb0 * p = (P_10dbb0 *)__p1;

    if (FUN_00344e74(p, 0, &RTTI_Params_10dbb0, &RTTI_CFightParams_10dbb0, 0)) {
        Owner_10dbb0* o = p->GetMid()->GetOwner();
        if (o) {
            Holder_10dbb0* n = (*(Holder_10dbb0 * *)&this->f_0c);
            if (n) {
                Sub_10dbb0* s = &o->sub;
                if (s) {
                    Holder_10dbb0* h = s->h;
                    if (h) {
                        if (s->Valid()) {
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
