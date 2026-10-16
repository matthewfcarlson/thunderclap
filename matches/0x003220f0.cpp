#include "gen/pure3d.h"

struct Block_3220f0 {
    unsigned int x[16];
};

bool pure3d::d3dExtGlobalProjectedTexture::vfunc_2(int index, void* __p1, void* __p2) { Block_3220f0 * output = (Block_3220f0 *)__p1; int * value = (int *)__p2;

    *output = *(Block_3220f0*)((char*)this + index * 0x40 + 0x44);
    int v = *(int*)((char*)this + index * 4 + 4);
    *value = v;
    return v != 0;
}
