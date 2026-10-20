// STATUS: equivalent (tools/equiv.py level 3: 57 inputs, branch coverage 6/6)
// FUN_0031f0a0 @ 0x0031f0a0
#include "compat/ptr.h"
void* __cdecl FUN_0008d690(hulk_uintptr bytes);
namespace pure3d {
class pddiStencilState {
public:
 virtual void dummy();
 char data[32];
};
template<class T> class pddiStack {
public:
 virtual void dummy();
 int count;
 int top;
 T* entries;
 pddiStack(int n);
};
}
template<> pure3d::pddiStack<pure3d::pddiStencilState>::pddiStack(int n) {
 pddiStencilState* p = (pddiStencilState*)FUN_0008d690((unsigned int)n * 36);
 if (p && (int)((unsigned int)n-1)>=0) {
  unsigned int i=0;
  do { p[i].pddiStencilState::pddiStencilState(); ++i; } while (i!=(unsigned int)n);
 }
 count=n;
 entries=p;
 top=0;
}
