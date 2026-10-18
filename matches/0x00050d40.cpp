class CGrappleFightNodeCondition;
extern "C" int __cdecl CastCheck(void*, int, void*, void*, int);
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
extern void* a;
extern void* b;
template <> bool fight::ConditionFactoryCasterTemplate<CGrappleFightNodeCondition>::vfunc_0(void* p) {
    return CastCheck(p, 0, &a, &b, 0) != 0;
}
