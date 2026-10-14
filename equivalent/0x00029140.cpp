// STATUS: equivalent (tools/equiv.py level 3: 81 inputs, branch coverage 20/22, incomplete)
// FUN_00029140 @ 0x00029140
struct Vec_29140 { float x,y,z; };
struct Transform_29140 { void FUN_000fddb0(Vec_29140*); };
struct Entity { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void setState(int); virtual int getState(); char pad[0x58-4]; Transform_29140 transform; };
struct Position_29140 { void FUN_00059a50(Vec_29140*); };
struct Item_29140 { char pad0[0x10]; Position_29140* position; char pad1[0x1ca0-0x14]; Entity* entity; char pad2[0x1cbc-0x1ca4]; float radius; bool FUN_00035ab0(); };
struct Manager_29140 { Item_29140* FUN_00059c10(int); };
struct Owner_29140 { char pad[0x44]; Manager_29140* manager; };
extern "C" double __cdecl sqrt(double);
struct Target_29140 { Owner_29140* owner; char pad[8]; int count; int ids[1]; void FUN_00029140(Vec_29140 center,float radius); };
void Target_29140::FUN_00029140(Vec_29140 center,float radius) {
 int n=count;
 for(int i=0;i<n;++i) {
  if(i<0 || i>=count) continue;
  Item_29140* item=owner->manager->FUN_00059c10(ids[i]);
  if(!item) continue;
  Vec_29140 p; item->position->FUN_00059a50(&p);
  if(item->FUN_00035ab0()) continue;
  float r=item->radius;
  if(!(r>0.0f)) continue;
  Entity* entity=item->entity;
  if(!entity) continue;
  Transform_29140* t=&entity->transform;
  if(!t) continue;
  double dx=(double)center.x-p.x,dy=(double)center.y-p.y,dz=(double)center.z-p.z;
  if(!((double)r+radius>sqrt(dz*dz+dy*dy+dx*dx))) continue;
  t->FUN_000fddb0(&center);
  if(entity->getState()<2) entity->setState(2);
 }
}