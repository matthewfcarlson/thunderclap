// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_002047c0 @ 0x002047c0
#include "gen/content.h"
struct Resource_2047c0 { virtual void activate(); };
struct LoadInventory_nv_2047c0 {
    content::LoadInventory* FUN_00266480(void*);
};
extern void* __cdecl FUN_00266e00(int, int);
extern Resource_2047c0* __cdecl FUN_0026cfa0(void*, int, int, const char*);
extern void __cdecl FUN_002670b0(int, int, Resource_2047c0*);
extern int __cdecl FUN_00266da0(int);
extern void* __cdecl FUN_00263ea0(unsigned int);
struct Object_2047c0 {
 char prefix[5]; char name[33]; short id; short count; char pad[2]; void* context; Resource_2047c0* resource; void* config; content::LoadInventory* helper;
 void FUN_002047c0(const char* text, int identifier, int mode, int amount);
};
void Object_2047c0::FUN_002047c0(const char* text, int identifier, int mode, int amount) {
 if(id != 0) return;
 id = (short)identifier;
 count = (short)amount;
 char* dest = name;
 do { *dest++ = *text; } while (*text++ != 0);
 if (!context) context = FUN_00266e00(amount, mode);
 resource = FUN_0026cfa0(context, mode, amount, name);
 resource->activate();
 FUN_002670b0(id, amount, resource);
 int old = FUN_00266da0(id);
 content::LoadInventory* p = (content::LoadInventory*)FUN_00263ea0(20);
 if(p) p = ((LoadInventory_nv_2047c0*)(p))->FUN_00266480(config);
 helper = p;
 helper->vfunc_0();
 FUN_00266da0(old);
}