// STATUS: equivalent (tools/equiv.py level 3: 132 inputs, branch coverage 16/18, incomplete)
// FUN_0002a890 @ 0x0002a890
struct Item_2a890 { void FUN_0003b620(int); };
struct Registry_2a890 { Item_2a890* FUN_00059c10(int); };
struct Owner_2a890 { char pad[0x44]; Registry_2a890* registry; };
struct Component_2a890 { void FUN_00044c30(); void FUN_00046230(); };
struct Interface_2a890 { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); };
struct Entry_2a890 { char pad[0x5c]; Interface_2a890* object; };
struct Manager_2a890 { int FUN_002327c0(); Entry_2a890* FUN_00232810(int); };
extern Manager_2a890* DAT_004e5af8;
struct Resource_2a890 { virtual void slot0(); virtual void release(); };
struct Target_2a890 {
 Owner_2a890* owner;
 Component_2a890* component;
 int unknown;
 int count;
 int ids[205];
 Resource_2a890* resource1;
 Resource_2a890* resource2;
 void FUN_0002a800();
 void FUN_0002a890();
};
void Target_2a890::FUN_0002a890() {
 for (int i = 0; i < count; ++i) {
  if (i >= 0 && i < count) {
   Item_2a890* item = owner->registry->FUN_00059c10(ids[i]);
   if (item) item->FUN_0003b620(1);
  }
 }
 FUN_0002a800();
 component->FUN_00044c30();
 component->FUN_00046230();
 Manager_2a890* manager = DAT_004e5af8;
 int n = manager->FUN_002327c0();
 for (int j = 0; j < n; ++j) {
  Interface_2a890* object = manager->FUN_00232810(j)->object;
  object->slot6();
  object->slot7();
 }
 if (resource1) { resource1->release(); resource1 = 0; }
 if (resource2) { resource2->release(); resource2 = 0; }
}
