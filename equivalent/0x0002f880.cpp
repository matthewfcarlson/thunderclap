// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure5<CActorManager,void,const_char_*,const_char_*,float,float,float>::vfunc_2 @ 0x0002f880
#include "gen/global.h"

struct CActorManager_2f880 {};
struct Arguments { const char* first; const char* second; float third; float fourth; float fifth; };

template <> void Closure5<CActorManager, void, const char *, const char *, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { const Arguments * args = (const Arguments *)__p1;

    ((*(CActorManager_2f880 * *)&this->f_20)->*(*(void (CActorManager_2f880::**)(const char *, const char *, float, float, float))&this->f_1c))(args->first, args->second, args->third, args->fourth, args->fifth);
}
