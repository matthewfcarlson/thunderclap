#include "gen/hulkfight.h"

typedef unsigned int u32_17b170;
extern int desc1_17b170;
extern int desc2_17b170;
int __cdecl check(void* obj, int z, void* d1, void* d2, int z2);
void* __cdecl alloc(int size);
struct Result_17b170 {
    int init(void* self, void* p);
};
struct Track_17b170 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual int v10(u32_17b170, u32_17b170, void*);
};

int hulkfight::motion::JointPivotTrackerTrack::vfunc_10(int __p0, int __p1, int __p2) { u32_17b170 a = (u32_17b170)__p0; u32_17b170 b = (u32_17b170)__p1; void * c = (void *)__p2;

    if (check(c, 0, &desc1_17b170, &desc2_17b170, 0)) {
        Result_17b170* p = (Result_17b170*)alloc(0x84);
        if (p)
            return p->init(this, c);
    }
    return 0;
}
