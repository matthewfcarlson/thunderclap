// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CSPManager,int,const_char_*,const_char_*>::vfunc_2 @ 0x001e1900
#include "gen/global.h"

struct CSPManager_1e1900 {
    int FUN_001e1900(const char *, const char *);
};

template <> void Closure2<CSPManager, int, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { int unused = (int)__p0; const char ** arguments = (const char **)__p1; int * result = (int *)__p2;

    int value = ((*(CSPManager_1e1900 * *)&this->f_20)->*(*(int (CSPManager_1e1900::**)(const char *, const char *))&this->f_1c))(arguments[0], arguments[1]);
    if (result)
        *result = value;
}
