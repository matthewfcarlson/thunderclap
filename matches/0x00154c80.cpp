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
class HitOrientToPushbackTrack {};
} // namespace motion
} // namespace hulkfight
extern "C" int __cdecl Cast(void*, int, void*, void*, int);
extern int g1, g2;
template <class T> bool fight::TrackFactoryCasterTemplate<T>::vfunc_0(void* t) {
    return Cast(t, 0, &g1, &g2, 0) != 0;
}
template bool fight::TrackFactoryCasterTemplate<hulkfight::motion::HitOrientToPushbackTrack>::vfunc_0(void*);