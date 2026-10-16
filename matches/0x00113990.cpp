namespace fight {
class ConditionFactoryCaster {
  public:
    virtual void dummy();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {};
} // namespace fight
namespace hulkfight {
namespace ai {
class PropsToChuckCondition;
}
} // namespace hulkfight
class Owner {
  public:
    void Set(void*);
};
void* Find(const char*, fight::ConditionFactoryCaster*);
void FUN_00113990(Owner* owner, const char* name) {
    fight::ConditionFactoryCasterTemplate<hulkfight::ai::PropsToChuckCondition> caster;
    owner->Set(Find(name, &caster));
}