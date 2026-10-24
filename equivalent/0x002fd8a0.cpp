// STATUS: equivalent (tools/equiv.py level 3: 2970 inputs, branch coverage 14/14)
// FUN_002fd8a0 @ 0x002fd8a0
#include "gen/physics.h"

struct Matrix_2fd8a0 { unsigned int words[16]; };
struct Transform_2fd8a0 { Matrix_2fd8a0* FUN_0030f100(); };
struct Item_2fd8a0 { Transform_2fd8a0* FUN_0030edf0(); };
struct Resource_2fd8a0 { virtual void AddRef() = 0; virtual void Release() = 0; int FUN_0030f450(); Item_2fd8a0* FUN_0030f490(int index); };
struct Child_2fd8a0 { char padding[0x24]; int state; void FUN_00312240(Resource_2fd8a0* resource); };
struct Entry_2fd8a0 { Item_2fd8a0* item; char padding[0x1c]; Matrix_2fd8a0 matrix; char tail[4]; };

void physics::SimStateArticulated::FUN_002fd8a0(void* __p0) { Resource_2fd8a0 * incoming = (Resource_2fd8a0 *)__p0;

 if (incoming) incoming->AddRef();
 if ((*(Resource_2fd8a0 * *)&this->f_88)) (*(Resource_2fd8a0 * *)&this->f_88)->Release();
 (*(Resource_2fd8a0 * *)&this->f_88) = incoming;
 if (incoming) {
  if (incoming->FUN_0030f450() > 0) {
   int index = 0;
   do {
    Item_2fd8a0* item = (*(Resource_2fd8a0 * *)&this->f_88)->FUN_0030f490(index);
    Entry_2fd8a0* entry = &(*(Entry_2fd8a0 * *)&this->f_8c)[index];
    entry->item = item;
    Transform_2fd8a0* transform = item->FUN_0030edf0();
    Matrix_2fd8a0* matrix = transform->FUN_0030f100();
    for (int j = 0; j < 16; ++j) entry->matrix.words[j] = matrix->words[j];
    ++index;
   } while (index < (*(Resource_2fd8a0 * *)&this->f_88)->FUN_0030f450());
  }
  Child_2fd8a0* current = (*(Child_2fd8a0 * *)&this->f_70);
  if (current && current->state == 1) current->FUN_00312240(incoming);
 }
}
