extern char a[];
extern char b[];
extern "C" int __cdecl lookup(void*, int, const void*, const void*, int);
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
    return lookup(p, 0, a, b, 0) != 0;
}