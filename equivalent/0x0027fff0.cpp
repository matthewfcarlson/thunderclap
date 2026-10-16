// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 20/20)
// FUN_0027fff0 @ 0x0027fff0
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"

struct Object;
struct Entry_27fff0 { unsigned a,b; Object* object; };
struct Container_27fff0 { char pad[0x3c]; Entry_27fff0* begin; Entry_27fff0* end; };
struct Object {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual int kind();
 virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual int subtype();
 char pad[0x40]; Container_27fff0* container; char pad2[0x10]; float value;
 void FUN_002a3be0(int, float);
};
void __stdcall FUN_0027fff0(Object* object, float value) {
 union { float f; unsigned u; } delta;
 delta.f = value - DAT_003f32dc; delta.u &= 0x7fffffff;
 if (delta.f <= DAT_0042c46c) return;
 if (object->kind() == 4) {
  Container_27fff0* container = object->container;
  unsigned count = (unsigned char)(container->end - container->begin);
  for (unsigned i=0; i<count; ++i) {
   Object* child = container->begin[(unsigned char)i].object;
   if (!child) continue;
   if (child->subtype()==4) {
    child->FUN_002a3be0(8,value); child->FUN_002a3be0(9,value); child->FUN_002a3be0(11,value);
   } else if (child->subtype()==8) child->value=value;
  }
 } else if (object->kind()==1) {
  if (object->subtype()==4) {
   object->FUN_002a3be0(8,value); object->FUN_002a3be0(9,value); object->FUN_002a3be0(11,value);
  } else if(object->subtype()==8) object->value=value;
 }
}
