typedef unsigned int uint;
extern "C" void *memcpy(void *, const void *, uint);
class ControllerBuffer {
public:
  virtual void vfunc_0();
  virtual void vfunc_1();
  virtual void vfunc_2();
  virtual void vfunc_3();
  virtual void vfunc_4();
  virtual void vfunc_5();
  virtual bool vfunc_6(void *dst, uint size);
  char p[0x18];
  int mRead;
  int mEnd;
  char **mData;
};
bool ControllerBuffer::vfunc_6(void *dst, uint size) {
  if (mRead == mEnd) return false;
  memcpy(dst, mData[mRead], size);
  return true;
}
