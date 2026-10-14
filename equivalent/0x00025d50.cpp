// STATUS: equivalent (tools/equiv.py level 3: 569 inputs, branch coverage 16/16)
// FUN_00025d50 @ 0x00025d50
struct Vec_25d50 { float x,y,z; };
struct Actor_25d50 { bool FUN_00035ab0(); int FUN_00036d00(); };
struct Entry_25d50 { Actor_25d50* FUN_00059a30(); void FUN_00059a50(Vec_25d50*); };
struct Manager_25d50 { Entry_25d50* FUN_00059ba0(int); Actor_25d50* FUN_00059c10(int); };
struct Owner_25d50 { char pad[0x44]; Manager_25d50* manager; };
extern "C" double __cdecl sqrt(double);
struct Selection_25d50 { Owner_25d50* owner; char pad[8]; int count; int ids[1]; int FUN_00025d50(float x,float y,float z); };
int Selection_25d50::FUN_00025d50(float x,float y,float z) {
 float best=-1.0f; int selected=-1;
 for(int i=0;i<count;++i) {
  Entry_25d50* entry=owner->manager->FUN_00059ba0(ids[i]);
  if(!entry) continue;
  Actor_25d50* actor=entry->FUN_00059a30();
  if(!actor || actor->FUN_00035ab0()) continue;
  Vec_25d50 p; entry->FUN_00059a50(&p);
  double dx=(double)p.x-x, dy=(double)p.y-y, dz=(double)p.z-z;
  double distance=sqrt(dz*dz+dy*dy+dx*dx);
  if(best<0.0f || distance<best) {best=(float)distance;selected=i;}
 }
 if(selected<0) return 0;
 return owner->manager->FUN_00059c10(ids[selected])->FUN_00036d00();
}