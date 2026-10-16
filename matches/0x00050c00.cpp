struct TypeDesc;
extern TypeDesc a, b;
extern "C" void* __cdecl cast(void*, int, TypeDesc*, TypeDesc*, int);
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
};
bool ConditionFactoryCasterTemplate::vfunc_0(void* y) {
    return cast(y, 0, &a, &b, 0) != 0;
}
} // namespace fight