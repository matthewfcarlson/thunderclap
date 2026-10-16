#include "gen/hulkfight.h"

extern "C" char DAT_00494b44[];
extern "C" char DAT_004c13d0[];
struct R_1a4c50 {
    char a[4];
    int type;
    char b[12];
    int name;
};
extern void* Find(void*, int, void*, void*, int);
struct Obj_1a4c50 {
    R_1a4c50* Get();
};

bool hulkfight::scenario::Event_LocomotionStateNamePreviousCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { void * x = (void *)__p0; void * y = (void *)__p1; void * z = (void *)__p2;

    void* p = Find(y, 0, (void*)((int)DAT_00494b44), (void*)((int)DAT_004c13d0), 0);
    if (!p)
        return false;
    R_1a4c50* q = ((Obj_1a4c50*)p)->Get();
    if (q->type != 15)
        return false;
    int n = q->name;
    switch (this->f_0c) {
    case 0:
        return n == this->f_10;
    case 1:
        return n != this->f_10;
    }
    return false;
}
