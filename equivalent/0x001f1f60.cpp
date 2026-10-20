// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure4<CSoundSystem,void,char_*,char_*,float,float>::vfunc_2 @ 0x001f1f60
#include "gen/global.h"

struct CSoundSystem_1f1f60 { void FUN_001f1f60(char*, char*, float, float); };
struct Arguments { char* first; char* second; float third; float fourth; };

template <> void Closure4<CSoundSystem, void, char *, char *, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { Arguments * args = (Arguments *)__p1;

    ((*(CSoundSystem_1f1f60 * *)&this->f_20)->*(*(void (CSoundSystem_1f1f60::**)(char *, char *, float, float))&this->f_1c))(args->first, args->second, args->third, args->fourth);
}
