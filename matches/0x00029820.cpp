// FUN_00029820 @ 0x00029820
#include "decls/address.h"
struct Owner_29820 {
    char pad[0x9e];
    char hasId;
    char pad9f;
    unsigned int idLo;
    unsigned int idHi;
};

struct Holder_29820 {
    char pad[0x1ca0];
    Owner_29820 *owner;
};

union Id64_29820 {
    unsigned __int64 q;
    unsigned int w[2];
};

Holder_29820 *__stdcall FUN_000259f0(const char *name);

bool __stdcall FUN_00029820(const char *a, const char *b)
{
    if (a == 0 || a[0] == 0 || b == 0 || b[0] == 0)
        return false;
    Holder_29820 *h = FUN_000259f0(a);
    if (h == 0)
        return false;
    Owner_29820 *o = h->owner;
    if (o == 0)
        return false;
    if (o->hasId) {
        unsigned int lo = o->idLo;
        unsigned int hi = o->idHi;
        Id64_29820 id;
        id.q = FUN_0027b020(b);
        if (lo == id.w[0] && hi == id.w[1])
            return true;
    }
    return false;
}
