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
template <class T> bool TrackFactoryCasterTemplate<T>::vfunc_0(void* p) {
    return check(p, 0, &a, &b, 0) != 0;
}
} // namespace fight
namespace hulkfight {
namespace motion {
class CriticalMassDrainTrack {};
} // namespace motion
} // namespace hulkfight
template bool fight::TrackFactoryCasterTemplate<hulkfight::motion::CriticalMassDrainTrack>::vfunc_0(void*);