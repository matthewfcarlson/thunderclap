extern char gOne[];
extern char gTwo[];
extern "C" void* __cdecl Find(void*, int, const char*, const char*, int);
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
class HitPushbackTrack {};
} // namespace motion
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::HitPushbackTrack>::vfunc_0(void* p) {
    return Find(p, 0, gOne, gTwo, 0) != 0;
}
