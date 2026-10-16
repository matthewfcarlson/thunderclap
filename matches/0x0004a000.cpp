class Base {
  public:
    Base(int);
    virtual void v();
    char pad[8];
};
class Member {
  public:
    Member();
};
class CCharacterTemplateVariationCondition : public Base {
  public:
    CCharacterTemplateVariationCondition();
    virtual void v();
    int x;
    Member m;
};
CCharacterTemplateVariationCondition::CCharacterTemplateVariationCondition() : Base(0), x(0), m() {}