// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 40/40)
// FUN_0025da00 @ 0x0025da00
struct TypeInfo_25da00 { unsigned int data; }; extern TypeInfo_25da00 DAT_004c7eb4, DAT_004c7ed4;
extern void* __cdecl FUN_00344e74(void*, int, TypeInfo_25da00*, TypeInfo_25da00*, int);
extern bool __cdecl FUN_0024b200(void*);
extern int __cdecl FUN_0024afe0(void*);
extern void __cdecl FUN_0024ba70(void*, int, int);
struct Owner_25da00;
struct Node;
struct Link_25da00 { Node* asNodePadding; }; 
struct Node { virtual void destroy(int); virtual void finish(Owner_25da00*); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual int status(Owner_25da00*); virtual void update(Owner_25da00*); Link_25da00* next; };
extern void __cdecl FUN_0025d640(Link_25da00**, Node*);
struct Owner_25da00 { char pad0[0x34]; void* resource; char pad38[8]; Link_25da00* head; char pad44[4]; unsigned int count; Link_25da00* other; char pad50[4]; signed char index; char pad55[3]; int state; unsigned char active; bool run(); };
bool Owner_25da00::run() {
 Node* node = head ? reinterpret_cast<Node*>(reinterpret_cast<char*>(head)-4) : 0;
 while(node) {
  bool before = FUN_00344e74(node,0,&DAT_004c7eb4,&DAT_004c7ed4,0)!=0;
  node->update(this);
  Link_25da00* next = node->next;
  node = next ? reinterpret_cast<Node*>(reinterpret_cast<char*>(next)-4) : 0;
  bool after = FUN_00344e74(node,0,&DAT_004c7eb4,&DAT_004c7ed4,0)!=0;
  if(before!=after) break;
 }
 if(resource && !active && (!other || reinterpret_cast<char*>(other)-4==0 || (unsigned int)(int(index)+1)<count)) {
  if(!FUN_0024b200(resource) && FUN_0024afe0(resource)) {
   void* r=resource; active=1; FUN_0024ba70(r,0,0);
  }
 }
 node = head ? reinterpret_cast<Node*>(reinterpret_cast<char*>(head)-4) : 0;
 if(node) {
  int result=node->status(this);
  if(result==0 && state==3) {
   FUN_0025d640(&head,node); --count; node->destroy(1); return true;
  }
  if(result==2 && state==3) node->finish(this);
 }
 return false;
}