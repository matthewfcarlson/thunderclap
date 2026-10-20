// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure4<CSPManager,bool,const_char_*,float,float,int>::vfunc_2 @ 0x001e25c0
#include "gen/global.h"

struct CSPManager_1e25c0 { bool FUN_001e25c0(const char*, float, float, int); };
struct ClosureArgs { const char* text; float first; float second; int number; };

template <> void Closure4<CSPManager, bool, const char *, float, float, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const ClosureArgs * args = (const ClosureArgs *)__p1; bool * result = (bool *)__p2;

    bool value = ((*(CSPManager_1e25c0 * *)&this->f_20)->*(*(bool (CSPManager_1e25c0::**)(const char *, float, float, int))&this->f_1c))(args->text, args->first, args->second, args->number);
    if (result) *result = value;
}
