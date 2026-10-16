class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
extern "C" int __cdecl check(const char*, int, const void*, const void*, int);
extern int a, b;
class StatBeginTrialCaster : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
bool StatBeginTrialCaster::vfunc_0(const char* name) {
    return check(name, 0, &a, &b, 0) != 0;
}