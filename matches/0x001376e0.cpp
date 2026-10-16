extern "C" int __cdecl FUN_00344e74(void*, void*, void*, void*, void*);
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
class AirToGroundTargetTrack {};
} // namespace motion
} // namespace hulkfight
extern char data1, data2;
template <>
int fight::TrackFactoryCasterTemplate<hulkfight::motion::AirToGroundTargetTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &data1, &data2, 0) != 0;
}