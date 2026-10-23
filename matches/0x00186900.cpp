extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
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
class PropAtRestCondition {};
} // namespace motion
} // namespace hulkfight
extern int DAT_00491ca8, DAT_004bd670;
template <>
int fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropAtRestCondition>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004bd670, 0) != 0;
}