namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class AnimationLinkedTrack {};
} // namespace motion
} // namespace hulkfight
extern "C" int __cdecl check(void*, int, void*, void*, int);
extern void* a;
extern void* b;
template <> int fight::TrackFactoryCasterTemplate<hulkfight::motion::AnimationLinkedTrack>::vfunc_0(void* p) {
    return check(p, 0, &a, &b, 0) != 0;
}