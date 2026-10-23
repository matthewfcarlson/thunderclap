namespace fight {
class TrackFactory {
  public:
    virtual void dummy();
};
template <class T> class TrackFactoryTemplate : public TrackFactory {};
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class ShieldArcTrack;
} // namespace motion
} // namespace hulkfight
namespace fight {
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
// the original asks whether a factory is the ShieldArcTrack one: dynamic_cast from fight::TrackFactory (RTTI 0x0049850c)
// to fight::TrackFactoryTemplate<hulkfight::motion::ShieldArcTrack> (0x004be460)
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::motion::ShieldArcTrack>::vfunc_0(void* p) {
    return dynamic_cast<fight::TrackFactoryTemplate<hulkfight::motion::ShieldArcTrack>*>((fight::TrackFactory*)p) != 0;
}
