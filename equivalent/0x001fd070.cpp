// STATUS: equivalent (tools/equiv.py level 3: 424 inputs, branch coverage 12/12)
// FUN_001fd070 @ 0x001fd070
struct Item { char data[0x40]; };
struct Group { int count; Item* items; };
struct State {
 char pad[0x458]; int enabled; char tail[0xc70-0x45c];
 bool FUN_001f8740(int type);
 void FUN_001f8fe0(Item* item);
};
struct Owner {
 char pad[0x214]; Group* groups[6]; char gap[8]; State* states;
 void target(int index);
};
void Owner::target(int index) {
 if (!states[index].enabled) return;
 for (int type=0; type<6; ++type) {
  for (int group=0; group<20; ++group) {
   for (int n=0; n<groups[type][group].count; ++n) {
    if (states[index].FUN_001f8740(type)) {
     Item* item = &groups[type][group].items[n];
     states[index].FUN_001f8fe0(item);
    }
   }
  }
 }
}
