// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 18/18)
// FUN_002ffc00 @ 0x002ffc00
struct Object { char pad[0x50]; unsigned char flag; };
struct Pair { Object* first; Object* second; unsigned int a,b,c; Pair* FUN_002f8ef0(Object*,Object*); };
struct Container { char pad[0x30]; Pair* begin; Pair* end; Pair* capacity; void FUN_002ffc00(Object* first, Object* second); };
void Container::FUN_002ffc00(Object* first,Object* second) {
 for(Pair* p=begin;p!=end;++p) {
  if((p->first==first || p->second==first) && (p->first==second || p->second==second)) return;
 }
 Pair local;
 Pair* source;
 if(first->flag) source=local.FUN_002f8ef0(first,second);
 else source=local.FUN_002f8ef0(second,first);
 Pair* dest=end;
 if((unsigned int)dest >= (unsigned int)capacity) return;
 end=(Pair*)((unsigned int)dest+sizeof(Pair));
 if(dest) {
 dest->first=source->first; dest->second=source->second; dest->a=source->a; dest->b=source->b; dest->c=source->c;
 }
}
