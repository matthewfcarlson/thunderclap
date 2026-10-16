extern "C" int __cdecl Check(void*, int, void*, void*, int);
extern void* gA;
extern void* gB;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
};
} // namespace fight
namespace hulkfight {
namespace ai {
class MotionStopTrack;
}
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionStopTrack>::vfunc_0(void* p) {
    return Check(p, 0, &gA, &gB, 0) != 0;
}