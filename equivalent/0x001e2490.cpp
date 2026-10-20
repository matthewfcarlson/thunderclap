// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<CSPManager,void,float,float,float>::vfunc_2 @ 0x001e2490
#include "gen/global.h"

struct CSPManager_1e2490 { void FUN_001e2490(float, float, float); }; struct Values { float a,b,c; };  
template <> void Closure3<CSPManager, void, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; Values * values = (Values *)__p1; void * unused2 = (void *)__p2;
 ((*(CSPManager_1e2490 * *)&this->f_20)->*(*(void (CSPManager_1e2490::**)(float, float, float))&this->f_1c))(values->a,values->b,values->c); }
