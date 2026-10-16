extern int gOne;
extern int gTwo;
extern "C" void* __cdecl Search(void*, int, int*, int*, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
class GroundCaster : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
bool GroundCaster::vfunc_0(void* p) {
    return Search(p, 0, &gOne, &gTwo, 0) != 0;
}
} // namespace fight