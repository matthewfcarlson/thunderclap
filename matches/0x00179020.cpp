extern int gA, gB;
extern "C" int __cdecl check(void*, int, const int*, const int*, int);
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
} // namespace fight
namespace hulkfight {
namespace motion {
class SyncToLocatorTrack;
}
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::SyncToLocatorTrack>::vfunc_0(void* p) {
    return check(p, 0, &gA, &gB, 0) != 0;
}
