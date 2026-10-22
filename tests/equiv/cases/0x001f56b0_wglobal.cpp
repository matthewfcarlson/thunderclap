// STATUS: equivalent (tools/equiv.py level 3: 20011 inputs, branch coverage 16/16)
// FUN_001f56b0 @ 0x001f56b0
#include "decls/data/game/global.h"
struct Resource_1f56b0 {
 char pad0[4]; void* handle; void* owner; char pad12[12]; int active;
 void FUN_001f3400(int);
 void FUN_001f4940();
 void FUN_001f34f0();
 void FUN_001f32b0(void*,int,int);
 void FUN_001f3370(int*);
 void FUN_001f33b0(int);
};
extern bool __cdecl FUN_00249b40(void*);
extern int __cdecl FUN_002673a0(const char*,int);
extern void __cdecl FUN_00247890(void*,float);
extern void __cdecl thunk_FUN_00270a50();
extern void __cdecl FUN_002656a0();
extern void __cdecl FUN_0024a800(void*,int);
struct Object {
 char pad0[0xc8]; Resource_1f56b0* resource; char padcc[0x334-0xcc]; float scale;
 bool FUN_001f56b0(void* owner,int value);
};
bool Object::FUN_001f56b0(void* owner,int value) {
 if (!resource || !owner) return false;
 if (resource->handle && !FUN_00249b40(resource->handle)) {
 resource->FUN_001f3400(0); resource->FUN_001f4940();
 }
 if (resource->active) {
 if (resource->owner == owner) return false;
 resource->FUN_001f3400(0); resource->FUN_001f4940();
 }
 resource->FUN_001f34f0();
 resource->FUN_001f32b0(owner,0,0);
 int init = FUN_002673a0("init",0);
 resource->FUN_001f3370(&init);
 resource->FUN_001f33b0(value);
 if (resource->handle) FUN_00247890(resource->handle,DAT_004c7df8 * scale * 0.01f);
 if (!resource->active) return false;
 thunk_FUN_00270a50();
 FUN_002656a0();
 FUN_0024a800(resource->handle,0);
 return true;
}
