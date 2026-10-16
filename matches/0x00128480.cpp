struct Info {
    int x;
};
extern Info a, b;
extern "C" void* __cdecl lookup(void*, int, Info*, Info*, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool Make(void*);
    virtual void Other();
};
class Caster : public TrackFactoryCaster {
  public:
    virtual bool Make(void*);
    virtual void Other();
};
} // namespace fight
bool fight::Caster::Make(void* p) {
    return lookup(p, 0, &a, &b, 0) != 0;
}