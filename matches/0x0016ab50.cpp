namespace fight {
class Condition {
  public:
    virtual ~Condition() throw();
};
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(Condition*);
    virtual void vfunc_1();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(Condition*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class RageModeStateCondition : public fight::Condition {};
} // namespace motion
} // namespace hulkfight
template <>
bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::RageModeStateCondition>::vfunc_0(
    fight::Condition* p) {
    return dynamic_cast<hulkfight::motion::RageModeStateCondition*>(p) != 0;
}