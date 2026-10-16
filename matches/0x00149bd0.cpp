extern "C" int __cdecl match(void*, void*, void*, void*, int);
extern int a, b;
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
class GrappleAttachJointCondition {};
} // namespace motion
} // namespace hulkfight
template <>
bool fight::ConditionFactoryCasterTemplate<hulkfight::motion::GrappleAttachJointCondition>::vfunc_0(void* p) {
    return match(p, 0, &a, &b, 0) != 0;
}