#include "decls/data/game/hulkfight/motion.h"

extern "C" char DAT_0041324c[];
extern int gCounter_145990;
extern int gArray_145990;
extern "C" void* Alloc(unsigned int);
struct Obj_145990 {
    void* vf;
    char pad[12];
    int v;
    char rest[4];
    void Init(const char*);
};
extern "C" void Register(void*, Obj_145990**, int);

void FUN_00145990() {
    if (gCounter_145990 == 0) {
        Obj_145990* a[6];
        Obj_145990* p;
        p = (Obj_145990*)Alloc(24);
        if (p) {
            p->Init("timeBegin");
            p->vf = (void*)((int)DAT_0041324c);
            p->v = 0x143610;
            a[0] = p;
        } else
            a[0] = 0;
        p = (Obj_145990*)Alloc(24);
        if (p) {
            p->Init("timeOn");
            p->vf = (void*)((int)DAT_0041324c);
            p->v = 0x143630;
            a[1] = p;
        } else
            a[1] = 0;
        p = (Obj_145990*)Alloc(24);
        if (p) {
            p->Init("timeOff");
            p->vf = (void*)((int)DAT_0041324c);
            p->v = 0x143650;
            a[2] = p;
        } else
            a[2] = 0;
        p = (Obj_145990*)Alloc(24);
        if (p) {
            p->Init("timeEnd");
            p->vf = (void*)((int)DAT_0041324c);
            p->v = 0x143670;
            a[3] = p;
        } else
            a[3] = 0;
        p = (Obj_145990*)Alloc(24);
        if (p) {
            p->Init("motionBlur");
            p->vf = (void*)((int)DAT_0041324c);
            p->v = 0x143690;
            a[4] = p;
        } else
            a[4] = 0;
        p = (Obj_145990*)Alloc(24);
        if (p) {
            p->Init("motionBlurParallax");
            p->vf = (void*)((int)DAT_0041324c);
            p->v = 0x1436b0;
            a[5] = p;
        } else
            a[5] = 0;
        Register((void*)((int)DAT_004e0fa0), a, 6);
    }
    ++gCounter_145990;
}
