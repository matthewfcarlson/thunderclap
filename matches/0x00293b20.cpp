#include "gen/pure3d.h"

struct H {
    void init();
    void combine(void*, void*);
    void finish();
};
struct M_293b20 {
    unsigned int v[16];
};

void pure3d::VectorCamera::vfunc_26() {
    char* b = (char*)this;
    ((H*)(b + 0xdc))->init();
    ((H*)(b + 0xe8))->init();
    ((H*)(b + 0x8c))->combine(b + 0xdc, b + 0xe8);
    *(volatile int*)(b + 0xbc) = *(volatile int*)(b + 0xd0);
    *(volatile int*)(b + 0xc0) = *(volatile int*)(b + 0xd4);
    *(volatile int*)(b + 0xc4) = *(volatile int*)(b + 0xd8);
    *(M_293b20*)(b + 0x4c) = *(M_293b20*)(b + 0x8c);
    ((H*)(b + 0x4c))->finish();
    b[0xcc] = 1;
}
