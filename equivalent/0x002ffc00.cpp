// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 18/18)
// FUN_002ffc00 @ 0x002ffc00
struct Object { char pad[0x50]; unsigned char flag; };
struct Pair_2ffc00 { Object* first; Object* second; unsigned int a,b,c; Pair_2ffc00* FUN_002f8ef0(Object*,Object*); };
struct Container_2ffc00 { char pad[0x30]; Pair_2ffc00* begin; Pair_2ffc00* end; Pair_2ffc00* capacity; void FUN_002ffc00(Object* first, Object* second); };
void Container_2ffc00::FUN_002ffc00(Object* first,Object* second) {
 for(Pair_2ffc00* p=begin;p!=end;++p) {
  if((p->first==first || p->second==first) && (p->first==second || p->second==second)) return;
 }
 Pair_2ffc00 local;
 Pair_2ffc00* source;
 if(first->flag) source=local.FUN_002f8ef0(first,second);
 else source=local.FUN_002f8ef0(second,first);
 Pair_2ffc00* dest=end;
 if((unsigned int)dest >= (unsigned int)capacity) return;
 end=(Pair_2ffc00*)((unsigned int)dest+sizeof(Pair_2ffc00));
 if(dest) {
 dest->first=source->first; dest->second=source->second; dest->a=source->a; dest->b=source->b; dest->c=source->c;
 }
}
