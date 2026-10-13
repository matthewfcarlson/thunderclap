// STATUS: equivalent (tools/equiv.py level 3: 171 inputs, branch coverage 10/10)
// FUN_00103a50 @ 0x00103a50
struct Vec { float x,y,z; };
struct Points { char pad[20]; int count; Vec* FUN_00106160(int); };
struct Position { void FUN_00059a50(Vec*); };
struct Result { char pad[16]; Position* position; };
struct Provider { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual Result* v6(); };
extern "C" double __cdecl sqrt(double);
struct Object { char pad[0x58]; Provider* provider; char p5c[4]; Points* points; char p64[0x54]; int selected; void target(); };
void Object::target() {
 if (!points) return;
 selected=0;
 Vec first=*points->FUN_00106160(0);
 Vec origin;
 provider->v6()->position->FUN_00059a50(&origin);
 int count=points->count;
 double x=(double)first.x-origin.x, y=(double)first.y-origin.y, z=(double)first.z-origin.z;
 float best=(float)sqrt(z*z+y*y+x*x);
 for(int i=1;i<count;++i) {
  Vec* p=points->FUN_00106160(i);
  float dx=(float)((double)p->x-origin.x);
  double dy=(double)p->y-origin.y, dz=(double)p->z-origin.z;
  double distance=sqrt(dz*dz+dy*dy+(double)dx*dx);
  if(distance < best && distance > 0.01) { best=(float)distance; selected=i; }
 }
}