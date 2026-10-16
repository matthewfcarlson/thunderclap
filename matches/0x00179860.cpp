namespace hulkfight {
namespace motion {
class SuckInPropsTrack;
}
} // namespace hulkfight
extern int a, b;
extern "C" int __cdecl check(void*, int, const void*, const void*, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
template <> bool TrackFactoryCasterTemplate<hulkfight::motion::SuckInPropsTrack>::vfunc_0(void* p) {
    return check(p, 0, &a, &b, 0) != 0;
}
} // namespace fight