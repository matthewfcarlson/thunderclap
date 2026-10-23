extern int __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
extern "C" const char DAT_00491ca8[];
extern "C" const char DAT_004a8758[];
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
    return FUN_00344e74(p, 0, DAT_00491ca8, DAT_004a8758, 0) != 0;
}
