// cl-flags: /O2
class CSmartPropRemoveInstanceTrack;
int FUN_00344e74(int, int, void*, int, int);
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(int);
};
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(int);
};
bool TrackFactoryCasterTemplate::vfunc_0(int param) {
    return !(FUN_00344e74(param, 0, (void*)0x49850c, 0x49aad8, 0) == 0);
}
