extern char DAT_0049850c, DAT_004ba8b8;
extern "C" int __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
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
template <class T> int TrackFactoryCasterTemplate<T>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004ba8b8, 0) != 0;
}
} // namespace fight
namespace hulkfight {
namespace motion {
class SurfTrack {};
} // namespace motion
} // namespace hulkfight
template int fight::TrackFactoryCasterTemplate<hulkfight::motion::SurfTrack>::vfunc_0(void*);