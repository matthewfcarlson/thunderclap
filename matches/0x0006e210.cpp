extern int gA, gB;
extern "C" void* __cdecl Find(void*, int, int*, int*, int);
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
class COrientTargetTrack {};
bool fight::TrackFactoryCasterTemplate<COrientTargetTrack>::vfunc_0(void* p) {
    return Find(p, 0, &gA, &gB, 0) != 0;
}
template class fight::TrackFactoryCasterTemplate<COrientTargetTrack>;
