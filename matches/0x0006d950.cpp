class CGrappleDamageTrack;
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(int owner);
    virtual bool vfunc_1(int owner);
};
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(int owner);
};
int FUN_00344e74(int owner, int a, int b, int c, int d);
bool TrackFactoryCasterTemplate::vfunc_0(int owner) {
    return FUN_00344e74(owner, 0, 0x49850c, 0x499170, 0) != 0;
}
