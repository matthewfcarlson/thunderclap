extern int gA;
extern int gB;
extern "C" int __cdecl CastCheck(void*, int, const void*, const void*, int);
namespace hulkfight {
namespace motion {
class DriftToHulkTrack;
}
} // namespace hulkfight
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
template <> int TrackFactoryCasterTemplate<hulkfight::motion::DriftToHulkTrack>::vfunc_0(void* p) {
    return CastCheck(p, 0, &gA, &gB, 0) != 0;
}
} // namespace fight