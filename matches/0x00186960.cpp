struct TypeInfo {
    int x;
};
extern TypeInfo a, b;
extern "C" int __cdecl cast(void*, int, TypeInfo*, TypeInfo*, int);
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
class PropIsAttachedCondition {};
} // namespace motion
} // namespace hulkfight
template <>
int fight::ConditionFactoryCasterTemplate<hulkfight::motion::PropIsAttachedCondition>::vfunc_0(void* p) {
    return cast(p, 0, &a, &b, 0) != 0;
}