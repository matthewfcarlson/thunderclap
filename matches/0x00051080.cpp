struct TypeInfo {
    int x;
};
extern TypeInfo a, b;
extern "C" int __cdecl cast(void*, int, TypeInfo*, TypeInfo*, int);
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
    return cast(p, 0, &a, &b, 0) != 0;
}
} // namespace fight