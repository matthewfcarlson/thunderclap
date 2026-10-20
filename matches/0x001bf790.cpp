#include "gen/global.h"

struct CSubtitleManager_1bf790 {
    void FUN_001bf790(float, float, float);
};
struct Float3 {
    float x, y, z;
};
struct Function_1bf790 {
    virtual void vfunc_0();
    virtual void vfunc_1();
};

template <> void Method3<CSubtitleManager, void, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSubtitleManager_1bf790 * manager = (CSubtitleManager_1bf790 *)__p0; const Float3 * values = (const Float3 *)__p1; void * unused = (void *)__p2;

    const Float3* v = values;
    volatile unsigned int& x = *(volatile unsigned int*)&values;
    x = *(const unsigned int*)&v->x;
    (manager->*(*(void (CSubtitleManager_1bf790::**)(float, float, float))&this->f_1c))(*(float*)&values, v->y, v->z);
}
