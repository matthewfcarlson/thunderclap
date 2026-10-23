extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern int DAT_0049850c, DAT_0049a0d4;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
bool TrackFactoryCasterTemplate::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_0049a0d4, 0) != 0;
}
} // namespace fight