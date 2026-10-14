// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002fba80 @ 0x002fba80
extern "C" double __cdecl sqrt(double);
struct Bits3 { unsigned int x,y,z; };
struct Vec3_2fba80 { float x,y,z; };
struct Object {
 char pad0[0x1c]; Bits3 position; char pad28[0xc]; float radius; unsigned int flags; Bits3 savedPosition; Vec3_2fba80 scale; Bits3 axisX,axisY,axisZ; char pad78[0x10]; Vec3_2fba80 savedScale; Bits3 savedX,savedY,savedZ;
 void FUN_002fba80(const Bits3* p,const Vec3_2fba80* s,const Bits3* x,const Bits3* y,const Bits3* z);
};
void Object::FUN_002fba80(const Bits3* p,const Vec3_2fba80* s,const Bits3* x,const Bits3* y,const Bits3* z) {
 position.x=p->x; position.y=p->y; position.z=p->z;
 savedPosition.x=p->x; savedPosition.y=p->y; savedPosition.z=p->z;
 scale.x=savedScale.x=s->x; scale.y=savedScale.y=s->y; scale.z=savedScale.z=s->z;
 radius=(float)sqrt((double)s->y*s->y+(double)s->z*s->z+(double)s->x*s->x);
 savedX.x=x->x; savedX.y=x->y; savedX.z=x->z;
 savedY.x=y->x; savedY.y=y->y; savedY.z=y->z;
 savedZ.x=z->x; savedZ.y=z->y; savedZ.z=z->z;
 axisX.x=savedX.x; axisX.y=savedX.y; axisX.z=savedX.z;
 axisY.x=savedY.x; axisY.y=savedY.y; axisY.z=savedY.z;
 axisZ.x=savedZ.x; axisZ.y=savedZ.y; axisZ.z=savedZ.z;
 flags=0;
}