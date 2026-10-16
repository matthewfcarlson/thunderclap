#include "gen/pure3d.h"

extern "C" void* memcpy(void*, const void*, unsigned);
struct Info_2ae060 {
    char p[0x10];
    int count;
    int p14;
    int bpp;
};

void pure3d::ImageBuilder::vfunc_2(void* __p0) { const unsigned char * src = (const unsigned char *)__p0;

    int n;
    if ((*(Info_2ae060 * *)&this->f_04)->bpp == 8) {
        n = (*(Info_2ae060 * *)&this->f_04)->count;
        memcpy((*(unsigned char * *)&this->f_0c), src, n);
    } else {
        n = (*(Info_2ae060 * *)&this->f_04)->count;
        for (int i = 0; i < n; i++)
            ((unsigned*)(*(unsigned char * *)&this->f_0c))[i] = (*(unsigned int * *)&this->f_08)[src[i]];
    }
    (*(unsigned char * *)&this->f_0c) += (*(int *)&this->f_14);
    (*(int *)&this->f_10)++;
}
