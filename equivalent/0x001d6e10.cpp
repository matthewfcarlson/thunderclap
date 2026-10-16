// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 22/22)
// FUN_001d6e10 @ 0x001d6e10
#include "decls/address.h"
struct Entry_1d6e10;
struct Owner_1d6e10;
struct Resource_1d6e10 {
 Entry_1d6e10* FUN_00035b60();
};
struct Entry_1d6e10 {
 virtual void AddRef();
 virtual void Release();
 unsigned int reserved;
 union { Resource_1d6e10* resource; Owner_1d6e10* owner; } value;
 unsigned int type;
};
struct Manager_1d6e10 { bool FUN_000242d0(Resource_1d6e10*); };
struct World { char pad[0x20]; Manager_1d6e10* manager; };
void __cdecl FUN_00018810(Entry_1d6e10**, Entry_1d6e10*);
struct Owner_1d6e10 {
 char pad[0x24c];
 Entry_1d6e10* entry;
 void FUN_001d6e10(Entry_1d6e10* incoming);
};
void Owner_1d6e10::FUN_001d6e10(Entry_1d6e10* incoming) {
 if (entry && entry->type == 1 && DAT_004dd700->manager->FUN_000242d0(entry->value.resource)) return;
 if (incoming) incoming->AddRef();
 if (entry) entry->Release();
 entry = incoming;
 if (!incoming) return;
 if (incoming->type == 5) {
  Entry_1d6e10* nested = incoming->value.owner->entry;
  if (nested) FUN_00018810(&entry, nested);
 } else if (incoming->type == 1) {
  Resource_1d6e10* resource = incoming->value.resource;
  if (!DAT_004dd700->manager->FUN_000242d0(resource) && resource->FUN_00035b60())
   FUN_00018810(&entry, resource->FUN_00035b60());
 }
}
