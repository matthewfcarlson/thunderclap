// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// CSmartPropSpawnAction::vfunc_6 @ 0x0001f080
struct Vec3 { float x,y,z; };
struct Ref { virtual void vfunc_0(); virtual void vfunc_1(); };
struct Prop : Ref { void FUN_001d6630(const void*); };
struct Transform { void FUN_00059a50(Vec3*); };
struct ActorData { char pad[16]; Transform* transform; };
struct Actor { ActorData* FUN_00059a30(); };
struct Owner { Actor* FUN_000592a0(); };
struct Descriptor { char pad[16]; char resource[184]; unsigned int flags[2]; };
struct Manager { void FUN_001e5860(char*, const void*, Vec3); Prop* FUN_001def30(char*); };
struct Global { char pad[12]; Manager* manager; };
extern Global* DAT_004dd700;
extern int DAT_004dc018;
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" int __cdecl sprintf(char*, const char*, ...);
struct CSmartPropSpawnAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(int); virtual void vfunc_7(); virtual void vfunc_8();
 char pad[24]; Owner* owner; Descriptor* descriptor; Prop* prop;
};
bool CSmartPropSpawnAction::vfunc_6(int) {
 unsigned int cookie=DAT_004d9968;
 Vec3 position;
 owner->FUN_000592a0()->FUN_00059a30()->transform->FUN_00059a50(&position);
 char name[32];
 int number=DAT_004dc018++;
 sprintf(name,"SpawnedProp%d",number);
 Manager* manager=DAT_004dd700->manager;
 manager->FUN_001e5860(name,descriptor->resource,position);
 Prop* spawned=manager->FUN_001def30(name);
 if (!spawned) { __security_check_cookie(cookie); return false; }
 if (descriptor->flags[0] | descriptor->flags[1]) spawned->FUN_001d6630(descriptor->flags);
 spawned->vfunc_0();
 if(prop) prop->vfunc_1();
 prop=spawned;
 __security_check_cookie(cookie);
 return true;
}