// STATUS: equivalent (tools/equiv.py level 3: 3036 inputs, branch coverage 29/30, incomplete)
// FUN_0003a9d0 @ 0x0003a9d0
struct Vec3 { float x,y,z; };
struct Entity { char pad[0x114]; void* owner; int FUN_001d64a0(); };
struct Target { virtual void retain(); virtual void release(); int unused; Entity* entity; int type; };
struct Position { bool FUN_00059a50(Vec3*); };
struct Height { char pad[0x2c]; float offset; };
struct Actor {
 char pad0[0x10]; Position* position;
 char pad1[0x108]; Height* height;
 char pad2[0xc]; void* owner;
 char pad3[0x274]; Target* current;
 bool FUN_0003a830(Target*, Vec3*);
 bool FUN_00038de0(Vec3*, Vec3*, int, int, Vec3*, Vec3*, Target**, int);
 bool FUN_0003a9d0(Target*);
};
bool Actor::FUN_0003a9d0(Target* target) {
 if (target && target != current && target->type == 5) {
  Entity* entity = target->entity;
  int state = entity->FUN_001d64a0();
  if (entity->owner && entity->owner != owner) return false;
  if (state != 5 && state != 0) {
   Vec3 start = {0.0f,0.0f,0.0f};
   if (!position->FUN_00059a50(&start)) return false;
   if (height) start.y += height->offset;
   Vec3 end;
   if (!FUN_0003a830(target,&end)) return false;
   Vec3 auxiliary, hit;
   Target* found = 0;
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
