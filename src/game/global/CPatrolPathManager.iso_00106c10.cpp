// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001065b0..0x00107000 (kind game, layer game, confidence high), dominant class CPatrolPathManager
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00106c10 Closure3<CPatrolPathManager,bool,const_char_*,bool,int>::vfunc_2 (50 B): matches/0x00106c10.cpp [isolated: conflict: Arguments; on include/gen/ and not mergeable]
// sym: ?vfunc_2@?$Closure3@VCPatrolPathManager@@_NPBD_NH@@UAEXPAX00@Z
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

