// STATUS: equivalent (tools/equiv.py level 3: 440 inputs, branch coverage 10/10)
// FUN_002287b0 @ 0x002287b0
struct Entry { unsigned index; float weight; float value; };
struct Object {
 char pad0[0x30]; unsigned limit;
 char pad1[0x8b4-0x34]; unsigned count; Entry entries[1];
 void FUN_002287b0(unsigned index, float weight, float value);
};
void Object::FUN_002287b0(unsigned index, float weight, float value) {
 if (weight <= 0.0f) return;
 if (index >= limit) return;
 for (unsigned i=0;i<count;++i) {
  if (entries[i].index == index) {
   double sum = (double)weight + entries[i].weight;
   entries[i].weight = (float)sum;
   double ratio = (double)weight / sum;
   entries[i].value = (float)((1.0f - ratio) * entries[i].value + ratio * value);
   return;
  }
 }
 entries[count].index = index;
 entries[count].weight = weight;
 entries[count].value = value;
 ++count;
}