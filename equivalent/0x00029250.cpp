// STATUS: equivalent (tools/equiv.py level 3: 77 inputs, branch coverage 17/20, incomplete)
// FUN_00029250 @ 0x00029250
extern "C" double __cdecl sqrt(double);
struct Vec3 { float x,y,z; };
struct Effect { char pad[0x58]; char data; void FUN_000fe4d0(int, int); };
struct Position { void FUN_00059a50(Vec3*); };
struct Entity { char pad0[0x10]; Position* position; char pad1[0x1ca0-0x14]; Effect* effect; char pad2[0x1cbc-0x1ca4]; float value; bool FUN_00035ab0(); };
struct Registry { Entity* FUN_00059c10(int); };
struct Owner { char pad[0x44]; Registry* registry; };
struct Target { Owner* owner; char pad[8]; int count; int ids[1]; void FUN_00029250(int, const Vec3*, float, int); };
void Target::FUN_00029250(int a, const Vec3* point, float radius, int b) {
 int n=count;
 for(int i=0;i<n;++i) {
  if(i<0 || i>=count) continue;
  Entity* e=owner->registry->FUN_00059c10(ids[i]);
  if(!e) continue;
  Vec3 p;
  e->position->FUN_00059a50(&p);
  if(e->FUN_00035ab0()) continue;
  if(!(e->value>0.0f)) continue;
  Effect* effect=e->effect;
  if(!effect || !&effect->data) continue;
  double x=(double)point->x-p.x;
  double y=(double)point->y-p.y;
  double z=(double)point->z-p.z;
  if(sqrt(z*z+y*y+x*x)<radius) effect->FUN_000fe4d0(a,b);
 }
}