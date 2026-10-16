namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(const char*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace ai {
class TokenTrack {};
} // namespace ai
} // namespace hulkfight
extern "C" int __cdecl FUN_00344e74(const char*, int, void*, void*, int);
extern int a, b;
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::ai::TokenTrack>::vfunc_0(const char* s) {
    return FUN_00344e74(s, 0, &a, &b, 0) != 0;
}