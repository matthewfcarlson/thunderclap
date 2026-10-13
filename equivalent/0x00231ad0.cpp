// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 31/32, incomplete)
// FUN_00231ad0 @ 0x00231ad0
struct Owner;
struct Item;
struct Node {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual Item* query(Item*, int);
 virtual int check(Owner*, Item*, int);
 Node* next; int kind;
};
struct Item { void FUN_00232060(Owner*,Item*,int,unsigned); void FUN_002320d0(Owner*,Item*,int); };
extern int __cdecl FUN_00238190(int);
extern int __cdecl FUN_00266da0(int);
extern unsigned DAT_004d9968;
extern void __fastcall __security_check_cookie(unsigned);
struct Owner { char pad[0x28]; Node* head; void FUN_00231ad0(Item* input,int arg,unsigned flags); };
void Owner::FUN_00231ad0(Item* input,int arg,unsigned flags) {
 unsigned cookie=DAT_004d9968;
 int previous=FUN_00266da0(FUN_00238190(3));
 Item* items[8]; unsigned char active[8]; int count=0;
 for(Node* node=head;node;node=node->next) {
  Item* item=node->query(input,arg);
  if(!item) continue;
  int index=0;
  while(index<count && items[index]!=item) ++index;
  if(index==count && count<8) { items[count]=item; active[count]=0; ++count; }
  if(index>=count) continue;
  if(node->kind==0) active[index]=1;
  else if(node->kind==3 && !node->check(this,item,arg)) active[index]=1;
 }
 for(int i=0;i<count;++i) {
  if(active[i]) items[i]->FUN_00232060(this,input,arg,items[i]==input?flags:0x80000000U);
  else items[i]->FUN_002320d0(this,input,arg);
 }
 FUN_00266da0(previous);
 __security_check_cookie(cookie);
}