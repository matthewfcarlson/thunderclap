// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// hulkfight::motion::CollisionSourceForceMagnitudeCondition::vfunc_6 @ 0x00150a10
#include "gen/hulkfight.h"

extern "C" void* __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
extern char DAT_00494b44;
extern char DAT_00494b60;
extern "C" bool __cdecl FUN_00018960(float,float,float);
extern "C" double __cdecl sqrt(double);
struct Force { char pad[0x38]; float x,y,z; };
struct Source_150a10 { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual Force* slot3(); };
namespace hulkfight { namespace motion {

}}
bool hulkfight::motion::CollisionSourceForceMagnitudeCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { Source_150a10 * source = (Source_150a10 *)__p1;

if (!FUN_00344e74(source,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
Force* force=source->slot3();
if (!force) return false;
float magnitude=(float)sqrt(force->x*force->x+force->y*force->y+force->z*force->z);
switch((*(unsigned int *)&this->f_0c)) {
case 0: return magnitude<this->f_10;
case 1: return magnitude<=this->f_10;
case 2: return FUN_00018960(magnitude,this->f_10,0.00001f);
case 3: return !FUN_00018960(magnitude,this->f_10,0.00001f);
case 4: return magnitude>=this->f_10;
case 5: return magnitude>this->f_10;
default: return false;
}
}
