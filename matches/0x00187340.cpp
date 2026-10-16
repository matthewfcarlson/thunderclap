namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class ShieldArcTrack {
  public:
    virtual void dummy();
};
} // namespace motion
} // namespace hulkfight
class Track {
  public:
    virtual void dummy();
};
namespace fight {
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::ShieldArcTrack>::vfunc_0(void* p) {
    return dynamic_cast<hulkfight::motion::ShieldArcTrack*>((Track*)p) != 0;
}