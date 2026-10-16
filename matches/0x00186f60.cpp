class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
class GrapplePropDamageCaster : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
extern const char a[], b[];
extern "C" int __cdecl check(const char*, int, const char*, const char*, int);
bool GrapplePropDamageCaster::vfunc_0(const char* s) {
    return check(s, 0, a, b, 0) != 0;
}