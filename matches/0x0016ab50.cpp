namespace fight {
class ConditionFactory {
  public:
    virtual ~ConditionFactory() throw();
};
template <class T> class ConditionFactoryTemplate : public ConditionFactory {};
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(ConditionFactory*);
    virtual void vfunc_1();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(ConditionFactory*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class RageModeStateCondition;
} // namespace motion
} // namespace hulkfight
// the original asks whether a factory is the RageModeStateCondition one: dynamic_cast to
// fight::ConditionFactoryTemplate<hulkfight::motion::RageModeStateCondition> (RTTI 0x004b77d0) from fight::ConditionFactory
template <>
bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::RageModeStateCondition>::vfunc_0(
    fight::ConditionFactory* p) {
    return dynamic_cast<fight::ConditionFactoryTemplate<hulkfight::motion::RageModeStateCondition>*>(p) != 0;
}
