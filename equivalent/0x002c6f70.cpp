// STATUS: equivalent (tools/equiv.py level 3: 2978 inputs, branch coverage 0/0)
// FUN_002c6f70 @ 0x002c6f70
struct Value { short component[4]; };
struct Object {
 char pad[0x28];
 Value* values[1];
 void blend(int index, const Value* target, int bank, float fraction);
};
void Object::blend(int index, const Value* target, int bank, float fraction) {
 for (int i=0;i<4;++i) {
  short* destination = &values[bank][index].component[i];
  int difference = (int)target->component[i] - (int)*destination;
  if(i == 3) {
   short original = *destination;
   int delta = (int)(difference * fraction);
   *destination = (short)(original + delta);
  } else {
   int delta = (int)(difference * fraction);
   *destination = (short)(*destination + delta);
  }
 }
}
