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
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern int DAT_0049850c, DAT_004b3198;
template <class T> bool fight::TrackFactoryCasterTemplate<T>::vfunc_0(void* t) {
    return FUN_00344e74(t, 0, &DAT_0049850c, &DAT_004b3198, 0) != 0;
}
template bool fight::TrackFactoryCasterTemplate<hulkfight::motion::HitOrientToPushbackTrack>::vfunc_0(void*);