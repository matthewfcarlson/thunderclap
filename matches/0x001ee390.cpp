#include "gen/global.h"

struct CSoundRealTimeManager_1ee390 {};

template <> void Closure3<CSoundRealTimeManager, void, char *, char *, char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { char *volatile * args = (char *volatile *)__p1;

    char* a = args[0];
    ((*(CSoundRealTimeManager_1ee390 * *)&this->f_20)->*(*(void (CSoundRealTimeManager_1ee390::**)(char *, char *, char *))&this->f_1c))(a, args[1], args[2]);
}
