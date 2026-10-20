// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure3<CAmbientsManager,void,const_char_*,int,bool>::vfunc_2 @ 0x0007e100
#include "gen/global.h"

struct CAmbientsManager_7e100 {};
struct AmbientArgs { const char* name; int number; bool enabled; };

template <> void Closure3<CAmbientsManager, void, const char *, int, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const AmbientArgs * arguments = (const AmbientArgs *)__p1; void * unused2 = (void *)__p2;

    ((*(CAmbientsManager_7e100 * *)&this->f_20)->*(*(void (CAmbientsManager_7e100::**)(const char *, int, bool))&this->f_1c))(arguments->name, arguments->number, arguments->enabled);
}
