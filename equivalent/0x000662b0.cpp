// STATUS: equivalent (tools/equiv.py level 3: 376 inputs, branch coverage 14/14)
// FUN_000662b0 @ 0x000662b0
#include "decls/address.h"
struct Entity { char pad[0x1b0c]; float value; char pad2[0x94]; unsigned char active; };
struct Manager_662b0 { Entity* FUN_00024280(unsigned int a, unsigned int b); };
struct World { char pad[0x20]; Manager_662b0* manager; };
struct Entry_662b0 { unsigned int a,b; };
struct Object { char pad[0x170]; Entry_662b0 entries[40]; int count; bool FUN_000662b0(); };
bool Object::FUN_000662b0() {
 for (int i=0; i<count; ++i) {
  Entity* e=DAT_004dd700->manager->FUN_00024280(entries[i].a,entries[i].b);
  if(e && !(e->value < 0.0f)) {
   if(e->active) return true;
  } else {
   for(int j=i+1;j<count;++j) { entries[j-1].a=entries[j].a; entries[j-1].b=entries[j].b; }
   --count; --i;
  }
 }
 return false;
}