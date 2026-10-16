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
extern "C" int __cdecl lookup(const char*, int, const void*, const void*, int);
extern int a;
extern int b;
bool fight::TrackFactoryCasterTemplate::vfunc_0(const char* s) {
    return lookup(s, 0, &a, &b, 0) != 0;
}