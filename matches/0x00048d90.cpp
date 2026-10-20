// Same code shape as 0x0004a030 (propagated; names are from that function)
#include "compat/ptr.h"
extern int vtableA;
extern int vtableB;
class Part_48d90 {
  public:
    void Init();
};
class CCondition {
  public:
    virtual void F();
};
class CNameFlagConditionBase_48d90 : public CCondition {
  public:
    char pad[12];
    Part_48d90 part;
    void Run();
    void Finish();
};
void CNameFlagConditionBase_48d90::Run() {
    *(hulk_intptr*)this = (hulk_intptr)&vtableA;
    part.Init();
    *(hulk_intptr*)this = (hulk_intptr)&vtableB;
    Finish();
}