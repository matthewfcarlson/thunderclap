// STATUS: equivalent (tools/equiv.py level 3: 1590 inputs, branch coverage 14/14)
// FUN_001d6000 @ 0x001d6000
typedef unsigned int uint;
extern uint DAT_004e2428;
extern uint DAT_004e2420;
extern uint DAT_004e2424;
extern unsigned __int64 __cdecl FUN_0027b020(const char*);
extern int __cdecl FUN_00096600(const char*, const char*);
struct Property { uint low, high; const char* value; uint unused; };
struct Item { char pad[0x3c]; int count; Property* properties; };
struct Collection { char pad[0x1c]; Item** begin; Item** end; };
struct Object { char pad[0x90]; Collection* collection; bool check(int index); };
bool Object::check(int index) {
 uint low,high;
 if (!(DAT_004e2428 & 1)) {
  DAT_004e2428 |= 1;
  unsigned __int64 key = FUN_0027b020("climbable");
  low=(uint)key; high=(uint)(key>>32);
  DAT_004e2420=low; DAT_004e2424=high;
 } else { low=DAT_004e2420; high=DAT_004e2424; }
 if(index<0) return false;
 Collection* c=collection;
 int n=c->end-c->begin;
 if(index>=n) return false;
 Item* item=c->begin[index];
 int count=item->count;
 if(count<=0) return false;
 Property* p=item->properties;
 for(int i=0;i<count;++i,++p) {
  if(p->low==low && p->high==high) return FUN_00096600(p->value,"true")==0;
 }
 return false;
}