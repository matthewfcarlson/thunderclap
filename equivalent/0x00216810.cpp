// STATUS: equivalent (tools/equiv.py level 3: 36 inputs, branch coverage 30/30)
// FUN_00216810 @ 0x00216810
struct Node { char pad[5]; unsigned char flags; };
struct Entry_216810 { int type; Node* node; };
struct Record_216810 { Node* node; int a,b; };
struct Container_216810 {
 char pad0[8]; Entry_216810* entries; int unusedC; Node** nodes; int unused14; Record_216810* records; Node** cleared; Node* root; int clearedCount; int entryCount; int unused2C; int unused30; int nodeCount; int recordCount;
};
extern "C" void __cdecl FUN_002164b0(void *, void *);
// equiv-conv: FUN_00216810 esi stack
extern "C" void __cdecl FUN_00216810(void * self, void* context) {
 if(((Container_216810 *)self)->root) ((Container_216810 *)self)->root->flags &= 0xfc;
 for(int i=0; i<((Container_216810 *)self)->entryCount; ++i) {
  Entry_216810& entry=((Container_216810 *)self)->entries[i];
  if(entry.type>=4 && (entry.node->flags&3)) FUN_002164b0(context,(Node *)(entry.node));
 }
 for(int j=0; j<((Container_216810 *)self)->clearedCount; ++j) {
  Node* n=((Container_216810 *)self)->cleared[j]; if(n) n->flags &= 0xfc;
 }
 for(int k=0; k<((Container_216810 *)self)->nodeCount; ++k) {
  Node* n=((Container_216810 *)self)->nodes[k]; if(n && (n->flags&3)) FUN_002164b0(context,(Node *)n);
 }
 for(int l=0; l<((Container_216810 *)self)->recordCount; ++l) {
  Node* n=((Container_216810 *)self)->records[l].node; if(n) n->flags &= 0xfc;
 }
}
