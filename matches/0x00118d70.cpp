extern "C" int FindTrack(void*, int, void*, void*, int);
extern char gOne;
extern char gTwo;
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
namespace ai {
class MotionChaseTrack;
}
} // namespace hulkfight
bool fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionChaseTrack>::vfunc_0(void* p) {
    return FindTrack(p, 0, &gOne, &gTwo, 0) != 0;
}
