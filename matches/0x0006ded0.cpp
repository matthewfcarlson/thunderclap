namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
class TrackFactoryCasterTemplate_CInvincibleTrack : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
} // namespace fight
extern "C" int __cdecl FUN_00344e74(const char*, int, const void*, const void*, int);
extern const int DAT_0049850c;
extern const int DAT_00499e40;
bool fight::TrackFactoryCasterTemplate_CInvincibleTrack::vfunc_0(const char* name) {
    return FUN_00344e74(name, 0, &DAT_0049850c, &DAT_00499e40, 0) != 0;
}