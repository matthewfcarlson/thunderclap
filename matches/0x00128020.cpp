extern int __cdecl FUN(void*, int, const void*, const void*, int);
extern "C" const char g1[];
extern "C" const char g2[];
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual int f0(void*);
    virtual int f1();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual int f0(void*);
    virtual int f1();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class TargetDistanceXZCondition;
}
} // namespace hulkfight
template <> int fight::ConditionFactoryCasterTemplate<hulkfight::ai::TargetDistanceXZCondition>::f0(void* p) {
    return FUN(p, 0, g1, g2, 0) != 0;
}
