// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_001fa7d0 @ 0x001fa7d0
struct Entry_1fa7d0 { char data[0x58]; void FUN_001f9810(int value); };
struct Object {
 char pad0[0x10];
 int items[256];
 int count;
 char pad414[0x44];
 int state;
 char pad45c[0x28c];
 Entry_1fa7d0 entries[1];
 bool FUN_001f9040(int input, int item);
 bool FUN_001f87e0(int input, int item, int* index);
 void FUN_001fa1c0(int input, int item);
 void FUN_001fa3a0(int index);
 bool FUN_001fa7d0(int input, int value);
};
bool Object::FUN_001fa7d0(int input, int value) {
 if (!input || state != 2) return false;
 bool result = false;
 for (int i = 0; i < count; ++i) {
  int index = -1;
  bool first = FUN_001f9040(input, items[i]);
  bool second = FUN_001f87e0(input, items[i], &index);
  if (first) {
   if (second) entries[index].FUN_001f9810(value);
   else FUN_001fa1c0(input, items[i]);
   result = true;
  } else if (second) FUN_001fa3a0(index);
 }
 return result;
}