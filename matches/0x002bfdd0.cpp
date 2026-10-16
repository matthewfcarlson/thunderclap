#include "gen/pure3d.h"

void __cdecl free_pixels(void*);
void* __cdecl alloc_pixels(int);

void pure3d::Image8::vfunc_5(int w, int h) {
    this->f_10 = w;
    this->f_14 = h;
    free_pixels((*(void * *)&this->f_24));
    (*(void * *)&this->f_24) = alloc_pixels(this->f_14 * this->f_10);
}
