extern char gA;
extern char gB;
extern "C" int __cdecl check(void*, int, const void*, const void*, int);
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
namespace ai {
class FaceMotionTrack;
}
} // namespace hulkfight
template <> int fight::TrackFactoryCasterTemplate<hulkfight::ai::FaceMotionTrack>::vfunc_0(void* p) {
    return check(p, 0, &gA, &gB, 0) != 0;
}
