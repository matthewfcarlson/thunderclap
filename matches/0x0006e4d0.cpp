extern "C" int __cdecl check(void*, int, void*, void*, int);
extern int gA, gB;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool test(void*) = 0;
    virtual void other() = 0;
};
class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool test(void*);
    virtual void other();
};
} // namespace fight
bool fight::TrackFactoryCasterTemplate::test(void* p) {
    return check(p, 0, &gA, &gB, 0) != 0;
}