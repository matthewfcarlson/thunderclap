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
class ClearFightParamsHitRecordTrack {};
} // namespace motion
} // namespace hulkfight
extern void* gA;
extern void* gB;
template <>
int fight::TrackFactoryCasterTemplate<hulkfight::motion::ClearFightParamsHitRecordTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &gA, &gB, 0) != 0;
}