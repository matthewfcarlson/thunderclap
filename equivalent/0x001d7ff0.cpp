// STATUS: equivalent (tools/equiv.py level 3: 2975 inputs, branch coverage 26/26)
// FUN_001d7ff0 @ 0x001d7ff0
struct Owner_1d7ff0;
struct Slots_1d7ff0 {
 Owner_1d7ff0* FUN_00035ef0(int);
 void FUN_0003acf0(int,int,int,int,int,int);
 void* FUN_00036c60(int);
};
struct Link_1d7ff0 { char pad[8]; Slots_1d7ff0* slots; int kind; };
struct Resource_1d7ff0 { char pad[16]; void* identity; };
struct Flag_1d7ff0 { char pad[0xa8]; unsigned char enabled; };
struct Disposable { virtual void unused(); virtual void release(); };
struct Manager_1d7ff0 { void FUN_0027ffb0(void*); };
Manager_1d7ff0* __cdecl FUN_0027f250();
struct Context {
 char pad[0x328]; void* selected;
 char pad2[0x78]; void* active;
 void FUN_0003a9d0(int);
 void FUN_0003ffa0(int,int);
};
struct Root_1d7ff0 { char pad[12]; Context* context; };
Root_1d7ff0* __cdecl FUN_001b6580();
struct Owner_1d7ff0 {
 char p0[0xa0]; Resource_1d7ff0* resource;
 char p1[0x58]; int state;
 char p2[0x14]; Link_1d7ff0* link;
 char p3[4]; Flag_1d7ff0* flag;
 char p4[0xbc]; Disposable* disposable;
 char p5[0xd]; unsigned char marked;
 void FUN_001d7ee0(int);
 void target();
};
void Owner_1d7ff0::target() {
 if (link) {
  if (link->kind == 1) {
   Slots_1d7ff0* slots = link->slots;
   for (int i=0;i<8;++i) {
    if (slots->FUN_00035ef0(i)==this) {
     slots->FUN_0003acf0(i,0,-1,0,0,0);
     if(marked) {
      Manager_1d7ff0* manager=FUN_0027f250();
      void* entry=slots->FUN_00036c60(i+20);
      manager->FUN_0027ffb0(entry);
      marked=0;
     }
    }
   }
  }
  FUN_001d7ee0(0);
 }
 Context* context=FUN_001b6580()->context;
 if(context) {
  if(context->active==(resource ? resource->identity : 0)) context->FUN_0003a9d0(0);
  if(context->selected==(resource ? resource->identity : 0)) context->FUN_0003ffa0(0,0);
 }
 if(state!=3) state=2;
 if(flag) flag->enabled=0;
 if(disposable) disposable->release();
 disposable=0;
}
