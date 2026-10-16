namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class GrappleOrientationCaster : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
};
} // namespace fight
extern "C" int __cdecl Find(void*, int, void*, void*, int);
extern int a, b;
bool fight::GrappleOrientationCaster::vfunc_0(void* p) {
    return Find(p, 0, &a, &b, 0) != 0;
}