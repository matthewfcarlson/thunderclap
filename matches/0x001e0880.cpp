#include "gen/global.h"

struct Vector_1e0880 {
    float x, y, z;
};
struct CSPManager_1e0880 {
    int dummy;
};
struct Arg_1e0880 {
    Vector_1e0880 v;
    float f;
};

template <> void Method2<CSPManager, bool,math::Vector, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSPManager_1e0880 * obj = (CSPManager_1e0880 *)__p0; Arg_1e0880 * a = (Arg_1e0880 *)__p1; bool * out = (bool *)__p2;

    bool (CSPManager_1e0880::*fn)(Vector_1e0880, float) = (*(bool (CSPManager_1e0880::**)(Vector_1e0880, float))&this->f_1c);
    Vector_1e0880 v = a->v;
    float f = a->f;
    bool r = (obj->*fn)(v, f);
    if (out)
        *out = r;
}
