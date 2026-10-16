class CDriftTrack;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
} // namespace fight
extern int __cdecl FUN_00344e74(const char*, int, const void*, const void*, int);
extern int a, b;
bool fight::TrackFactoryCasterTemplate::vfunc_0(const char* s) {
    return FUN_00344e74(s, 0, &a, &b, 0) != 0;
}