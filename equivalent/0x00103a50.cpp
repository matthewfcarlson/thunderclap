// STATUS: equivalent (tools/equiv.py level 3: 171 inputs, branch coverage 10/10)
// FUN_00103a50 @ 0x00103a50
struct Vec_103a50 { float x,y,z; };
struct Points { char pad[20]; int count; Vec_103a50* FUN_00106160(int); };
struct Position_103a50 { void FUN_00059a50(Vec_103a50*); };
struct Result_103a50 { char pad[16]; Position_103a50* position; };
struct Provider_103a50 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual Result_103a50* v6(); };
extern "C" double __cdecl sqrt(double);
struct COccupationAgent_103a50 { char pad[0x58]; Provider_103a50* provider; char p5c[4]; Points* points; char p64[0x54]; int selected; void target(); };
void COccupationAgent_103a50::target() {
 if (!points) return;
 selected=0;
 Vec_103a50 first=*points->FUN_00106160(0);
 Vec_103a50 origin;
 provider->v6()->position->FUN_00059a50(&origin);
 int count=points->count;
 double x=(double)first.x-origin.x, y=(double)first.y-origin.y, z=(double)first.z-origin.z;
 float best=(float)sqrt(z*z+y*y+x*x);
 for(int i=1;i<count;++i) {
  Vec_103a50* p=points->FUN_00106160(i);
  float dx=(float)((double)p->x-origin.x);
  double dy=(double)p->y-origin.y, dz=(double)p->z-origin.z;
  double distance=sqrt(dz*dz+dy*dy+(double)dx*dx);
  if(distance < best && distance > 0.01) { best=(float)distance; selected=i; }
 }
}