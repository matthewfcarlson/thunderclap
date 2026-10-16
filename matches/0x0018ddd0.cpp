extern "C" int __cdecl Check(void*, int, void*, void*, int);
extern char a, b;
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
};
} // namespace fight
namespace hulkfight {
namespace motion {
class TimerSetTrack;
}
} // namespace hulkfight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::TimerSetTrack>::vfunc_0(void* p) {
    return Check(p, 0, &a, &b, 0) != 0;
}