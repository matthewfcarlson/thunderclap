namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
};
} // namespace fight
namespace hulkfight {
namespace motion {
class AnimationTrack;
}
} // namespace hulkfight
extern int FUN_00344e74(void*, int, void*, void*, int);
extern int a;
extern int b;
int fight::TrackFactoryCasterTemplate<hulkfight::motion::AnimationTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &a, &b, 0) != 0;
}