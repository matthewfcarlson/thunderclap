extern int gA;
extern int gB;
extern int __cdecl Check(void*, int, void*, void*, int);
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
class CGrappleSizeCondition {};
template <> bool fight::ConditionFactoryCasterTemplate<CGrappleSizeCondition>::vfunc_0(void* p) {
    return Check(p, 0, &gA, &gB, 0) != 0;
}
