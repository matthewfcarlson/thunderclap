extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
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
extern void* DAT_00491ca8;
extern void* DAT_004af148;
template <>
bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::CivilianAttachedCondition>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004af148, 0) != 0;
}