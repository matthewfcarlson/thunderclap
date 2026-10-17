// STATUS: equivalent (tools/equiv.py level 3: 2936 inputs, branch coverage 0/0)
// pure3d::pddiBaseContext::vfunc_15 @ 0x0031e810
namespace pure3d {
struct MatrixEntry { char pad[8]; int index; unsigned char* data; };
class pddiBaseContext {
public:
  virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2();
  virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5();
  virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8();
  virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
  virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14();
  virtual void vfunc_15(int slot);
  char pad[0x1c]; MatrixEntry* entries[1];
};
void pddiBaseContext::vfunc_15(int slot) {
  MatrixEntry* entry = entries[slot];
  int next = entry->index + 1;
  unsigned char* destination = entry->data + next * 64;
  entry->index = next;
  unsigned int* dst = (unsigned int*)destination;
  unsigned int* src = (unsigned int*)(destination - 64);
  for (int i = 0; i < 16; ++i) dst[i] = src[i];
}
}