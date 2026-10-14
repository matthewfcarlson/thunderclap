// STATUS: equivalent (tools/equiv.py level 3: 36 inputs, branch coverage 30/30)
// FUN_00216810 @ 0x00216810
struct Node { char pad[5]; unsigned char flags; };
struct Entry { int type; Node* node; };
struct Record { Node* node; int a,b; };
struct Container {
 char pad0[8]; Entry* entries; int unusedC; Node** nodes; int unused14; Record* records; Node** cleared; Node* root; int clearedCount; int entryCount; int unused2C; int unused30; int nodeCount; int recordCount;
};
void __cdecl FUN_002164b0(void* context, Node* node);
// equiv-conv: FUN_00216810 esi stack
void __cdecl FUN_00216810(Container* self, void* context) {
 if(self->root) self->root->flags &= 0xfc;
 for(int i=0; i<self->entryCount; ++i) {
  Entry& entry=self->entries[i];
  if(entry.type>=4 && (entry.node->flags&3)) FUN_002164b0(context,entry.node);
 }
 for(int j=0; j<self->clearedCount; ++j) {
  Node* n=self->cleared[j]; if(n) n->flags &= 0xfc;
 }
 for(int k=0; k<self->nodeCount; ++k) {
  Node* n=self->nodes[k]; if(n && (n->flags&3)) FUN_002164b0(context,n);
 }
 for(int l=0; l<self->recordCount; ++l) {
  Node* n=self->records[l].node; if(n) n->flags &= 0xfc;
 }
}
