#include "gen/global.h"

struct Vec_2d290 {
    int x, y, z;
};
class Actor_2d290 {
  public:
    bool Invoke(Vec_2d290 v);
};
typedef bool (Actor_2d290::*ActorFn_2d290)(Vec_2d290);

template <> void Method1<CActorManager, bool,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Vec_2d290 * v = (Vec_2d290 *)__p1; unsigned char * out = (unsigned char *)__p2;

    ActorFn_2d290 f = (*(ActorFn_2d290 *)&this->f_1c);
    unsigned char r = (unsigned char)((((Actor_2d290*)a)->*f)(*v));
    if (out)
        *out = r;
}
