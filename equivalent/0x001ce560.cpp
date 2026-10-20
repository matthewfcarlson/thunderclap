// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CScenarioManager,int,float,const_char_*>::vfunc_2 @ 0x001ce560
#include "gen/global.h"

struct CScenarioManager_1ce560 { char unused; };
struct Arguments { int value; float fraction; };

template <> void Closure2<CScenarioManager, int, float, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; Arguments * args = (Arguments *)__p1; const char ** result = (const char **)__p2;

    const char* value = ((*(CScenarioManager_1ce560 * *)&this->f_20)->*(*(const char *(CScenarioManager_1ce560::**)(int, float))&this->f_1c))(args->value, args->fraction);
    if (result) *result = value;
}
