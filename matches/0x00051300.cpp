extern "C" int __cdecl CastCheck(void*, int, void*, void*, int);
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
extern void* a;
extern void* b;
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
int ConditionFactoryCasterTemplate::vfunc_0(void* p) {
    return CastCheck(p, 0, &a, &b, 0) != 0;
}
} // namespace fight