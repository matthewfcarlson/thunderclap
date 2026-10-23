extern int __cdecl FUN_00344e74(void*, void*, void*, void*, void*);
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
namespace motion {
class GrappleHitReactionTrack;
}
} // namespace hulkfight
extern void* DAT_0049850c;
extern void* DAT_004af720;
template <>
bool fight::TrackFactoryCasterTemplate<hulkfight::motion::GrappleHitReactionTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004af720, 0) != 0;
}