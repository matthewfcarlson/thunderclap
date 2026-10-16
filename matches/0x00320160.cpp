#include "gen/pure3d.h"

class Device_320160 {
    char pad[0x154];

  public:
    void Read(void*, int, int*, void*);
};
class Mid_320160 {
    char pad[0x154];

  public:
    Device_320160* dev;
};

void pure3d::d3dExtReadPixels::vfunc_1(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; int * r = (int *)__p1; void * c = (void *)__p2;

    Device_320160* d = (*(Mid_320160 * *)&this->f_04)->dev;
    d->Read(c, (r[3] - r[1]) * (r[2] - r[0]) * 4, r, a);
}
