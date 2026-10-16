// Same code shape as 0x0002ec60 (propagated; names are from that function)
#include "gen/global.h"

struct Arg_946d0 {
    const char* s;
    unsigned char b;
};
class Actor_946d0 {
  public:
    void invoke(const char*, unsigned char);
};

template <> void Closure2<CUnlockablesManager, void, int, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { Arg_946d0 * p = (Arg_946d0 *)__p1;

    ((*(Actor_946d0 * *)&this->f_20)->*(*(void (Actor_946d0::**)(const char *, unsigned char))&this->f_1c))(p->s, p->b);
}
