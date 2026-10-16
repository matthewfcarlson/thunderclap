// STATUS: equivalent (tools/equiv.py level 3: 112 inputs, branch coverage 108/120, incomplete)
// FUN_001ed320 @ 0x001ed320
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"

typedef unsigned __int64 ID;
struct V { float x,y,z; float FUN_000259c0(); };
struct Name_1ed320 { unsigned a,b; void FUN_0027b0e0(const char*); void FUN_0027af50(); };
struct Named_1ed320 { char header[8]; Name_1ed320 name; };
struct Info_1ed320 { char p[20]; int flag; ID FUN_000443c0(); const char* FUN_000443b0(); };
struct Position_1ed320 { bool FUN_00059a50(V*); };
struct Entity { char p0[8]; ID id; Position_1ed320* pos; char p14[0x108]; Info_1ed320* info; char p120[8]; int excluded; char p12c[20]; int state; char p144[0x1f4]; Entity* link; char p33c[0x1724]; V origin; char p1a6c[0x221]; unsigned char screaming; char p1c8e[2]; float timer; bool FUN_00035660(V*); };
struct Actor_1ed320 { char p0[8]; ID id; char p10[0xdc]; Named_1ed320* name; char pf0[12]; int state; char p100[20]; void* flag; char p118[48]; Entity* entity; char p14c[125]; unsigned char flag2; V* FUN_001d6b40(); V* FUN_001d77c0(); };
struct Item_1ed320 { char p0[8]; ID id; char p10[84]; V location; };
struct Extra_1ed320 { char p[8]; ID id; V* FUN_00082cf0(); };
struct List_1ed320 { char p[12]; int count; Entity* FUN_00024190(int); bool FUN_00024540(Entity*); };
struct Items_1ed320 { char p[0x3800]; Extra_1ed320* extras[10]; int count; int FUN_00079270(); Item_1ed320* FUN_00079280(int); };
struct Actors { int FUN_001dcf50(); Actor_1ed320* FUN_001dc0b0(int); };
struct Slot_1ed320 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual Actor_1ed320* v5(); };
struct Slots_1ed320 { Slot_1ed320* FUN_001b68e0(int); };
struct World { char p[12]; Actors* actors; char p10[4]; Slots_1ed320* slots; char p18[8]; List_1ed320* list; char p24[40]; Items_1ed320* items; };
struct Renderer_1ed320 { void FUN_001f42d0(ID*,Name_1ed320*,V,V,V,V,int); };
struct Indirect { Renderer_1ed320* renderer; };
struct Manager_1ed320 { Indirect* indirect; void FUN_001eb7e0(ID*,Name_1ed320*,V*,V*,V*,V,int); void FUN_001eb560(const char*); void FUN_001eb6c0(const char*); };
struct Target_1ed320 { World* world; void FUN_001ed0b0(Entity*); void FUN_001ec100(Entity*,const char*); void run(World*,float); };
void Target_1ed320::run(World* w,float dt) {
 if(!DAT_0049caa0) return;
 world=w;
 if(!w) return;
 V velocity,position,delta,origin;
 Name_1ed320 name;
 int count=world->list->count;
 for(int i=0;i<count;++i) {
  Entity* e=world->list->FUN_00024190(i);
  if(!e || !e->pos->FUN_00059a50(&position) || e->excluded || world->list->FUN_00024540(e)) continue;
  int kind;
  if(e->info->FUN_000443c0()==(*(ID*)&DAT_004dc0e0)) kind=1;
  else kind=e->info->flag?2:4;
  e->FUN_00035660(&velocity);
  name.FUN_0027b0e0(e->info->FUN_000443b0());
  (*(Manager_1ed320**)&DAT_004e36d8)->FUN_001eb7e0(&e->id,&name,&position,((V*)&DAT_004e36e4),((V*)&DAT_004c7614),velocity,kind);
  if(e->id==(*(ID*)&DAT_004dc0e0)) {
   FUN_001ed0b0(e);
   if(!(*(unsigned char*)&DAT_004e3708)) {
    if(position.y>100.0f && velocity.FUN_000259c0()<5.0f && e->state!=3) {
     (*(unsigned char*)&DAT_004e3708)=1;
     (*(Manager_1ed320**)&DAT_004e36d8)->FUN_001eb560("city_rooftop");
     (*(Manager_1ed320**)&DAT_004e36d8)->FUN_001eb6c0("city_rooftop");
    }
   } else if(position.y<100.0f) {
    (*(unsigned char*)&DAT_004e3708)=0;
    (*(Manager_1ed320**)&DAT_004e36d8)->FUN_001eb560("city_rooftop_done");
    (*(Manager_1ed320**)&DAT_004e36d8)->FUN_001eb6c0("city_rooftop_done");
   }
  } else if(e->info->FUN_000443c0()==(*(ID*)&DAT_004dc068) || e->info->FUN_000443c0()==(*(ID*)&DAT_004dc0a8) || e->info->FUN_000443c0()==(*(ID*)&DAT_004dc0b8) || e->info->FUN_000443c0()==(*(ID*)&DAT_004dc0c8)) {
   FUN_001ed0b0(e);
  } else {
   int state=e->state;
   if(state==3) e->timer+=dt; else e->timer=0.0f;
   unsigned char screaming=e->screaming;
   Entity* link=e->link;
   if((!screaming && !link && state==3) || (link && link->id==(*(ID*)&DAT_004dc0e0))) {
    origin=e->origin;
    e->pos->FUN_00059a50(&delta);
    delta.x-=origin.x;
    double height=(double)delta.y-origin.y;
    delta.y=(float)height;
    delta.z-=origin.z;
    if(height>15.0f || (!e->link && e->timer>2.5f)) {
     e->screaming=1;
     FUN_001ec100(e,"screaming");
    }
   } else if(screaming && state!=3 && !link) {
    e->screaming=0; e->timer=0.0f;
   }
  }
  name.FUN_0027af50();
 }
 count=world->items->FUN_00079270();
 for(int i=0;i<count;++i) {
  Item_1ed320* e=world->items->FUN_00079280(i);
  if(e) {
   origin=e->location;
   name.FUN_0027b0e0("civilians");
   (*(Manager_1ed320**)&DAT_004e36d8)->FUN_001eb7e0(&e->id,&name,&origin,((V*)&DAT_004e36e4),((V*)&DAT_004c7614),(*(V*)&DAT_004e36e4),6);
   name.FUN_0027af50();
  }
 }
 if(world->actors) {
  count=world->actors->FUN_001dcf50();
  for(int i=0;i<count;++i) {
   Actor_1ed320* a=world->actors->FUN_001dc0b0(i);
   if(!a || a->state==2 || a->state==3) continue;
   Entity* e=a->entity;
   bool valid=false;
   if(e) valid=e->FUN_00035660(&velocity);
   position=*a->FUN_001d6b40();
   if(!valid) velocity=*a->FUN_001d77c0();
   int kind=a->flag||a->flag2?3:(e?2:5);
   (*(Manager_1ed320**)&DAT_004e36d8)->FUN_001eb7e0(&a->id,&a->name->name,&position,((V*)&DAT_004e36e4),((V*)&DAT_004c7614),velocity,kind);
  }
 }
 if(world->slots) {
  for(int i=0;i<32;++i) {
   Slot_1ed320* slot=world->slots->FUN_001b68e0(i);
   if(!slot) continue;
   Actor_1ed320* a=slot->v5();
   if(!a) continue;
   position=*a->FUN_001d6b40();
   velocity=*a->FUN_001d77c0();
   (*(Manager_1ed320**)&DAT_004e36d8)->indirect->renderer->FUN_001f42d0(&a->id,&a->name->name,position,(*(V*)&DAT_004e36e4),(*(V*)&DAT_004c7614),velocity,3);
  }
 }
 count=world->items->count;
 for(int i=0;i<count;++i) {
  Extra_1ed320* e=world->items->extras[i];
  if(e) {
   V location=*e->FUN_00082cf0();
   name.FUN_0027b0e0("civilians");
   (*(Manager_1ed320**)&DAT_004e36d8)->indirect->renderer->FUN_001f42d0(&e->id,&name,location,(*(V*)&DAT_004e36e4),(*(V*)&DAT_004c7614),(*(V*)&DAT_004e36e4),6);
   name.FUN_0027af50();
  }
 }
}
