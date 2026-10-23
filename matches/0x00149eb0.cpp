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
class GrappleStruggleTrack {};
} // namespace motion
} // namespace hulkfight
extern int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern char DAT_0049850c[], DAT_004af500[];
template <>
bool fight::TrackFactoryCasterTemplate<hulkfight::motion::GrappleStruggleTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, DAT_0049850c, DAT_004af500, 0) != 0;
}