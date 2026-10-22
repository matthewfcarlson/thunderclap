class CCondition_4a000 {
  public:
    CCondition_4a000(int);
    virtual void v();
    char pad[8];
};
class Member {
  public:
    Member();
};
class CCharacterTemplateVariationCondition : public CCondition_4a000 {
  public:
    CCharacterTemplateVariationCondition();
    virtual void v();
    int x;
    Member m;
};
CCharacterTemplateVariationCondition::CCharacterTemplateVariationCondition() : CCondition_4a000(0), x(0), m() {}