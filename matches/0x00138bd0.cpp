#include "gen/hulkfight.h"

class Result_138bd0 {
  public:
    int build(int, int);
};
extern int __cdecl Lookup(int);
extern Result_138bd0* __cdecl Alloc(int);

int hulkfight::motion::GrappleHoverTrack::vfunc_10(int a, int b, int c) {
    int x = Lookup(c);
    if (x) {
        Result_138bd0* p = Alloc(0x24);
        if (p) {
            int f = this->f_14;
            return p->build(f, x);
        }
    }
    return 0;
}
