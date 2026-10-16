// Same code shape as 0x0002ec60 (propagated; names are from that function)
#include "gen/global.h"

struct Arg_7e020 {
    const char* s;
    unsigned char b;
};
class Actor_7e020 {
  public:
    void invoke(const char*, unsigned char);
};

template <> void Closure2<CAmbientsManager, void, const char *, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { Arg_7e020 * p = (Arg_7e020 *)__p1;

    ((*(Actor_7e020 * *)&this->f_20)->*(*(void (Actor_7e020::**)(const char *, unsigned char))&this->f_1c))(p->s, p->b);
}
