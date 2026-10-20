#include "compat/ptr.h"
#include "gen/global.h"

typedef unsigned int u32_1bfc30;
struct State_1bfc30 {
    char pad[0x58];
    int query(int, int);
};
struct sSubtitleCallback_1bfc30 {
    virtual void f0();
    virtual void f1(int, int);
};

void sSubtitleManagerCallback::vfunc_1(int a, int b) {
    State_1bfc30* p = (*(State_1bfc30 * *)&this->f_04);
    if (p && p->query(a, b) != -1 && *(int*)((char*)p + 0x20) == 2) {
        *(u32_1bfc30*)((char*)p + 4) = 0;
        *(u32_1bfc30*)p = 0xbf800000;
        *((unsigned char*)p + 0xd) = 0;
        *((unsigned char*)p + 0x24) = 0;
        *((unsigned char*)p + 0x55) = 0;
        *((unsigned char*)(*(hulk_uintptr*)((char*)p + 0x2c)) + 0xc) = 0;
    }
}
