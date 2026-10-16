namespace hulkfight {
class ChapterMissionCondition {};
} // namespace hulkfight
namespace fight {
template <class T> class ConditionFactoryCasterTemplate {
  public:
    ConditionFactoryCasterTemplate();
    virtual void dummy();
};
template <>
ConditionFactoryCasterTemplate<hulkfight::ChapterMissionCondition>::ConditionFactoryCasterTemplate() {}
} // namespace fight