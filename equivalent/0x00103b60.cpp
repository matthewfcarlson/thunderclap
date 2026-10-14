// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00103b60 @ 0x00103b60
struct Target;
struct Vector { float x,y,z; };
struct Source { void FUN_00059a50(Vector*); };
struct View { char pad[0x10]; Source* source; };
struct Provider { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual View* v6(); };
struct Resource { int FUN_00106160(int); };
struct Lookup { Resource* FUN_00106230(const char*); };
struct Context { char pad[0x18]; Lookup* lookup; };
struct Manager { void FUN_001048d0(Target*); int FUN_00104c60(Context*,Vector*,int,int,unsigned int,int,int); };
extern "C" int __cdecl FUN_000964a0(char*,int,const char*,...);
struct Target {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
 int pad4; int state; char padC[0x4c]; Provider* provider; Manager* manager; Resource* resource; char name[0x40]; unsigned char enabled; char padA5[0x13]; int selection; int option; unsigned char flag; char padC1[3]; int extra;
 void FUN_00103a50();
 int target(Context* context,const char* text,unsigned char mode);
};
int Target::target(Context* context,const char* text,unsigned char mode) {
 v9();
 FUN_000964a0(name,0x40,"%s",text);
 resource=context->lookup->FUN_00106230(name);
 if (!resource) { name[0]=0; state=0; return 0; }
 enabled=1;
 Vector position;
 provider->v6()->source->FUN_00059a50(&position);
 if(mode) { selection=0; manager->FUN_001048d0(this); } else FUN_00103a50();
 int result=resource->FUN_00106160(selection);
 return manager->FUN_00104c60(context,&position,result,option,flag,extra,0);
}