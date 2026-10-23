namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
} // namespace fight
extern "C" int __cdecl FUN_00344e74(const char*, int, const void*, const void*, int);
namespace fight {
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class CivilianDetachTrack {};
} // namespace motion
} // namespace hulkfight
extern const void* DAT_0049850c;
extern const void* DAT_004af398;
template <>
bool fight::TrackFactoryCasterTemplate<hulkfight::motion::CivilianDetachTrack>::vfunc_0(const char* s) {
    return FUN_00344e74(s, 0, &DAT_0049850c, &DAT_004af398, 0) != 0;
}