// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// choreo2::AnimationDriver::vfunc_12 @ 0x00225800
#include "gen/choreo2.h"

struct Query_225800 { char pad[8]; int first; int second; };
struct Tracks {
 bool FUN_00288d10(int, int, int, int*, int*);
 float FUN_00288de0(int, int, int, int);
};
namespace choreo2 {
struct AnimationDriver_nv_225800 {
    bool FUN_00222330(Query_225800*);
};
}
bool choreo2::AnimationDriver::vfunc_12(int __p0, int __p1) { Query_225800 * query = (Query_225800 *)__p0; float * result = (float *)__p1;

 int a,b;
 int first=query->first, second=query->second;
 if (!(*(Tracks * *)&this->f_20)->FUN_00288d10(0,first,second,&b,&a)) return false;
 if (!((AnimationDriver_nv_225800*)this)->FUN_00222330(query)) return false;
 float start=(*(Tracks * *)&this->f_20)->FUN_00288de0(0,0,first,second);
 float end=(*(Tracks * *)&this->f_20)->FUN_00288de0(1,0,first,second);
 if (!(end>=start)) {
  *result=(end<=this->f_23c && this->f_23c<start)?1.0f:0.0f;
 } else {
  *result=(this->f_23c<start || !(end>this->f_23c))?1.0f:0.0f;
 }
 return true;
}
