#include "compat/ptr.h"
extern int vftable_2a1310;
class Sub_2a1310 {
  public:
    void Init();
};
class IRefCount_2a1310 {
  public:
    char pad[8];
    Sub_2a1310 sub;
    void Init();
};
void IRefCount_2a1310::Init() {
    sub.Init();
    *(hulk_intptr*)this = (hulk_intptr)&vftable_2a1310;
}