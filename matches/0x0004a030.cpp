extern int vtableA;
extern int vtableB;
class Part {
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
    Part part;
    void Run();
    void Finish();
};
void CCharacterTemplateVariationCondition::Run() {
    *(int*)this = (int)&vtableA;
    part.Init();
    *(int*)this = (int)&vtableB;
    Finish();
}