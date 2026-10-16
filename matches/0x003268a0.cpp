#include "gen/pure3d.h"

extern "C" void* __stdcall D3DPalette_Lock2(void*, int);
extern "C" void* memcpy(void*, const void*, unsigned int);
namespace pure3d {
} // namespace pure3d
void pure3d::d3dTexture::vfunc_11(unsigned int count, void* __p1) { unsigned int * src = (unsigned int *)__p1;

    if ((*(void * *)&this->f_68)) {
        void* dst = D3DPalette_Lock2((*(void * *)&this->f_68), 0);
        volatile unsigned int* p = src;
        memcpy(dst, (const void*)p, count * 4);
    }
}
