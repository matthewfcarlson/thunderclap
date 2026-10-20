// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure3<CWorldStreamManager,void,const_char_*,int,bool>::vfunc_2 @ 0x002061c0
#include "gen/global.h"

struct CWorldStreamManager_2061c0 {
    void FUN_002061c0(const char *, int, bool);
};
struct Args { const char *name; int number; bool flag; };

template <> void Closure3<CWorldStreamManager, void, const char *, int, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { const Args * args = (const Args *)__p1;

    ((*(CWorldStreamManager_2061c0 * *)&this->f_20)->*(*(void (CWorldStreamManager_2061c0::**)(const char *, int, bool))&this->f_1c))(args->name, args->number, args->flag);
}
