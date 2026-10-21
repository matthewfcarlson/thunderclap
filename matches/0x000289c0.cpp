#include "compat/ptr.h"
extern const float zero;
struct Result {
    float Get();
};
struct Obj {
    Result* Find(unsigned a, unsigned b);
    hulk_freg Run(const char* s);
};
extern "C" unsigned __int64 __cdecl Parse(const char*, int, int);
hulk_freg Obj::Run(const char* s) {
    unsigned __int64 v = Parse(s, 0, 0);
    Result* r = Find((unsigned)v, (unsigned)(v >> 32));
    if (!r)
        return zero;
    return r->Get();
}