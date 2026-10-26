#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int type1_138b80, type2;
class Built_138b80 {
  public:
    int make(int, hulk_intptr);
};
extern int __cdecl Check(void*, int, hulk_intptr, hulk_intptr, int);
extern Built_138b80* __cdecl Allocate(int);

hulk_intptr hulkfight::motion::HoverTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    if (Check((void*)c, 0, (hulk_intptr)&type1_138b80, (hulk_intptr)&type2, 0)) {
        Built_138b80* p = Allocate(0x24);
        if (p) {
            int m = this->f_14;
            return p->make(m, c);
        }
    }
    return 0;
}
