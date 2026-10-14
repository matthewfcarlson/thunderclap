// STATUS: equivalent (tools/equiv.py level 3: 2970 inputs, branch coverage 14/14)
// FUN_002fd8a0 @ 0x002fd8a0
struct Matrix { unsigned int words[16]; };
struct Transform { Matrix* FUN_0030f100(); };
struct Item { Transform* FUN_0030edf0(); };
struct Resource { virtual void AddRef() = 0; virtual void Release() = 0; int FUN_0030f450(); Item* FUN_0030f490(int index); };
struct Child { char padding[0x24]; int state; void FUN_00312240(Resource* resource); };
struct Entry { Item* item; char padding[0x1c]; Matrix matrix; char tail[4]; };
struct Owner { char padding[0x70]; Child* child; char padding2[0x14]; Resource* resource; Entry* entries; void FUN_002fd8a0(Resource* incoming); };
void Owner::FUN_002fd8a0(Resource* incoming) {
 if (incoming) incoming->AddRef();
 if (resource) resource->Release();
 resource = incoming;
 if (incoming) {
  if (incoming->FUN_0030f450() > 0) {
   int index = 0;
   do {
    Item* item = resource->FUN_0030f490(index);
    Entry* entry = &entries[index];
    entry->item = item;
    Transform* transform = item->FUN_0030edf0();
    Matrix* matrix = transform->FUN_0030f100();
    for (int j = 0; j < 16; ++j) entry->matrix.words[j] = matrix->words[j];
    ++index;
   } while (index < resource->FUN_0030f450());
  }
  Child* current = child;
  if (current && current->state == 1) current->FUN_00312240(incoming);
 }
}