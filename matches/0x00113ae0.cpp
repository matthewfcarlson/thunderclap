namespace hulkfight {
namespace ai {
class PropsToSuckCondition;
}
} // namespace hulkfight
namespace fight {
template <class T> class ConditionFactoryCasterTemplate {
  public:
    virtual void Cast();
};
} // namespace fight
class Obj {
  public:
    void Do(void*);
};
extern "C" void* Lookup(void*, fight::ConditionFactoryCasterTemplate<hulkfight::ai::PropsToSuckCondition>*);
void Func(Obj* obj, void* b) {
    fight::ConditionFactoryCasterTemplate<hulkfight::ai::PropsToSuckCondition> caster;
    obj->Do(Lookup(b, &caster));
}