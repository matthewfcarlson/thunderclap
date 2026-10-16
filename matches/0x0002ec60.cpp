#include "gen/global.h"

struct Arg_2ec60 {
    const char* s;
    unsigned char b;
};
class Actor_2ec60 {
  public:
    void invoke(const char*, unsigned char);
};

template <> void Closure2<CActorManager, void, const char *, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { Arg_2ec60 * p = (Arg_2ec60 *)__p1;

    ((*(Actor_2ec60 * *)&this->f_20)->*(*(void (Actor_2ec60::**)(const char *, unsigned char))&this->f_1c))(p->s, p->b);
}
