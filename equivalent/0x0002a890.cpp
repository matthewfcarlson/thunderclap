// STATUS: equivalent (tools/equiv.py level 3: 132 inputs, branch coverage 16/18, incomplete)
// FUN_0002a890 @ 0x0002a890
struct Item { void FUN_0003b620(int); };
struct Registry { Item* FUN_00059c10(int); };
struct Owner { char pad[0x44]; Registry* registry; };
struct Component { void FUN_00044c30(); void FUN_00046230(); };
struct Interface { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); };
struct Entry { char pad[0x5c]; Interface* object; };
struct Manager { int FUN_002327c0(); Entry* FUN_00232810(int); };
extern Manager* DAT_004e5af8;
struct Resource { virtual void slot0(); virtual void release(); };
struct Target {
 Owner* owner;
 Component* component;
 int unknown;
 int count;
 int ids[205];
 Resource* resource1;
 Resource* resource2;
 void FUN_0002a800();
 void FUN_0002a890();
};
void Target::FUN_0002a890() {
 for (int i = 0; i < count; ++i) {
  if (i >= 0 && i < count) {
   Item* item = owner->registry->FUN_00059c10(ids[i]);
   if (item) item->FUN_0003b620(1);
  }
 }
 FUN_0002a800();
 component->FUN_00044c30();
 component->FUN_00046230();
 Manager* manager = DAT_004e5af8;
 int n = manager->FUN_002327c0();
 for (int j = 0; j < n; ++j) {
  Interface* object = manager->FUN_00232810(j)->object;
  object->slot6();
  object->slot7();
 }
 if (resource1) { resource1->release(); resource1 = 0; }
 if (resource2) { resource2->release(); resource2 = 0; }
}
