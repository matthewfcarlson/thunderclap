extern "C" int FUN_00344e74(void*, int, void*, int, int);
extern int gA;
extern int gB;
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(int a);
    virtual int vfunc_1(int a);
};
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(int a);
};
int TrackFactoryCasterTemplate::vfunc_0(int a) {
    return (FUN_00344e74((void*)a, 0, &gA, (int)&gB, 0) != 0);
}
