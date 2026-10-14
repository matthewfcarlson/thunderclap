// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 31/32, incomplete)
// FUN_00231ad0 @ 0x00231ad0
struct Owner_231ad0;
struct Item_231ad0;
struct Node {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual Item_231ad0* query(Item_231ad0*, int);
 virtual int check(Owner_231ad0*, Item_231ad0*, int);
 Node* next; int kind;
};
struct Item_231ad0 { void FUN_00232060(Owner_231ad0*,Item_231ad0*,int,unsigned); void FUN_002320d0(Owner_231ad0*,Item_231ad0*,int); };
extern int __cdecl FUN_00238190(int);
extern int __cdecl FUN_00266da0(int);
extern unsigned DAT_004d9968;
extern void __fastcall __security_check_cookie(unsigned);
struct Owner_231ad0 { char pad[0x28]; Node* head; void FUN_00231ad0(Item_231ad0* input,int arg,unsigned flags); };
void Owner_231ad0::FUN_00231ad0(Item_231ad0* input,int arg,unsigned flags) {
 unsigned cookie=DAT_004d9968;
 int previous=FUN_00266da0(FUN_00238190(3));
 Item_231ad0* items[8]; unsigned char active[8]; int count=0;
 for(Node* node=head;node;node=node->next) {
  Item_231ad0* item=node->query(input,arg);
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