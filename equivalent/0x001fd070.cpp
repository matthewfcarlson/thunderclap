// STATUS: equivalent (tools/equiv.py level 3: 424 inputs, branch coverage 12/12)
// FUN_001fd070 @ 0x001fd070
struct Item_1fd070 { char data[0x40]; };
struct Group_1fd070 { int count; Item_1fd070* items; };
struct State_1fd070 {
 char pad[0x458]; int enabled; char tail[0xc70-0x45c];
 bool FUN_001f8740(int type);
 void FUN_001f8fe0(Item_1fd070* item);
};
struct Owner_1fd070 {
 char pad[0x214]; Group_1fd070* groups[6]; char gap[8]; State_1fd070* states;
 void target(int index);
};
void Owner_1fd070::target(int index) {
 if (!states[index].enabled) return;
 for (int type=0; type<6; ++type) {
  for (int group=0; group<20; ++group) {
   for (int n=0; n<groups[type][group].count; ++n) {
    if (states[index].FUN_001f8740(type)) {
     Item_1fd070* item = &groups[type][group].items[n];
     states[index].FUN_001f8fe0(item);
    }
   }
  }
 }
}
