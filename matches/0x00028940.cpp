#include "decls/address.h"
struct Result {
    void Apply(int);
};
struct Obj {
    Result* Find(unsigned, unsigned);
    void Do(const char*, int);
};
void Obj::Do(const char* s, int x) {
    unsigned __int64 v = FUN_002672f0(s, 0, 0);
    Result* r = Find((unsigned)v, (unsigned)(v >> 32));
    if (r)
        r->Apply(x);
}