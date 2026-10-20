// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000f2c10 @ 0x000f2c10
#include "decls/address.h"
#include "decls/data/game/global.h"
namespace pure3d { class VectorCamera; }
namespace content { namespace LoadInventory { template<class T> class DynamicCaster { public: virtual void* cast(void*); }; } }
struct Inventory_f2c10 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void* lookup(content::LoadInventory::DynamicCaster<pure3d::VectorCamera>*, unsigned __int64); };
struct VectorCamera_f2c10 { virtual void init(); virtual void release(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void set(float,float); char pad[12]; float angle; char pad2[188]; unsigned position[3]; VectorCamera_f2c10* FUN_002939a0(); };
struct Timer { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual float time(); };
void* __cdecl FUN_00263ea0(unsigned);
void __cdecl FUN_000f6530(void*,VectorCamera_f2c10*);
void __cdecl FUN_0009f790(float,float,float*,float*);
struct Owner_f2c10 { char pad[0x98c]; float angle; VectorCamera_f2c10* camera; char pad2[0xd4]; unsigned position[3]; unsigned last; void target(const char*); };
void Owner_f2c10::target(const char* name) {
 Inventory_f2c10* inv=(*(Inventory_f2c10**)&DAT_004dd9cc);
 unsigned __int64 key=FUN_0027b020(name);
 content::LoadInventory::DynamicCaster<pure3d::VectorCamera> caster;
 void* found=inv->lookup(&caster,key);
 if(!found) return;
 if(camera) { camera->release(); camera=0; }
 VectorCamera_f2c10* memory=(VectorCamera_f2c10*)FUN_00263ea0(0xf8);
 camera=memory ? memory->FUN_002939a0() : 0;
 camera->init();
 FUN_000f6530(found,camera);
 angle=camera->angle*57.2957763671875f;
 float t=(*(Timer**)&DAT_0052c2a4)->time();
 float a,b;
 FUN_0009f790(angle,t,&a,&b);
 camera->set(a*0.01745329238474369f,1.0f);
 position[0]=camera->position[0]; position[1]=camera->position[1]; position[2]=camera->position[2]; last=0;
}
