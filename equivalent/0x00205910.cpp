// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 14/14)
// FUN_00205910 @ 0x00205910
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/content.h"

struct LoadInventory_nv_205910 {
    content::LoadInventory* FUN_00266480(int);
};
extern "C" void* __cdecl FUN_00263ea0(unsigned int);
extern "C" int __cdecl FUN_00266da0(hulk_intptr);
extern "C" void __cdecl FUN_00266d90();
struct Texture_205910 {
 char pad[0x34];
 unsigned int size;
 char tail[4];
 void FUN_002047c0(const char*, int, int, int);
};
struct Object_205910 {
 char pad0[0x44];
 content::LoadInventory* resource;
 char pad1[0x4f8-0x48];
 Texture_205910 textures[2];
 char pad2[0xaf4-0x570];
 unsigned char flag;
 void FUN_00204e40();
 void target();
};
void Object_205910::target() {
 content::LoadInventory* memory = (content::LoadInventory*)FUN_00263ea0(0x14);
 content::LoadInventory* replacement = memory ? ((LoadInventory_nv_205910*)(memory))->FUN_00266480(0x400) : 0;
 if (replacement) replacement->vfunc_0();
 if (resource) resource->vfunc_1();
 resource = replacement;
 if ((*(unsigned char*)&DAT_004c91d8) || (*(unsigned char*)((char*)&DAT_004c91d8 + 1))) {
 int previous = FUN_00266da0(11);
 FUN_00266d90();
 if ((*(unsigned char*)((char*)&DAT_004c91d8 + 1))) {
 for (int i=0; i<2; ++i) {
 textures[i].size = 0x200;
 textures[i].FUN_002047c0("texture data",19+i,0x32000,11);
 }
 }
 FUN_00204e40();
 flag = 0;
 FUN_00266da0(previous);
 }
}
