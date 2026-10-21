#include "compat/ptr.h"
struct V {
    float Get();
};
struct X {
    V* Find(__int64);
    hulk_freg Fn(int);
};
extern "C" __int64 __cdecl Make(int, int, int);
extern const float deg;
hulk_freg X::Fn(int x) {
    __int64 a = Make(x, 0, 0);
    V* v = Find(a);
    if (!v)
        return 0.0f;
    return v->Get() * deg;
}