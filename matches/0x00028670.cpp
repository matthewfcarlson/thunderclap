#include "decls/address.h"
struct Sub {
    int done();
};
struct Result {
    char pad[0x1d70];
    Sub sub;
};
struct Obj {
    Result* get(unsigned a, unsigned b);
    int fn(const char* s, int n);
};
int Obj::fn(const char* s, int n) {
    unsigned __int64 v = FUN_002672f0(s, 0, 0);
    Result* r = get((unsigned)v, (unsigned)(v >> 32));
    if (!r)
        return 0;
    return r->sub.done();
}