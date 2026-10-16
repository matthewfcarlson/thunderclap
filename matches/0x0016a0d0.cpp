extern "C" int __cdecl Cast(void*, int, void*, void*, int);
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class TargetMotionStateCondition {};
} // namespace motion
} // namespace hulkfight
extern void* a;
extern void* b;
template <>
int fight::ConditionFactoryCasterTemplate<hulkfight::motion::TargetMotionStateCondition>::vfunc_0(void* p) {
    return Cast(p, 0, &a, &b, 0) != 0;
}