// Same code shape as 0x000244a0 (propagated; names are from that function)
#include "gen/pure3d.h"

struct Y_324590 {
    void g(int, int, int);
};

void pure3d::d3dExtGammaControl::vfunc_1(int a0, int a1, int a2) {
    (*(Y_324590 * *)&this->f_04)->g(a0, a1, a2);
}
