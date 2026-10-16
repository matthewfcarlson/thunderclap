struct Info {
    int value;
};
extern Info a, b;
extern "C" int __cdecl check(void*, int, Info*, Info*, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
};
} // namespace fight
bool fight::TrackFactoryCasterTemplate::vfunc_0(void* p) {
    return check(p, 0, &a, &b, 0) != 0;
}