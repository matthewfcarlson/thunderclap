// Same code shape as 0x0002ec60 (propagated; names are from that function)
#include "gen/global.h"

struct Arg_cff70 {
    const char* s;
    unsigned char b;
};
class Actor_cff70 {
  public:
    void invoke(const char*, unsigned char);
};

template <> void Closure2<HUDOverlay, void, int, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { Arg_cff70 * p = (Arg_cff70 *)__p1;

    ((*(Actor_cff70 * *)&this->f_20)->*(*(void (Actor_cff70::**)(const char *, unsigned char))&this->f_1c))(p->s, p->b);
}
