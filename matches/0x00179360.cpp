extern int DAT_0049850c;
extern int DAT_004ba410;
extern "C" int __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
namespace hulkfight {
namespace motion {
class DriftToHulkTrack;
}
} // namespace hulkfight
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
template <> int TrackFactoryCasterTemplate<hulkfight::motion::DriftToHulkTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004ba410, 0) != 0;
}
} // namespace fight