// Same code shape as 0x0002ec60 (propagated; names are from that function)
#include "gen/global.h"

struct Arg_aed50 {
    const char* s;
    unsigned char b;
};
class Actor_aed50 {
  public:
    void invoke(const char*, unsigned char);
};

template <> void Closure2<CControllerManager, void, int, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { Arg_aed50 * p = (Arg_aed50 *)__p1;

    ((*(Actor_aed50 * *)&this->f_20)->*(*(void (Actor_aed50::**)(const char *, unsigned char))&this->f_1c))(p->s, p->b);
}
