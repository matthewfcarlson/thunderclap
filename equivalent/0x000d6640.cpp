// STATUS: equivalent (tools/equiv.py level 3: 2747 inputs, branch coverage 12/12)
// FUN_000d6640 @ 0x000d6640
typedef unsigned int uint;
void* __cdecl operator new(unsigned int, void* p) { return p; }
extern void* __cdecl FUN_0008d690(uint);
extern void* __cdecl FUN_00263ea0(uint);
extern unsigned char __cdecl FUN_001d04d0(const void*);
extern uint DAT_0048e100, DAT_0048e0f0, DAT_0048e0e4, DAT_0048e128;
struct MessageOverlay;
extern void FUN_000d45e0(); extern void FUN_000d4600(); extern void FUN_000d4720(); extern void FUN_000d4780(); extern void FUN_000d47d0(); extern void FUN_000d4850(); extern void FUN_000d5440(); extern void thunk_FUN_000d4b60(); extern void FUN_000d5fa0();
struct Command_d6640 { virtual void slot0(); char pad4[12]; unsigned char argType; char pad11[7]; unsigned char returnType; char pad19[3]; void (*callback)(); void FUN_001d0480(const char*,int); };
template<class T,class R,class A_d6640> struct Method1 : Command_d6640 { virtual void slot0(); };
template<class T,class R,class A_d6640> struct Closure1 : Method1<T,R,A_d6640> { virtual void slot0(); T* owner; };
struct Manager_d6640 { void FUN_001d3b70(const char*,void*); void FUN_000d6410(const char*,MessageOverlay*,void(*)()); void FUN_000d6470(const char*,MessageOverlay*,void(*)()); void FUN_000d6520(const char*,MessageOverlay*,void(*)()); void FUN_000d65e0(const char*,MessageOverlay*,void(*)()); };
extern Manager_d6640* FUN_001d4c90();
struct A_d6640 { void FUN_000dee40(); char bytes[20]; }; struct B_d6640 { void FUN_000dee10(); char bytes[20]; };
struct Inner_d6640 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(uint,int); };
struct Resource_d6640 { virtual void v0(); char pad[12]; Inner_d6640* inner; Resource_d6640* FUN_0028edb0(); };
struct MessageOverlay { virtual void slot0(); unsigned char busy; char pad5[3]; uint f8,fc,f10; char pad14[0x248-0x14]; unsigned char f248; char pad249[0x484-0x249]; unsigned char f484; char pad485[0x7b0-0x485]; uint f7b0; char pad7b4[12]; Resource_d6640* resource; unsigned char f7c4; char pad7c5[3]; uint f7c8,f7cc; char pad7d0[4]; A_d6640 a; B_d6640 b; char pad7fc[16]; unsigned char f80c; MessageOverlay(); };
MessageOverlay::MessageOverlay() {
 busy=1; f248=0; f484=0; a.FUN_000dee40(); b.FUN_000dee10(); f8=0; fc=0; f7b0=0;
 Resource_d6640* r=(Resource_d6640*)FUN_00263ea0(32); resource=r?r->FUN_0028edb0():0; resource->v0(); resource->inner->v6(0x444d4c42,1);
 f7c4=0; f10=0; f7c8=0; f7cc=0; f80c=1;
 Manager_d6640* m=FUN_001d4c90(); if(m) {
 void* p=FUN_0008d690(36); if(p) { Command_d6640* c=(Command_d6640*)p; c->FUN_001d0480("hud_Message",1); new(p) Method1<MessageOverlay,void,const char*>; c->callback=FUN_000d5fa0; c->returnType=FUN_001d04d0(&DAT_0048e100); c->argType=FUN_001d04d0(&DAT_0048e0f0); Closure1<MessageOverlay,void,const char*>* q=new(p) Closure1<MessageOverlay,void,const char*>; q->owner=this; }
 m->FUN_001d3b70("hud_Message",p); m->FUN_000d6410("hud_MessageEx",this,thunk_FUN_000d4b60); m->FUN_000d6470("hud_ComboMessage",this,FUN_000d4780);
 p=FUN_0008d690(36); if(p) { Command_d6640* c=(Command_d6640*)p; c->FUN_001d0480("hud_PersistentMessages",1); new(p) Method1<MessageOverlay,void,bool>; c->callback=FUN_000d45e0; c->returnType=FUN_001d04d0(&DAT_0048e100); c->argType=FUN_001d04d0(&DAT_0048e0e4); Closure1<MessageOverlay,void,bool>* q=new(p) Closure1<MessageOverlay,void,bool>; q->owner=this; }
 m->FUN_001d3b70("hud_PersistentMessages",p); m->FUN_000d6520("hud_ClearMessages",this,FUN_000d5440);
 p=FUN_0008d690(36); if(p) { Command_d6640* c=(Command_d6640*)p; c->FUN_001d0480("hud_MessageHoldTime",1); new(p) Method1<MessageOverlay,void,float>; c->callback=FUN_000d4600; c->returnType=FUN_001d04d0(&DAT_0048e100); c->argType=FUN_001d04d0(&DAT_0048e128); Closure1<MessageOverlay,void,float>* q=new(p) Closure1<MessageOverlay,void,float>; q->owner=this; }
 m->FUN_001d3b70("hud_MessageHoldTime",p); m->FUN_000d6470("hud_BonusMessage",this,FUN_000d47d0); m->FUN_000d65e0("hud_ComboMessageEx",this,FUN_000d4720);
 p=FUN_0008d690(36); if(p) { Command_d6640* c=(Command_d6640*)p; c->FUN_001d0480("hud_EnableComboMessages",1); new(p) Method1<MessageOverlay,void,bool>; c->callback=FUN_000d4850; c->returnType=FUN_001d04d0(&DAT_0048e100); c->argType=FUN_001d04d0(&DAT_0048e0e4); Closure1<MessageOverlay,void,bool>* q=new(p) Closure1<MessageOverlay,void,bool>; q->owner=this; }
 m->FUN_001d3b70("hud_EnableComboMessages",p); busy=0;
 }
}