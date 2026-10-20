#include "compat/ptr.h"
extern int vtableA;
extern int vtableB;
class Part_4a030 {
  public:
    void Init();
};
class CCondition {
  public:
    virtual void F();
};
class CCharacterTemplateVariationCondition : public CCondition {
  public:
    char pad[12];
    Part_4a030 part;
    void Run();
    void Finish();
};
void CCharacterTemplateVariationCondition::Run() {
    *(hulk_intptr*)this = (hulk_intptr)&vtableA;
    part.Init();
    *(hulk_intptr*)this = (hulk_intptr)&vtableB;
    Finish();
}