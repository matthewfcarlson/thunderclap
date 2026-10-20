// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Closure3<CWorldStreamManager,int,float,float,float>::vfunc_2 @ 0x00205d70
#include "gen/global.h"

struct CWorldStreamManager_205d70 { int dummy; };  
template <> void Closure3<CWorldStreamManager, int, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { int unused = (int)__p0; const float * args = (const float *)__p1; int * result = (int *)__p2;
 int value = ((*(CWorldStreamManager_205d70 * *)&this->f_20)->*(*(int (CWorldStreamManager_205d70::**)(float, float, float))&this->f_1c))(args[0], args[1], args[2]); if (result) *result = value; }
