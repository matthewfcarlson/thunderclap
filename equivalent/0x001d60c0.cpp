// STATUS: equivalent (tools/equiv.py level 3: 571 inputs, branch coverage 20/22, incomplete)
// FUN_001d60c0 @ 0x001d60c0
struct Entry { int unused[2]; int type; int next; };
struct Node { char pad[0x24]; int count; Entry* entries; };
struct Table { char pad[0x1c]; Node** nodes; };
struct Object { char pad[0x90]; Table* table; int FUN_001d5c70(int index); int FUN_001d60c0(); };
int Object::FUN_001d60c0() {
 int total=0;
 int value=FUN_001d5c70(0);
 if(value>0) total=value;
 int history[8]={-1,-1,-1,-1,-1,-1,-1,-1};
 int slot=0, current=0;
 for(int step=0;step<16;++step) {
  history[slot]=current; slot=(slot+1)%8;
  Node* node=table->nodes[current];
  bool found=false;
  for(int i=0;i<node->count;++i) {
   if(node->entries[i].type==13) {
    current=node->entries[i].next;
    found=true;
    if(current==0) return 1000;
    value=FUN_001d5c70(current);
    if(value>0) total+=value;
    for(int j=0;j<8;++j) if(history[j]==current) return 1000;
    break;
   }
  }
  if(!found) break;
 }
 return total;
}