class Actor;
class Track;
extern int __cdecl FUN_00344e74(void*, int, void*, void*, int);
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
class PropActorToPropTrack {};
} // namespace motion
} // namespace hulkfight
extern void* DAT_0049850c;
extern void* DAT_004bdca8;
template <> int fight::TrackFactoryCasterTemplate<hulkfight::motion::PropActorToPropTrack>::vfunc_0(void* x) {
    return FUN_00344e74(x, 0, &DAT_0049850c, &DAT_004bdca8, 0) != 0;
}