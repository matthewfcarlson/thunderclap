// Same code shape as 0x0004a030 (propagated; names are from that function)
#include "compat/ptr.h"
extern int vtableA;
extern int vtableB;
class Part_498a0 {
  public:
    void Init();
};
class CCondition {
  public:
    virtual void F();
};
class CSmartPropGrabbableNameCondition_498a0 : public CCondition {
  public:
    char pad[12];
    Part_498a0 part;
    void Run();
    void Finish();
};
void CSmartPropGrabbableNameCondition_498a0::Run() {
    *(hulk_intptr*)this = (hulk_intptr)&vtableA;
    part.Init();
    *(hulk_intptr*)this = (hulk_intptr)&vtableB;
    Finish();
}