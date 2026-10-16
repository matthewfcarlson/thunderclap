extern "C" int __cdecl Check(void*, int, void*, void*, int);
extern void* a;
extern void* b;
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
class GrappleExecuteTrack;
}
} // namespace hulkfight
template <> int fight::TrackFactoryCasterTemplate<hulkfight::motion::GrappleExecuteTrack>::vfunc_0(void* p) {
    return Check(p, 0, &a, &b, 0) != 0;
}