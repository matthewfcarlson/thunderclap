int __cdecl Check(void*, int, const void*, const void*, int);
extern int g1, g2;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class GrappleThrowTrack {};
} // namespace motion
} // namespace hulkfight
int fight::TrackFactoryCasterTemplate<hulkfight::motion::GrappleThrowTrack>::vfunc_0(void* p) {
    return Check(p, 0, &g1, &g2, 0) != 0;
}
