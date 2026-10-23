struct TypeInfo {
    int x;
};
extern TypeInfo DAT_00491ca8, DAT_00493ad0;
extern "C" int __cdecl FUN_00344e74(void*, int, TypeInfo*, TypeInfo*, int);
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool Check(void*);
    virtual void Other();
};
class CMotionClimbAngleCondition;
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool Check(void*);
    virtual void Other();
};
template <> bool ConditionFactoryCasterTemplate<CMotionClimbAngleCondition>::Check(void* p) {
    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_00493ad0, 0) != 0;
}
} // namespace fight