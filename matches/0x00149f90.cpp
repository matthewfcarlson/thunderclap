extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern void* DAT_0049850c;
extern void* DAT_004af668;
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
class CivilianAttachTrack {};
} // namespace motion
} // namespace hulkfight
template <> int fight::TrackFactoryCasterTemplate<hulkfight::motion::CivilianAttachTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004af668, 0) != 0;
}
template class fight::TrackFactoryCasterTemplate<hulkfight::motion::CivilianAttachTrack>;