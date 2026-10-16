namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class CollisionTargetNameCondition;
}
} // namespace hulkfight
extern int g1, g2;
extern "C" void* cast(void*, int, int*, int*, int);
template <>
bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CollisionTargetNameCondition>::vfunc_0(
    void* p) {
    return cast(p, 0, &g1, &g2, 0) != 0;
}