void* __cdecl operator new(unsigned int) throw();
namespace hulkfight {
namespace ai {
class BaseCondition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    char pad[8];
    BaseCondition(int) throw();
};
class PropsToChuckCondition : public BaseCondition {
  public:
    PropsToChuckCondition() throw();
    int fieldC;
    int field10;
};
PropsToChuckCondition::PropsToChuckCondition() throw() : BaseCondition(0) {
    fieldC = 0;
    field10 = -1;
}
} // namespace ai
} // namespace hulkfight
namespace fight {
template <class T> class ConditionFactoryTemplate {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual hulkfight::ai::BaseCondition* vfunc_5();
};
template <>
hulkfight::ai::BaseCondition* ConditionFactoryTemplate<hulkfight::ai::PropsToChuckCondition>::vfunc_5() {
    return new hulkfight::ai::PropsToChuckCondition;
}
} // namespace fight