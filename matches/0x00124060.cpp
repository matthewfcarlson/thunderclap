namespace hulkfight {
namespace ai {
class TargetCondition {
  public:
    virtual ~TargetCondition() throw();
};
class TargetDistanceXZCondition : public TargetCondition {
  public:
    virtual ~TargetDistanceXZCondition() throw();
};
TargetDistanceXZCondition::~TargetDistanceXZCondition() throw() {}
} // namespace ai
} // namespace hulkfight
