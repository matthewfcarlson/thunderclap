extern int FUN_00344e74(void* a, int b, void* c, void* d, int e);
extern char DAT_0049850c[];
extern char DAT_00499750[];
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void* a);
    virtual void vfunc_1();
};
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void* a);
    virtual void vfunc_1();
};
bool TrackFactoryCasterTemplate::vfunc_0(void* a) {
    return (int)FUN_00344e74(a, 0, DAT_0049850c, DAT_00499750, 0) != 0;
}
