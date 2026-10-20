// Same code shape as 0x0004a030 (propagated; names are from that function)
#include "compat/ptr.h"
extern int vtableA;
extern int vtableB;
class Part_49f50 {
  public:
    void Init();
};
class CCondition {
  public:
    virtual void F();
};
class CCharacterTemplateCondition_49f50 : public CCondition {
  public:
    char pad[12];
    Part_49f50 part;
    void Run();
    void Finish();
};
void CCharacterTemplateCondition_49f50::Run() {
    *(hulk_intptr*)this = (hulk_intptr)&vtableA;
    part.Init();
    *(hulk_intptr*)this = (hulk_intptr)&vtableB;
    Finish();
}