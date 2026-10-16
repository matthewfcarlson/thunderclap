extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern int data1, data2;
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
class GrappleLocomotionSteerTrack {};
} // namespace motion
} // namespace hulkfight
template <>
int fight::TrackFactoryCasterTemplate<hulkfight::motion::GrappleLocomotionSteerTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &data1, &data2, 0) != 0;
}