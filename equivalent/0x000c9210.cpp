// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_000c9210 @ 0x000c9210
struct Vec { float x,y,z; };
struct Source { int id; Vec position; char pad[24]; char data[24]; };
struct Result { int active; char pad[48]; int sourceIndex; };
struct Object {
 char pad[0x258]; Source sources[128]; Result results[32];
 int FUN_000c8200(int value, void* data, Vec position, Vec a, Vec b);
 int FUN_000c9210(int index, int value, Vec a, Vec b);
};
int Object::FUN_000c9210(int index, int value, Vec a, Vec b) {
 Source* source = 0;
 if (index >= 0 && index < 128 && sources[index].id != -1) source = &sources[index];
 if (!source) return -1;
 int result = FUN_000c8200(value, source->data, source->position, a, b);
 if (result != -1) {
  Result* entry = 0;
  if (result >= 0 && result < 32 && results[result].active != 0) entry = &results[result];
  entry->sourceIndex = index;
 }
 return result;
}