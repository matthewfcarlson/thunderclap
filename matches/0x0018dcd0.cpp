struct Info {
    int x;
};
extern Info a, b;
extern int __cdecl check(void*, int, Info*, Info*, int);
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
class GrappleCaster : public ConditionFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
int fight::GrappleCaster::vfunc_0(void* p) {
    return check(p, 0, &a, &b, 0) != 0;
}