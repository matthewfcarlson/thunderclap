class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
extern "C" int __cdecl FUN_00344e74(const char*, int, const void*, const void*, int);
extern int DAT_0049850c, DAT_004aab18;
class StatBeginTrialCaster : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
bool StatBeginTrialCaster::vfunc_0(const char* name) {
    return FUN_00344e74(name, 0, &DAT_0049850c, &DAT_004aab18, 0) != 0;
}