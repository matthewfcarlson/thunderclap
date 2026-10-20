// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00088940 @ 0x00088940
// cl-flags: /GS
struct Obj_88940; struct Context; struct Mission_88940;
struct ResourceList { char storage[248]; void FUN_0027a630(); void FUN_0027a6e0(const char*,Obj_88940*); void FUN_0027a570(); };
struct Component_88940 { void FUN_001bdb90(); void FUN_0009a090(); void FUN_00201bb0(); void FUN_001b3f90(Obj_88940*); void FUN_001dbd40(); void FUN_001b68d0(Obj_88940*); void FUN_001063f0(); void FUN_000244a0(ResourceList*); void FUN_001f6c50(Mission_88940*); void FUN_001fac40(void*); void FUN_001faf70(const char*); void FUN_00025eb0(); void FUN_001fc690(); void FUN_001cbf40(Mission_88940*); void FUN_001cd3d0(Mission_88940*); void FUN_000d71f0(Obj_88940*,void*,void*); void FUN_00078c60(); void FUN_001c0ab0(const char*); };
struct Mission_88940 { const char* FUN_000897f0(); const char* FUN_000897e0(); const char* FUN_0008a2d0(); };
struct Other_88940 { void* FUN_000b4ff0(); };
struct Context { void* FUN_00086290(); void* FUN_000862b0(); Other_88940* FUN_00086280(); };
// equiv-conv: _sprintf stack stack stack
extern "C" int __cdecl sprintf(char*,const char*,const char*,const char*);
// equiv-conv: FUN_00267760 stack stack stack stack
int __cdecl FUN_00267760(char*,unsigned,const char*,const char*,const char*);
struct Obj_88940 { char pad0[8]; Component_88940 *p08,*p0c,*p10,*p14,*p18,*p1c,*p20,*p24,*p28,*p2c,*p30,*p34,*p38,*p3c,*p40,*p44,*p48,*p4c,*p50; char pad54[8]; unsigned char flag5c; char pad5d[63]; unsigned char flag9c; void run(Context*,Mission_88940*); };
void Obj_88940::run(Context* context,Mission_88940* mission) {
  flag5c=0; flag9c=0;
 p40->FUN_001bdb90(); p08->FUN_0009a090(); p24->FUN_00201bb0(); p10->FUN_001b3f90(this); p0c->FUN_001dbd40(); p14->FUN_001b68d0(this); p18->FUN_001063f0();
 ResourceList list; list.FUN_0027a630(); p20->FUN_000244a0(&list); list.FUN_0027a6e0("art/global.rdl",this);
 char buffer[255]; const char* b=mission->FUN_000897f0(); const char* a=mission->FUN_000897e0(); sprintf(buffer,"art/locations/%s/%s.rdl",a,b); list.FUN_0027a6e0(buffer,this);
 b=mission->FUN_0008a2d0(); a=mission->FUN_0008a2d0(); sprintf(buffer,"art/missions/%s/%s.rdl",a,b); list.FUN_0027a6e0(buffer,this);
 p38->FUN_001f6c50(mission); p48->FUN_001fac40(p18); p48->FUN_001fac40(p28); p48->FUN_001fac40(p0c); p48->FUN_001fac40(p4c); void* value=context->FUN_00086290(); p48->FUN_001fac40(value);
 b=mission->FUN_000897f0(); a=mission->FUN_000897e0(); FUN_00267760(buffer,255,"art/locations/%s/%s.dh",a,b); p48->FUN_001faf70(buffer);
 b=mission->FUN_0008a2d0(); a=mission->FUN_0008a2d0(); FUN_00267760(buffer,255,"art/missions/%s/%s.dh",a,b); p48->FUN_001faf70(buffer);
 p20->FUN_00025eb0(); p28->FUN_001fc690(); p30->FUN_001cbf40(mission); p2c->FUN_001cd3d0(mission);
 value=context->FUN_000862b0(); Other_88940* other=context->FUN_00086280(); void* result=other->FUN_000b4ff0(); p3c->FUN_000d71f0(this,result,value); p4c->FUN_00078c60(); a=mission->FUN_0008a2d0(); p50->FUN_001c0ab0(a); list.FUN_0027a570();
}