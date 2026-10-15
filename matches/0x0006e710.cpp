extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern int g49850c;
extern int g49b088;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(int);
    virtual int vfunc_1();
};
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(int a);
};
int TrackFactoryCasterTemplate::vfunc_0(int a) {
    return (int)FUN_00344e74((void*)a, 0, (void*)&g49850c, (void*)&g49b088, 0) != 0;
}
} // namespace fight
