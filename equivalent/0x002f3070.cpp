// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002f3070 @ 0x002f3070
extern "C" double __cdecl sqrt(double);
struct Vector3_2f3070 { unsigned int x,y,z; };
struct ShapePart {
 char pad[24]; float radius; float height; unsigned char round; char tail[11];
 void FUN_00306e70();
 void FUN_00306e10(Vector3_2f3070*,unsigned int,unsigned int,unsigned int,unsigned int,int);
};
struct FUN_003060a0 {
 FUN_003060a0();
 virtual void slot0();
 char pad04[24]; Vector3_2f3070 position; char pad28[12]; float extent;
};
namespace physics {
struct CollisionCylinder : FUN_003060a0 {
 virtual void slot0();
 ShapePart first; ShapePart second;
 CollisionCylinder(Vector3_2f3070*,unsigned int,unsigned int,unsigned int,unsigned int);
};
}
physics::CollisionCylinder::CollisionCylinder(Vector3_2f3070* p,unsigned int a,unsigned int b,unsigned int c,unsigned int d) {
 first.FUN_00306e70(); second.FUN_00306e70();
 position.x=p->x; position.y=p->y; position.z=p->z;
 first.tail[7]=0; first.tail[8]=0; first.tail[9]=0; first.tail[10]=0;
 first.FUN_00306e10(p,a,b,c,d,0);
 second.FUN_00306e10(p,a,b,c,d,0);
 if(first.round) extent=(float)sqrt((double)first.radius*first.radius+(double)first.height*first.height);
 else extent=first.height+first.radius;
}