extern "C" int __cdecl check(void*, int, const void*, const void*, int);
extern int data1;
extern int data2;
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
namespace hulkfight {
namespace motion {
class FootPivotTrack;
}
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::FootPivotTrack>::vfunc_0(void* p) {
    return check(p, 0, &data1, &data2, 0) != 0;
}