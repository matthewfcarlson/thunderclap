// Same code shape as 0x0004a030 (propagated; names are from that function)
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
class CCharacterTemplateVariationCondition : public CCondition {
  public:
    char pad[12];
    Part_49f50 part;
    void Run();
    void Finish();
};
void CCharacterTemplateVariationCondition::Run() {
    *(int*)this = (int)&vtableA;
    part.Init();
    *(int*)this = (int)&vtableB;
    Finish();
}