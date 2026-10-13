// STATUS: equivalent (tools/equiv.py level 3: 518 inputs, branch coverage 20/22, incomplete)
// FUN_001d62d0 @ 0x001d62d0
struct Entry { int a,b,type,next; };
struct Node { char pad[0x24]; int count; Entry* entries; };
struct Manager { Node* FUN_001d56f0(int); int FUN_001d5c70(int); };
struct Object { char pad0[0x40]; int start; char pad1[0xa8]; Manager* manager; char pad2[0x18]; int value; int FUN_001d62d0(); };
int Object::FUN_001d62d0() {
 int total=value>0?value:0;
 int current=start;
 int history[8]; for(int i=0;i<8;++i) history[i]=-1;
 int slot=0;
 for(int iteration=0;iteration<16;++iteration) {
  bool found=false;
  history[slot]=current; slot=(slot+1)%8;
  Node* node=manager->FUN_001d56f0(current);
  for(int j=0;j<node->count;++j) {
   Entry* e=&node->entries[j];
   if(e->type==13) {
    current=e->next; found=true;
    if(current==start) return 1000;
    int amount=manager->FUN_001d5c70(current);
    if(amount>0) total+=amount;
    for(int k=0;k<8;++k) if(current==history[k]) return 1000;
    break;
   }
  }
  if(!found) break;
 }
 return total;
}