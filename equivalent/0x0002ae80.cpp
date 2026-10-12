// STATUS: equivalent (tools/equiv.py level 3: 97 inputs, branch coverage 81/82, incomplete)
// FUN_0002ae80 @ 0x0002ae80
struct Vec { float x,y,z; };
struct Position { bool FUN_00059a50(Vec*); };
struct Bounds { char pad[8]; unsigned char type; char pad2[7]; Vec center; float radius; float distance; };
struct Actor {
 char p0[16]; Position* position; char p1[0x20b0-20]; int state; float timer;
 char p2[0x2144-0x20b8]; int active; char p3[0x22b8-0x2148]; Bounds bounds;
 void FUN_00042960(int,int); void FUN_000366d0(int,int); void FUN_000366f0(int,int); bool FUN_00037410();
};
struct Lookup { Actor* FUN_00059c10(int); };
struct Mode { int FUN_001cc840(); void FUN_001cc620(int); };
struct Owner { char p0[0x2c]; Mode* mode; char p1[0x44-0x30]; Lookup* lookup; };
struct Events { void FUN_001e53d0(Actor*); };
struct LevelData { int FUN_00088fa0(); int FUN_00088fb0(); };
struct Level { char p[0x80]; LevelData data; };
struct Levels { Level* FUN_00086310(); };
struct Game { char p[12]; Events* events; char p2[0x54-16]; Levels* levels; };
extern Game* DAT_004dd700;
struct Debug { void FUN_0023f7b0(Vec*,Vec*,unsigned,int); void FUN_0023f7d0(Vec*,unsigned,float,int); };
extern Debug* DAT_004dd6e8;
struct Manager {
 Owner* owner; char p0[8]; int count; int ids[17]; int flags[16]; int values[19]; int blocked[17]; Actor* mainActor;
 char p1[0x353-0x128]; unsigned char debugLine; Vec start,end; unsigned char debugSphere; char p2[3]; Vec sphere;
 void FUN_00025750(); void FUN_0002a4b0(int,int); void FUN_00025110(float); void FUN_000245b0(); void target(int arg,float dt);
};
void Manager::target(int arg,float dt) {
 for(int i=0;i<count;++i) {
  if((flags[i]&1)&&blocked[i]==0) {
   Actor* a=owner->lookup->FUN_00059c10(ids[i]);
   if(a) a->FUN_00042960(arg,values[i]);
  }
 }
 for(int i=0;i<count;++i) {
  if((flags[i]&1)&&blocked[i]==0) {
   Actor* a=owner->lookup->FUN_00059c10(ids[i]);
   if(a) a->FUN_000366d0(arg,values[i]);
  }
 }
 for(int i=0;i<count;++i) {
  if((flags[i]&1)&&blocked[i]==0) {
   Actor* a=owner->lookup->FUN_00059c10(ids[i]);
   if(a) a->FUN_000366f0(arg,values[i]);
  }
 }
 FUN_00025750();
 Actor* main=mainActor;
 for(int i=count-1;i>=0;--i) {
  Actor* a=owner->lookup->FUN_00059c10(ids[i]);
  if(a) {
   if(a->FUN_00037410()) { FUN_0002a4b0(i,1); continue; }
   if(a->state==1) {
    if(a->active>0) DAT_004dd700->events->FUN_001e53d0(a);
    double t=(double)dt+a->timer;
    a->timer=(float)t;
    if(t>=1.5f) FUN_0002a4b0(i,1);
    continue;
   }
  }
  Vec pos;
  if(!a->position->FUN_00059a50(&pos)) continue;
  float limit=-50.0f;
  if(DAT_004dd700->levels->FUN_00086310()->data.FUN_00088fa0()==10 &&
     DAT_004dd700->levels->FUN_00086310()->data.FUN_00088fb0()==41) limit=-200.0f;
  if(pos.y<=limit) {
   if(a!=main) FUN_0002a4b0(i,1);
   else {
    Mode* m=owner->mode;
    int mode=m->FUN_001cc840();
    if(mode!=2&&mode!=5) m->FUN_001cc620(2);
   }
   continue;
  }
  if(a==main) continue;
  Vec player;
  Bounds* b=&a->bounds;
  if(!main->position->FUN_00059a50(&player) || !b) continue;
  double x=(double)player.x-b->center.x;
  double y=(double)player.y-b->center.y;
  double z=(double)player.z-b->center.z;
  if(b->type!=255 && !(z*z+y*y+x*x > (double)b->radius*b->radius)) continue;
  x=(double)player.x-pos.x;
  y=(double)player.y-pos.y;
  z=(double)player.z-pos.z;
  if(b->distance>0.0f && z*z+y*y+x*x > (double)b->distance*b->distance) FUN_0002a4b0(i,0);
 }
 FUN_00025110(dt);
 FUN_000245b0();
 for(int i=0;i<count;++i) if(flags[i]&1) values[i]=0;
 if(debugLine) {
  DAT_004dd6e8->FUN_0023f7b0(&start,&end,0xffff0000,0);
  if(debugSphere) DAT_004dd6e8->FUN_0023f7d0(&sphere,0xffffffff,0.5f,0);
 }
}
