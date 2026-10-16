// STATUS: equivalent (tools/equiv.py level 3: 687 inputs, branch coverage 14/14)
// FUN_00066530 @ 0x00066530
#include "decls/address.h"
struct ValueSource {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual float slot21();
};
struct Link2_66530 { char pad[0x70]; ValueSource* source; };
struct Link1_66530 { char pad[0x10]; Link2_66530* next; };
struct Entity { char pad0[0xa0]; Link1_66530* link; char pad1[0x114-0xa4]; int state; char pad2[0x1a0-0x118]; unsigned char active; char pad3[0x1ed-0x1a1]; unsigned char flagged; };
struct Manager_66530 { Entity* FUN_001dee40(int, int); };
struct World { char pad[12]; Manager_66530* manager; };
struct Entry_66530 { int first; int second; };
struct Owner_66530 { char pad[0x390]; int count; int unknown; Entry_66530 entries[1]; void FUN_00065ee0(Entry_66530*); void update(); };
void Owner_66530::update() {
 for (int i=0; i<count; ++i) {
  Entry_66530* entry=&entries[i];
  Entity* entity=DAT_004dd700->manager->FUN_001dee40(entry->first,entry->second);
  if (entity) {
   if (entity->link->next->source->slot21() == 0.0f) FUN_00065ee0(entry);
   if (entity->flagged) FUN_00065ee0(entry);
   if (!entity->active) FUN_00065ee0(entry);
   if (entity->state) FUN_00065ee0(entry);
  }
 }
}
