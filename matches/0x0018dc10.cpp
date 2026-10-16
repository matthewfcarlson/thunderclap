namespace hulkfight {
namespace motion {
class TimerCondition;
}
} // namespace hulkfight
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
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern int a, b;
template <> int fight::ConditionFactoryCasterTemplate<hulkfight::motion::TimerCondition>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &a, &b, 0) != 0;
}