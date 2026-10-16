extern "C" int __cdecl CastCheck(void*, void*, void*, void*, void*);
extern char a, b;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool Check(void*);
    virtual void Other();
};
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool Check(void*);
    virtual void Other();
};
} // namespace fight
bool fight::TrackFactoryCasterTemplate::Check(void* p) {
    return CastCheck(p, 0, &a, &b, 0) != 0;
}