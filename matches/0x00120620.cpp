extern "C" int __cdecl Compare(void*, void*, void*, void*, void*);
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
};
} // namespace fight
namespace hulkfight {
namespace ai {
class PathLocatorTestCondition {};
} // namespace ai
} // namespace hulkfight
extern void* gA;
extern void* gB;
template <>
int fight::ConditionFactoryCasterTemplate<hulkfight::ai::PathLocatorTestCondition>::vfunc_0(void* p) {
    return Compare(p, 0, &gA, &gB, 0) != 0;
}