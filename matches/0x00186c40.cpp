extern "C" int __cdecl check(void*, int, void*, void*, int);
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
};
} // namespace fight
namespace hulkfight {
namespace motion {
class CSMPropIsCharacterCondition;
}
} // namespace hulkfight
template <>
int fight::ConditionFactoryCasterTemplate<hulkfight::motion::CSMPropIsCharacterCondition>::vfunc_0(void* p) {
    return check(p, 0, &a, &b, 0) != 0;
}