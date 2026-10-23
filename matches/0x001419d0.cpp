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
class WallJumpTrack {};
} // namespace motion
} // namespace hulkfight
extern int DAT_0049850c, DAT_004ad630;
template <> int fight::TrackFactoryCasterTemplate<hulkfight::motion::WallJumpTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004ad630, 0) != 0;
}