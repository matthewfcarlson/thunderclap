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
class LocationCondition {};
} // namespace hulkfight
extern void* gOne;
extern void* gTwo;
extern "C" int __cdecl check(void*, int, void*, void*, int);
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::LocationCondition>::vfunc_0(void* p) {
    return check(p, 0, &gOne, &gTwo, 0) != 0;
}