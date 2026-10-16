#include "gen/pure3d.h"

struct Buffer_2d5cb0 {
    int a[2];
    int used;
    int* data;
};

void pure3d::SpriteParticleEmitter::vfunc_15() {
    unsigned int i = 0;
    Buffer_2d5cb0* b = *(Buffer_2d5cb0**)((char*)this + 0x84);
    while (i < this->f_14c) {
        int* p = (*(int * *)&this->f_1c8) + i;
        int v = *p;
        if (v) {
            b->data[b->used++] = v;
            *p = 0;
        }
        ++i;
    }
    this->f_14c = 0;
}
