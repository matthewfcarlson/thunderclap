extern "C" int __cdecl FUN_00344e74(int a, int b, int c, int d, int e);
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(int a);
};
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(int a);
};
int TrackFactoryCasterTemplate::vfunc_0(int a) {
    return FUN_00344e74(a, 0, 0x49850c, 0x4a5a40, 0) != 0;
}
