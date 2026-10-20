// STATUS: equivalent (tools/equiv.py level 3: 155 inputs, branch coverage 32/32)
// FUN_003010a0 @ 0x003010a0
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"

struct Object {
 virtual void addRef();
 char pad[0x4c];
 unsigned char flag50, flag51;
};
struct Service_3010a0 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
 virtual bool pair(Object*,Object*);
 virtual bool single(Object*);
};
struct Global_3010a0 { char pad[0x6c]; Service_3010a0* service; };
struct Pair_3010a0 { char data[20]; Pair_3010a0* FUN_002f8ef0(Object*, Object*); };
struct Queue_3010a0 { void FUN_002ee0c0(Pair_3010a0*); };
void __cdecl FUN_00300bc0(Object**,Object**,unsigned);
struct Container_3010a0 {
 Object** begin; Object** end; Object** capacity;
 char pad0[8];
 Object** specialEnd; Object** specialCapacity;
 char pad1[0x14];
 Queue_3010a0 queue;
 void target(Object* object, unsigned flags);
};
void Container_3010a0::target(Object* object, unsigned flags) {
 if (!(flags & 8)) {
  if ((*(Global_3010a0**)&DAT_0055547c)->service->single(object)) {
   if ((hulk_uintptr)specialEnd < (hulk_uintptr)specialCapacity) {
    Object** slot=specialEnd; specialEnd=slot+1;
    if(slot) *slot=object;
   }
   object->addRef();
  }
  unsigned i=0;
  if ((unsigned)(end-begin)>0) {
   do {
    Object* other=begin[i];
    if ((*(Global_3010a0**)&DAT_0055547c)->service->pair(object,other)) {
     unsigned char a=object->flag50;
     if (!(a && other->flag50) && (object->flag51 || !other->flag50) && (other->flag51 || !a)) {
      if(a) { Pair_3010a0 p; queue.FUN_002ee0c0(p.FUN_002f8ef0(object,other)); }
      else { Pair_3010a0 p; queue.FUN_002ee0c0(p.FUN_002f8ef0(other,object)); }
     }
    }
    ++i;
   } while(i < (unsigned)(end-begin));
  }
 }
 if ((hulk_uintptr)end < (hulk_uintptr)capacity) {
  Object** slot=end; end=slot+1;
  if(slot) *slot=object;
 }
 FUN_00300bc0(begin,end,(unsigned)(end-begin));
 object->addRef();
}
