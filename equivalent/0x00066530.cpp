// STATUS: equivalent (tools/equiv.py level 3: 687 inputs, branch coverage 14/14)
// FUN_00066530 @ 0x00066530
struct ValueSource {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual float slot21();
};
struct Link2 { char pad[0x70]; ValueSource* source; };
struct Link1 { char pad[0x10]; Link2* next; };
struct Entity { char pad0[0xa0]; Link1* link; char pad1[0x114-0xa4]; int state; char pad2[0x1a0-0x118]; unsigned char active; char pad3[0x1ed-0x1a1]; unsigned char flagged; };
struct Manager { Entity* FUN_001dee40(int, int); };
struct Global { char pad[12]; Manager* manager; };
extern Global* DAT_004dd700;
struct Entry { int first; int second; };
struct Owner { char pad[0x390]; int count; int unknown; Entry entries[1]; void FUN_00065ee0(Entry*); void update(); };
void Owner::update() {
 for (int i=0; i<count; ++i) {
  Entry* entry=&entries[i];
  Entity* entity=DAT_004dd700->manager->FUN_001dee40(entry->first,entry->second);
  if (entity) {
   if (entity->link->next->source->slot21() == 0.0f) FUN_00065ee0(entry);
   if (entity->flagged) FUN_00065ee0(entry);
   if (!entity->active) FUN_00065ee0(entry);
   if (entity->state) FUN_00065ee0(entry);
  }
 }
}
