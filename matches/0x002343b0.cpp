class Base {
  public:
    Base();
    virtual void Fn();
};
class ConditionFactory : public Base {
  public:
    ConditionFactory();
};
ConditionFactory::ConditionFactory() {}
