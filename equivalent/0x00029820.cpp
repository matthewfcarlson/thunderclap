// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 18/18)
// FUN_00029820 @ 0x00029820
struct Owner {
    char pad[0x9e];
    char hasId;
    char pad9f;
    unsigned int idLo;
    unsigned int idHi;
};

struct Holder {
    char pad[0x1ca0];
    Owner *owner;
};

union Id64 {
    unsigned __int64 q;
    unsigned int w[2];
};

Holder *__stdcall FUN_000259f0(const char *name);
unsigned __int64 __cdecl FUN_0027b020(const char *name);

bool __stdcall FUN_00029820(const char *a, const char *b)
{
    if (a == 0 || a[0] == 0 || b == 0 || b[0] == 0)
        return false;
    Holder *h = FUN_000259f0(a);
    if (h == 0)
        return false;
    Owner *o = h->owner;
    if (o == 0)
        return false;
    if (o->hasId) {
        unsigned int lo = o->idLo;
        unsigned int hi = o->idHi;
        Id64 id;
        id.q = FUN_0027b020(b);
        if (lo == id.w[0] && hi == id.w[1])
            return true;
    }
    return false;
}
