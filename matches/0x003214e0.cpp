#include "gen/pure3d.h"

#include "compat/ptr.h"
typedef long long QWORD_3214e0;
extern "C" void __stdcall QueryPerformanceCounter(QWORD_3214e0*);

hulk_freg pure3d::d3dContext::vfunc_107() {
    QWORD_3214e0 q;
    QueryPerformanceCounter(&q);
    return (hulk_freg)(q - (*(QWORD_3214e0 *)&this->f_418)) * this->f_420;
}
