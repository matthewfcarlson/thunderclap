// STATUS: equivalent (tools/equiv.py level 3: 2975 inputs, branch coverage 26/26)
// FUN_001d7ff0 @ 0x001d7ff0
struct Owner;
struct Slots {
 Owner* FUN_00035ef0(int);
 void FUN_0003acf0(int,int,int,int,int,int);
 void* FUN_00036c60(int);
};
struct Link { char pad[8]; Slots* slots; int kind; };
struct Resource { char pad[16]; void* identity; };
struct Flag { char pad[0xa8]; unsigned char enabled; };
struct Disposable { virtual void unused(); virtual void release(); };
struct Manager { void FUN_0027ffb0(void*); };
Manager* __cdecl FUN_0027f250();
struct Context {
 char pad[0x328]; void* selected;
 char pad2[0x78]; void* active;
 void FUN_0003a9d0(int);
 void FUN_0003ffa0(int,int);
};
struct Root { char pad[12]; Context* context; };
Root* __cdecl FUN_001b6580();
struct Owner {
 char p0[0xa0]; Resource* resource;
 char p1[0x58]; int state;
 char p2[0x14]; Link* link;
 char p3[4]; Flag* flag;
 char p4[0xbc]; Disposable* disposable;
 char p5[0xd]; unsigned char marked;
 void FUN_001d7ee0(int);
 void target();
};
void Owner::target() {
 if (link) {
  if (link->kind == 1) {
   Slots* slots = link->slots;
   for (int i=0;i<8;++i) {
    if (slots->FUN_00035ef0(i)==this) {
     slots->FUN_0003acf0(i,0,-1,0,0,0);
     if(marked) {
      Manager* manager=FUN_0027f250();
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
