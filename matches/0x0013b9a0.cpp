extern "C" int __cdecl check(void*, int, void*, void*, int);
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
class FrameReachedCondition {};
} // namespace motion
} // namespace hulkfight
extern void* a;
extern void* b;
template <>
bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::FrameReachedCondition>::vfunc_0(void* p) {
    return check(p, 0, &a, &b, 0) != 0;
}