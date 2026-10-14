// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 20/22, incomplete)
// FUN_0002a3c0 @ 0x0002a3c0
struct Item_2a3c0 { char pad0[8]; int a; int b; int* id; char pad14[0x108]; int category; bool FUN_00035ab0(); };
struct Registry_2a3c0 { Item_2a3c0* FUN_00059c10(int); };
struct Owner_2a3c0 { char pad[0x44]; Registry_2a3c0* registry; };
struct List_2a3c0 {
 Owner_2a3c0* owner; char pad4[8]; int count; int ids[17]; int flags[16]; int extra[17];
 int FUN_00024230(Item_2a3c0*); void FUN_000269f0(int,int);
 int insert(Item_2a3c0* item);
};
int List_2a3c0::insert(Item_2a3c0* item) {
 if(count>=16) return -1;
 if(FUN_00024230(item)>=0) return -1;
 int pos=0;
 for(;pos<count;++pos) {
  if(pos>=0 && pos<count) {
   Item_2a3c0* old=owner->registry->FUN_00059c10(ids[pos]);
   if(old && item->category==old->category) break;
  }
 }
 for(int j=count;j>pos;--j) {
  ids[j]=ids[j-1];
  extra[j]=extra[j-1];
  flags[j]=flags[j-1];
 }
 ids[pos]=*item->id;
 ++count;
 if(!item->FUN_00035ab0()) FUN_000269f0(item->a,item->b);
 flags[pos]=4;
 extra[pos]=0;
 return pos;
}