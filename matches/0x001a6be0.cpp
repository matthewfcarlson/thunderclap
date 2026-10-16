extern int a, b;
extern "C" int __cdecl check(void*, int, int*, int*, int);
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
namespace scenario {
class Event_PropTypeCondition;
}
} // namespace hulkfight
int fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_PropTypeCondition>::vfunc_0(void* p) {
    return check(p, 0, &a, &b, 0) != 0;
}
