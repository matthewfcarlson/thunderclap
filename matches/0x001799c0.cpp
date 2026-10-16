namespace hulkfight {
namespace motion {
class TeleportToLocatorTrack;
}
} // namespace hulkfight
extern int a, b;
extern "C" int __cdecl cast(void*, int, const int*, const int*, int);
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
template <> bool TrackFactoryCasterTemplate<hulkfight::motion::TeleportToLocatorTrack>::vfunc_0(void* p) {
    return cast(p, 0, &a, &b, 0) != 0;
}
} // namespace fight