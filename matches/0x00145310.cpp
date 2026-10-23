namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(const char*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(const char*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class WorldDamageTrack {};
} // namespace motion
} // namespace hulkfight
extern "C" int __cdecl FUN_00344e74(const char*, int, const void*, const void*, int);
extern int DAT_0049850c;
extern int DAT_004ae040;
template <>
int fight::TrackFactoryCasterTemplate<hulkfight::motion::WorldDamageTrack>::vfunc_0(const char* s) {
    return FUN_00344e74(s, 0, &DAT_0049850c, &DAT_004ae040, 0) != 0;
}