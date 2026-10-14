// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0030f1e0 @ 0x0030f1e0
struct Vec3_30f1e0 { float x,y,z; };
struct Object;
struct Quaternion_30f1e0 {
 float x,y,z; unsigned int w;
 void FUN_0022b370(Object*);
 void FUN_0022b750(Quaternion_30f1e0*,Quaternion_30f1e0*,float);
};
struct Object {
 char pad[0x30]; Vec3_30f1e0 position; char pad3c[4]; Quaternion_30f1e0 rotation; int state;
 void FUN_0022be40(Vec3_30f1e0*);
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
 FUN_0022be40(&v);
 if(other->state==2) { other->rotation.FUN_0022b370(other); other->state=0; }
 if(state==2) { rotation.FUN_0022b370(this); state=0; }
 result.FUN_0022b750(&rotation,&other->rotation,t);
 rotation=result;
 state=1;
}
