extern "C" int FUN_00344e74(int a, int b, int c, int d, int e);
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(int a);
    virtual int vfunc_1();
};
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(int a);
};
int TrackFactoryCasterTemplate::vfunc_0(int a) {
    return (int)(!!FUN_00344e74(a, 0, 0x49850c, 0x499fcc, 0));
}
