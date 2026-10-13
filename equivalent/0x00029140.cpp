// STATUS: equivalent (tools/equiv.py level 3: 81 inputs, branch coverage 20/22, incomplete)
// FUN_00029140 @ 0x00029140
struct Vec { float x,y,z; };
struct Transform { void FUN_000fddb0(Vec*); };
struct Entity { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void setState(int); virtual int getState(); char pad[0x58-4]; Transform transform; };
struct Position { void FUN_00059a50(Vec*); };
struct Item { char pad0[0x10]; Position* position; char pad1[0x1ca0-0x14]; Entity* entity; char pad2[0x1cbc-0x1ca4]; float radius; bool FUN_00035ab0(); };
struct Manager { Item* FUN_00059c10(int); };
struct Owner { char pad[0x44]; Manager* manager; };
extern "C" double __cdecl sqrt(double);
struct Target { Owner* owner; char pad[8]; int count; int ids[1]; void FUN_00029140(Vec center,float radius); };
void Target::FUN_00029140(Vec center,float radius) {
 int n=count;
 for(int i=0;i<n;++i) {
  if(i<0 || i>=count) continue;
  Item* item=owner->manager->FUN_00059c10(ids[i]);
  if(!item) continue;
  Vec p; item->position->FUN_00059a50(&p);
  if(item->FUN_00035ab0()) continue;
  float r=item->radius;
  if(!(r>0.0f)) continue;
  Entity* entity=item->entity;
  if(!entity) continue;
  Transform* t=&entity->transform;
  if(!t) continue;
  double dx=(double)center.x-p.x,dy=(double)center.y-p.y,dz=(double)center.z-p.z;
  if(!((double)r+radius>sqrt(dz*dz+dy*dy+dx*dx))) continue;
  t->FUN_000fddb0(&center);
  if(entity->getState()<2) entity->setState(2);
 }
}