// STATUS: equivalent (tools/equiv.py level 3: 201 inputs, branch coverage 14/14)
// FUN_001fe280 @ 0x001fe280
#include "decls/address.h"
struct Vec_1fe280 { float x,y,z; };
struct Item_1fe280 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual Vec_1fe280* position(Vec_1fe280*);
 char pad[60];
 const char* FUN_001fba60();
};
struct List_1fe280 { int count; Item_1fe280* items; };
struct Lookup_1fe280 { void FUN_00026c30(Vec_1fe280*, const char*); };
struct State_1fe280 { char pad[0x59c]; int key; };
struct Manager_1fe280 { State_1fe280* FUN_000862a0(); };
struct World { char pad[0x20]; Lookup_1fe280* lookup; char gap[0x30]; Manager_1fe280* manager; };
extern "C" double __cdecl sqrt(double);
struct Target_1fe280 {
 char pad[0x20c]; List_1fe280 fallback; List_1fe280* lists[6]; int* keys;
 int FUN_001fd390(int);
 const char* FUN_001fe280(int);
};
const char* Target_1fe280::FUN_001fe280(int arg) {
 Vec_1fe280 origin; DAT_004dd700->lookup->FUN_00026c30(&origin,"hulk");
 int index=FUN_001fd390(arg);
 int count=0; Item_1fe280* items=0;
 if(index<0) { count=fallback.count; items=fallback.items; }
 else { int key=DAT_004dd700->manager->FUN_000862a0()->key;
 for(int i=0;i<20;++i) if(keys[i]==key) { count=lists[index][i].count; items=lists[index][i].items; break; }
 }
 Item_1fe280* selected=0;
 for(int n=0;n<count;++n) { Vec_1fe280 temp; Vec_1fe280* p=items[n].position(&temp);
 double x=(double)origin.x-p->x, y=(double)origin.y-p->y, z=(double)origin.z-p->z;
 if(sqrt(z*z+y*y+x*x)<999999.0f) selected=&items[n];
 }
 if(selected) return selected->FUN_001fba60();
 return "none";
}