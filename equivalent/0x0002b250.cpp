// STATUS: equivalent (tools/equiv.py level 3: 140 inputs, branch coverage 14/14)
// FUN_0002b250 @ 0x0002b250
struct Item_2b250 {
 char pad[8];
 int value8;
 int valueC;
 unsigned char FUN_00036950(int filter);
};
struct Manager_2b250 { Item_2b250* FUN_00059c10(int handle); };
struct Owner_2b250 { char pad[0x44]; Manager_2b250* manager; };
struct Container_2b250 {
 Owner_2b250* owner;
 char pad4[8];
 int count;
 int handles[69];
 Item_2b250* excluded;
 char pad128[0x200];
 int used;
 unsigned char FUN_00024720(int a, int b);
 void FUN_0002a4b0(int index, int flag);
 int FUN_0002b250(int desired, int filter);
};
int Container_2b250::FUN_0002b250(int desired, int filter) {
 int capacity = 32 - used;
 int needed = desired - capacity;
 if (needed <= 0) return capacity;
 int index = count - 1;
 Item_2b250* savedExcluded = excluded;
 int added = 0;
 for (; index >= 0 && added < needed; --index) {
  Item_2b250* item = owner->manager->FUN_00059c10(handles[index]);
  if (item != savedExcluded && item->FUN_00036950(filter) == 1) {
   if (FUN_00024720(item->value8, item->valueC)) ++added;
   FUN_0002a4b0(index, 0);
  }
 }
 return 32 - used;
}
