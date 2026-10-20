#include "compat/ptr.h"
#include "gen/global.h"

struct CPatrolPathManager_106c10 {
    bool FUN_00106c10(const char*, bool, int);
};
struct Arguments {
    const char* text;
    bool flag;
    char padding[3];
    int count;
};

template <> void Closure3<CPatrolPathManager, bool, const char *, bool, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr unused = (hulk_intptr)__p0; Arguments * args = (Arguments *)__p1; bool * result = (bool *)__p2;

    Arguments* a = args;
    CPatrolPathManager_106c10* obj = (*(CPatrolPathManager_106c10 * *)&this->f_20);
    bool (CPatrolPathManager_106c10::*fn)(const char*, bool, int) = (*(bool (CPatrolPathManager_106c10::**)(const char *, bool, int))&this->f_1c);
    const char* text = a->text;
    bool flag = a->flag;
    int count = a->count;
    bool value = (obj->*fn)(text, flag, count);
    if (result)
        *result = value;
}
