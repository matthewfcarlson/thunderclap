// STATUS: equivalent (tools/equiv.py level 3: 3013 inputs, branch coverage 12/12)
// fight::Reference::vfunc_9 @ 0x0023c410
#include "decls/data/engine/fight.h"

typedef unsigned __int64 Key_23c410;
struct Object {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12();
 virtual bool slot13(); virtual Key_23c410 slot14(); virtual void slot15(); virtual void slot16(unsigned long low,unsigned long high); virtual void slot17();
};
struct Context { char pad[0x28]; unsigned long value; };
struct Links_23c410 { void FUN_00236ec0(); void FUN_00237160(unsigned long low,unsigned long high,unsigned long value,Object* obj); };
struct Binding_23c410 { void FUN_002340b0(unsigned long low,unsigned long high,Object* obj); };
namespace fight {
struct Reference {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual bool vfunc_9(Context*,Object*,unsigned long);
 char pad[0x14]; Links_23c410 links; char pad2[0xf]; Binding_23c410 binding;
 void FUN_00233c50(Context*,Object*,unsigned long);
 void FUN_002337c0(Context*,Object*,int);
};
bool Reference::vfunc_9(Context* context,Object* object,unsigned long arg) {
 if (!object->slot13()) return false;
 Key_23c410 key=object->slot14();
 if ((unsigned long)key != (*(unsigned long*)&DAT_004e5b10) || (unsigned long)(key>>32)!=(*(unsigned long*)((char*)&DAT_004e5b10 + 4))) return false;
 object->slot16((*(unsigned long*)&DAT_004e5b10),(*(unsigned long*)((char*)&DAT_004e5b10 + 4)));
 FUN_00233c50(context,object,arg);
 binding.FUN_002340b0((*(unsigned long*)&DAT_004e5b98),(*(unsigned long*)&DAT_004e5b9c),object);
 links.FUN_00236ec0();
 if (object->slot13()) {
  key=object->slot14();
  if ((unsigned long)key==(*(unsigned long*)&DAT_004e5b20) && (unsigned long)(key>>32)==(*(unsigned long*)((char*)&DAT_004e5b20 + 4)))
   links.FUN_00237160((*(unsigned long*)&DAT_004e5b20),(*(unsigned long*)((char*)&DAT_004e5b20 + 4)),context->value,object);
 }
 FUN_002337c0(context,object,-1);
 object->slot17();
 return true;
}
}
