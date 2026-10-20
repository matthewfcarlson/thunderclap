// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CSPManager,bool,const_char_*,float>::vfunc_2 @ 0x001e2540
#include "gen/global.h"

struct CSPManager_1e2540 { };
struct Arguments { const char* text; float value; };

template <> void Closure2<CSPManager, bool, const char *, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; Arguments * args = (Arguments *)__p1; bool * result = (bool *)__p2;

    bool value = ((*(CSPManager_1e2540 * *)&this->f_20)->*(*(bool (CSPManager_1e2540::**)(const char *, float))&this->f_1c))(args->text, args->value);
    if (result) *result = value;
}
