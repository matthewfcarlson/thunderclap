namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
class CCameraHintTrack;
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
} // namespace fight
extern "C" int __cdecl FUN_00344e74(const char*, int, const void*, const void*, int);
extern int DAT_0049850c;
extern int DAT_00498760;
bool fight::TrackFactoryCasterTemplate::vfunc_0(const char* s) {
    return FUN_00344e74(s, 0, &DAT_0049850c, &DAT_00498760, 0) != 0;
}