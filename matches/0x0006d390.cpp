extern char DAT_0049850c[];
extern char DAT_00498530[];
extern "C" int __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool Cast(void*);
    virtual void Other();
};
class CAIHintTrack;
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool Cast(void*);
    virtual void Other();
};
} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<fight::CAIHintTrack>::Cast(void* p) {
    return FUN_00344e74(p, 0, DAT_0049850c, DAT_00498530, 0) != 0;
}