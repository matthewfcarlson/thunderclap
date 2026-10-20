// STATUS: equivalent (tools/equiv.py level 3: 63 inputs, branch coverage 20/20)
// pure3d::pddiBaseContext::vfunc_100 @ 0x0031e610
#include "compat/ptr.h"
void* __cdecl FUN_0008d690(hulk_uintptr);
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
namespace math { struct Matrix { char data[64]; void FUN_0022b980(); }; }
namespace pure3d {
template<class T> struct pddiStack { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); int capacity; int top; T* data; };
struct pddiMatrixStack : pddiStack<math::Matrix> { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); };
struct pddiBaseContext { char pad[32]; pddiMatrixStack* stacks[5]; void vfunc_100(); };
void pddiBaseContext::vfunc_100() {
 for(int s=0;s<5;++s) {
  void* memory=FUN_0008d690(16);
  pddiMatrixStack* stack=0;
  if(memory) {
   pddiStack<math::Matrix>* base=new(memory) pddiStack<math::Matrix>;
   math::Matrix* data=(math::Matrix*)FUN_0008d690(s==0?2048:128);
   base->data=data; base->top=0; base->capacity=s==0?32:2;
   stack=new(memory) pddiMatrixStack;
   int i=0;
   do { stack->data[i].FUN_0022b980(); ++i; } while(i<stack->capacity);
  }
  stacks[s]=stack;
 }
}
}