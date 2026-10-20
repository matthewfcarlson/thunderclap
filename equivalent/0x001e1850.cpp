// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CSPManager,int,const_char_*,int>::vfunc_2 @ 0x001e1850
#include "gen/global.h"

struct CSPManager_1e1850 { int FUN_001e1850(int, const char *); };

template <> void Closure2<CSPManager, int, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const void * arguments = (const void *)__p1; int * result = (int *)__p2;

    const struct Arguments { int first; const char *second; } *args = (const Arguments *)arguments;
    int value = ((*(CSPManager_1e1850 * *)&this->f_20)->*(*(int (CSPManager_1e1850::**)(int, const char *))&this->f_1c))(args->first, args->second);
    if (result) *result = value;
}
