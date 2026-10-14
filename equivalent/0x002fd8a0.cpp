// STATUS: equivalent (tools/equiv.py level 3: 2970 inputs, branch coverage 14/14)
// FUN_002fd8a0 @ 0x002fd8a0
struct Matrix { unsigned int words[16]; };
struct Transform_2fd8a0 { Matrix* FUN_0030f100(); };
struct Item_2fd8a0 { Transform_2fd8a0* FUN_0030edf0(); };
struct Resource_2fd8a0 { virtual void AddRef() = 0; virtual void Release() = 0; int FUN_0030f450(); Item_2fd8a0* FUN_0030f490(int index); };
struct Child_2fd8a0 { char padding[0x24]; int state; void FUN_00312240(Resource_2fd8a0* resource); };
struct Entry_2fd8a0 { Item_2fd8a0* item; char padding[0x1c]; Matrix matrix; char tail[4]; };
struct Owner_2fd8a0 { char padding[0x70]; Child_2fd8a0* child; char padding2[0x14]; Resource_2fd8a0* resource; Entry_2fd8a0* entries; void FUN_002fd8a0(Resource_2fd8a0* incoming); };
void Owner_2fd8a0::FUN_002fd8a0(Resource_2fd8a0* incoming) {
 if (incoming) incoming->AddRef();
 if (resource) resource->Release();
 resource = incoming;
 if (incoming) {
  if (incoming->FUN_0030f450() > 0) {
   int index = 0;
   do {
    Item_2fd8a0* item = resource->FUN_0030f490(index);
    Entry_2fd8a0* entry = &entries[index];
    entry->item = item;
    Transform_2fd8a0* transform = item->FUN_0030edf0();
    Matrix* matrix = transform->FUN_0030f100();
    for (int j = 0; j < 16; ++j) entry->matrix.words[j] = matrix->words[j];
    ++index;
   } while (index < resource->FUN_0030f450());
  }
  Child_2fd8a0* current = child;
  if (current && current->state == 1) current->FUN_00312240(incoming);
 }
}