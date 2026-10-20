// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<CActorManager,void,const_char_*,const_char_*,float>::vfunc_2 @ 0x0002fac0
#include "gen/global.h"

struct CActorManager_2fac0 { void FUN_0002fac0(const char *, const char *, float); };  
template <> void Closure3<CActorManager, void, const char *, const char *, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char ** args = (const char **)__p1;
 struct Args { const char *first; const char *second; float third; }; Args *a = (Args *)args; ((*(CActorManager_2fac0 * *)&this->f_20)->*(*(void (CActorManager_2fac0::**)(const char *, const char *, float))&this->f_1c))(a->first, a->second, a->third); }
