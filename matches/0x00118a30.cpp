extern int g1;
extern int g2;
extern "C" int __cdecl compare(void*, int, int*, int*, int);
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
namespace ai {
class HasGroundPointExtendedCondition;
}
} // namespace hulkfight
template <>
bool fight::ConditionFactoryCasterTemplate<hulkfight::ai::HasGroundPointExtendedCondition>::vfunc_0(void* p) {
    return compare(p, 0, &g1, &g2, 0) != 0;
}
