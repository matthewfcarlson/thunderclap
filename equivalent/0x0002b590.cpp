// STATUS: equivalent (tools/equiv.py level 3: 437 inputs, branch coverage 28/28)
// FUN_0002b590 @ 0x0002b590
struct Item {
 char pad[0x1d78];
 unsigned char protectedFlag;
 char pad2[7];
 int priority;
 void FUN_00036a20();
 void FUN_0003e640();
};
struct Registry { Item* FUN_00059c10(int id); };
struct Owner { char pad[0x44]; Registry* registry; };
extern unsigned char DAT_0048e0e1;
struct Manager {
 Owner* owner;
 char pad[8];
 int count;
 int ids[69];
 Item* preserved;
 char pad2[0x204];
 int limit;
 void FUN_0002a4b0(int index,int flag);
 void FUN_0002b590();
};
void Manager::FUN_0002b590() {
 for (int i=0;i<count;++i) {
  Item* item=owner->registry->FUN_00059c10(ids[i]);
  if(item) {
   item->FUN_00036a20();
   item->FUN_0003e640();
  }
 }
 Item* keep=preserved;
 while(count>limit) {
  int best=0x7fffffff;
  int index=-1;
  for(int j=0;j<count;++j) {
   Item* item=owner->registry->FUN_00059c10(ids[j]);
   if(item!=keep && !item->protectedFlag && item->priority<=best) {
    best=item->priority;
    index=j;
   }
  }
  if(index==-1 || best==0x7fffffff) {
   if(DAT_0048e0e1) DAT_0048e0e1=0;
   break;
  }
  FUN_0002a4b0(index,0);
 }
 if(count<=limit) DAT_0048e0e1=1;
}
