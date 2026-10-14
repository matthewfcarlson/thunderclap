// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 14/14)
// FUN_000af530 @ 0x000af530
extern unsigned char DAT_004dda3d;
extern float __cdecl FUN_000af420(float);
struct Value {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5();
 virtual void set(float);
};
struct Provider {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual Value* get(unsigned);
};
struct Record { unsigned count; unsigned types[8]; float values[2]; Provider* provider; };
struct Object {
 char pad0[8]; unsigned char enabled; char pad9[11]; Record* records;
 void target(unsigned group,unsigned index,float value);
};
void Object::target(unsigned group,unsigned index,float value) {
 if (!enabled) return;
 Record* base=records;
 Record* record=&base[group];
 if(index>=record->count || !record->provider) return;
 unsigned type=record->types[index];
 if(type==2) {
  value=value>0.5f?1.0f:0.0f;
  Value* dest=records[group].provider->get(index);
  dest->set(value);
 } else if(type==1) {
  if(DAT_004dda3d) {
   float result=FUN_000af420(value);
   record->values[index]=result;
  } else {
   Value* dest=records[group].provider->get(index);
   dest->set(value);
  }
 }
}
