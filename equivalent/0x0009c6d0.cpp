// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure4<CCameraManager,void,bool,bool,bool,bool>::vfunc_2 @ 0x0009c6d0
struct CCameraManager { void FUN_0009c6d0_placeholder(unsigned, unsigned, unsigned, unsigned); };
struct BoolArguments { unsigned char first; char pad0[3]; unsigned char second; char pad1[3]; unsigned char third; char pad2[3]; unsigned char fourth; };
struct Closure4 {
  virtual void vfunc_0();
  virtual void vfunc_1();
  virtual void vfunc_2(void* unused, BoolArguments* args, void* other);
  char padding[0x18];
  void (CCameraManager::*method)(unsigned, unsigned, unsigned, unsigned);
  CCameraManager* object;
};
void Closure4::vfunc_2(void* unused, BoolArguments* args, void* other) {
  unsigned first = ((unsigned)this & 0xffffff00U) | args->first;
  unsigned second = ((unsigned)args & 0xffffff00U) | args->second;
  (object->*method)(first, second, args->third, args->fourth);
}