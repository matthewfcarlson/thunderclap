extern "C" int __cdecl Check(void*, int, const void*, const void*, int);
extern int a;
extern int b;
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
class AnimationChargeTrack;
}
} // namespace hulkfight
template <>
bool fight::TrackFactoryCasterTemplate<hulkfight::motion::AnimationChargeTrack>::vfunc_0(void* p) {
    return Check(p, 0, &a, &b, 0) != 0;
}