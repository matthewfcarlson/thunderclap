class Track {};
extern void* gA;
extern void* gB;
extern "C" int __cdecl check(void*, int, void*, void*, int);
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
class JointTrackerTrack;
}
} // namespace hulkfight
template <> int fight::TrackFactoryCasterTemplate<hulkfight::motion::JointTrackerTrack>::vfunc_0(void* p) {
    return check(p, 0, &gA, &gB, 0) != 0;
}