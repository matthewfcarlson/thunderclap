// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0030f1e0 @ 0x0030f1e0
#include "gen/owners.h"
struct Vec3_30f1e0 { float x,y,z; };
struct Object;
struct Quaternion_30f1e0 {
 float x,y,z; unsigned int w;
};
struct Object {
 char pad[0x30]; Vec3_30f1e0 position; char pad3c[4]; Quaternion_30f1e0 rotation; int state;
 void blend(float,Object*);
};
void Object::blend(float t,Object* other) {
 float one=1.0f;
 double a=one-(double)t;
 Vec3_30f1e0 v;
 Quaternion_30f1e0 result;
 volatile float sy=(float)(position.y*a);
 volatile float sz=(float)(position.z*a);
 result.x=other->position.x;
 result.y=other->position.y*t;
 result.z=other->position.z*t;
 v.x=(float)(result.x*(double)t+position.x*a);
 v.y=result.y+sy;
 v.z=result.z+sz;
 ((owners::Target_22be40 *)this)->FUN_0022be40((const int *)(Vec3_30f1e0 *)(&v));
 if(other->state==2) { ((owners::Quat_22b370 *)&(other->rotation))->FUN_0022b370((const float *)(Object *)other); other->state=0; }
 if(state==2) { ((owners::Quat_22b370 *)&rotation)->FUN_0022b370((const float *)(Object *)this); state=0; }
 ((owners::Quaternion_22b750 *)&result)->FUN_0022b750((const owners::Quaternion_22b750 *)(Quaternion_30f1e0 *)(&rotation), (const owners::Quaternion_22b750 *)(Quaternion_30f1e0 *)(&other->rotation), t);
 rotation=result;
 state=1;
}
