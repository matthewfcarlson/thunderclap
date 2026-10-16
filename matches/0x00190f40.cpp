extern const char gName1[];
extern const char gName2[];
extern "C" void* __cdecl FindTrack(void*, int, const char*, const char*, int);
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
class ImpulseVelocityTrack {};
} // namespace motion
} // namespace hulkfight
template <> int fight::TrackFactoryCasterTemplate<hulkfight::motion::ImpulseVelocityTrack>::vfunc_0(void* p) {
    return FindTrack(p, 0, gName1, gName2, 0) != 0;
}