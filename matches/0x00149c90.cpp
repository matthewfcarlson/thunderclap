extern "C" int __cdecl FindType(void*, int, void*, void*, int);
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
};
} // namespace fight
namespace hulkfight {
namespace motion {
class CivilianAttachedCondition {};
} // namespace motion
} // namespace hulkfight
extern void* a;
extern void* b;
template <>
bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CivilianAttachedCondition>::vfunc_0(void* p) {
    return FindType(p, 0, &a, &b, 0) != 0;
}