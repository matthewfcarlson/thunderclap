#include "gen/pure3d.h"

extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
namespace pure3d {

} // namespace pure3d
void pure3d::Image32::vfunc_6(int w, int h, void* __p2) { const void * src = (const void *)__p2;

    vfunc_5(w, h);
    memcpy((*(void * *)&this->f_24), src, w * h * 4);
}
