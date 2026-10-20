// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Closure2<CSPManager,bool,const_char_*,int>::vfunc_2 @ 0x001e1560
#include "gen/global.h"

struct CSPManager_1e1560 {};
struct Arguments { const char* text; int number; };

template <> void Closure2<CSPManager, bool, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; Arguments * args = (Arguments *)__p1; bool * result = (bool *)__p2;

    bool value = ((*(CSPManager_1e1560 * *)&this->f_20)->*(*(bool (CSPManager_1e1560::**)(const char *, int))&this->f_1c))(args->text, args->number);
    if (result) *result = value;
}
