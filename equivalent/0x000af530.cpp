// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 14/14)
// FUN_000af530 @ 0x000af530
#include "decls/data/game/global.h"

extern float __cdecl FUN_000af420(float);
struct Value_af530 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5();
 virtual void set(float);
};
struct Provider_af530 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual Value_af530* get(unsigned);
};
struct Record_af530 { unsigned count; unsigned types[8]; float values[2]; Provider_af530* provider; };
struct Object {
 char pad0[8]; unsigned char enabled; char pad9[11]; Record_af530* records;
 void target(unsigned group,unsigned index,float value);
};
void Object::target(unsigned group,unsigned index,float value) {
 if (!enabled) return;
 Record_af530* base=records;
 Record_af530* record=&base[group];
 if(index>=record->count || !record->provider) return;
 unsigned type=record->types[index];
 if(type==2) {
  value=value>0.5f?1.0f:0.0f;
  Value_af530* dest=records[group].provider->get(index);
  dest->set(value);
 } else if(type==1) {
  if((*(unsigned char*)&DAT_004dda3d)) {
   float result=FUN_000af420(value);
   record->values[index]=result;
  } else {
   Value_af530* dest=records[group].provider->get(index);
   dest->set(value);
  }
 }
}
