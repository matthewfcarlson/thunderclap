// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00277d00 @ 0x00277d00
struct Interface_277d00 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(unsigned int a, unsigned int b, unsigned int c, unsigned int offset, unsigned int d, unsigned int e, unsigned int* result, unsigned int f);
};
struct Object {
 unsigned int field0;
 unsigned int base;
 unsigned int position;
 unsigned int fieldC;
 unsigned int end;
 unsigned int state;
 void FUN_00277d00(Interface_277d00* target, unsigned int a, unsigned int b, unsigned int c, unsigned int offset, unsigned int d, unsigned int e, unsigned int* result, unsigned int f);
};
void Object::FUN_00277d00(Interface_277d00* target, unsigned int a, unsigned int b, unsigned int c, unsigned int offset, unsigned int d, unsigned int e, unsigned int* result, unsigned int f) {
 target->slot12(a,b,c,base+offset,d,e,result,f);
 unsigned int value = *result + offset;
 position = value;
 end = value;
 state = 0;
}
