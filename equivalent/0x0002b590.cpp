// STATUS: equivalent (tools/equiv.py level 3: 437 inputs, branch coverage 28/28)
// FUN_0002b590 @ 0x0002b590
struct Item_2b590 {
 char pad[0x1d78];
 unsigned char protectedFlag;
 char pad2[7];
 int priority;
 void FUN_00036a20();
 void FUN_0003e640();
};
struct Registry_2b590 { Item_2b590* FUN_00059c10(int id); };
struct Owner_2b590 { char pad[0x44]; Registry_2b590* registry; };
extern unsigned char DAT_0048e0e1;
struct Manager_2b590 {
 Owner_2b590* owner;
 char pad[8];
 int count;
 int ids[69];
 Item_2b590* preserved;
 char pad2[0x204];
 int limit;
 void FUN_0002a4b0(int index,int flag);
 void FUN_0002b590();
};
void Manager_2b590::FUN_0002b590() {
 for (int i=0;i<count;++i) {
  Item_2b590* item=owner->registry->FUN_00059c10(ids[i]);
  if(item) {
   item->FUN_00036a20();
   item->FUN_0003e640();
  }
 }
 Item_2b590* keep=preserved;
 while(count>limit) {
  int best=0x7fffffff;
  int index=-1;
  for(int j=0;j<count;++j) {
   Item_2b590* item=owner->registry->FUN_00059c10(ids[j]);
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
