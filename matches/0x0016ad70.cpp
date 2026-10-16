extern "C" int __cdecl Check(void*, int, void*, void*, int);
extern int a, b;
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
class HealthCondition;
}
} // namespace hulkfight
template <> int fight::ConditionFactoryCasterTemplate<hulkfight::motion::HealthCondition>::vfunc_0(void* p) {
    return Check(p, 0, &a, &b, 0) != 0;
}