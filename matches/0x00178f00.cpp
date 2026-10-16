extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern int g1;
extern int g2;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual int vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual int vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class SnapToGroundTrack {};
} // namespace motion
} // namespace hulkfight
template <> int fight::TrackFactoryCasterTemplate<hulkfight::motion::SnapToGroundTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &g1, &g2, 0) != 0;
}