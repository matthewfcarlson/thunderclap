#include "gen/global.h"

class HUDOverlay_cef00 {
  public:
    int Do(int, int);
};
struct Args {
    int a;
    int b;
};

template <> void Method2<HUDOverlay, int, int, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { HUDOverlay_cef00 * obj = (HUDOverlay_cef00 *)__p0; Args * args = (Args *)__p1; int * out = (int *)__p2;

    int (HUDOverlay_cef00::*fn)(int, int) = (*(int (HUDOverlay_cef00::**)(int, int))&this->f_1c);
    int a = args->a;
    int b = args->b;
    int result = (obj->*fn)(a, b);
    if (out)
        *out = result;
}
