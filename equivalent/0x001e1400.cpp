// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Closure3<CSPManager,bool,const_char_*,int,int>::vfunc_2 @ 0x001e1400
#include "gen/global.h"

struct CSPManager_1e1400 { bool FUN_001e1400(const char*, int, int); };
struct Arguments { const char* text; int a; int b; };

template <> void Closure3<CSPManager, bool, const char *, int, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { Arguments * args = (Arguments *)__p1; bool * result = (bool *)__p2;

    bool value = ((*(CSPManager_1e1400 * *)&this->f_20)->*(*(bool (CSPManager_1e1400::**)(const char *, int, int))&this->f_1c))(args->text, args->a, args->b);
    if (result) *result = value;
}
