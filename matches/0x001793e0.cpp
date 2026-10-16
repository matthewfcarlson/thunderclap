namespace hulkfight {
namespace motion {
class MotionStateTrack;
}
} // namespace hulkfight
extern int a, b;
extern "C" void* __cdecl Cast(void*, int, const void*, const void*, int);
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
template <> bool TrackFactoryCasterTemplate<hulkfight::motion::MotionStateTrack>::vfunc_0(void* p) {
    return Cast(p, 0, &a, &b, 0) != 0;
}
} // namespace fight