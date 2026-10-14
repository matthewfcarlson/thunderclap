// STATUS: equivalent (tools/equiv.py level 3: 3036 inputs, branch coverage 29/30, incomplete)
// FUN_0003a9d0 @ 0x0003a9d0
struct Vec3_3a9d0 { float x,y,z; };
struct Entity { char pad[0x114]; void* owner; int FUN_001d64a0(); };
struct Target_3a9d0 { virtual void retain(); virtual void release(); int unused; Entity* entity; int type; };
struct Position_3a9d0 { bool FUN_00059a50(Vec3_3a9d0*); };
struct Height { char pad[0x2c]; float offset; };
struct Actor_3a9d0 {
 char pad0[0x10]; Position_3a9d0* position;
 char pad1[0x108]; Height* height;
 char pad2[0xc]; void* owner;
 char pad3[0x274]; Target_3a9d0* current;
 bool FUN_0003a830(Target_3a9d0*, Vec3_3a9d0*);
 bool FUN_00038de0(Vec3_3a9d0*, Vec3_3a9d0*, int, int, Vec3_3a9d0*, Vec3_3a9d0*, Target_3a9d0**, int);
 bool FUN_0003a9d0(Target_3a9d0*);
};
bool Actor_3a9d0::FUN_0003a9d0(Target_3a9d0* target) {
 if (target && target != current && target->type == 5) {
  Entity* entity = target->entity;
  int state = entity->FUN_001d64a0();
  if (entity->owner && entity->owner != owner) return false;
  if (state != 5 && state != 0) {
   Vec3_3a9d0 start = {0.0f,0.0f,0.0f};
   if (!position->FUN_00059a50(&start)) return false;
   if (height) start.y += height->offset;
   Vec3_3a9d0 end;
   if (!FUN_0003a830(target,&end)) return false;
   Vec3_3a9d0 auxiliary, hit;
   Target_3a9d0* found = 0;
   if (FUN_00038de0(&start,&end,0,1,&hit,&auxiliary,&found,0)) {
    if (!found || found != target) return false;
   }
  }
 }
 if (target) target->retain();
 if (current) current->release();
 current = target;
 return true;
}
