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
class CGrappleFightNodeParentCondition {};
extern "C" int __cdecl helper(void*, int, void*, void*, int);
extern int a, b;
template <> int fight::ConditionFactoryCasterTemplate<CGrappleFightNodeParentCondition>::vfunc_0(void* p) {
    return helper(p, 0, &a, &b, 0) != 0;
}