typedef unsigned int size_t;
void* __cdecl operator new(size_t) throw();
namespace fight {
class TrackFactory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void* vfunc_5();
};
} // namespace fight
namespace hulkfight {
namespace motion {
class BaseTrack {
  public:
    BaseTrack() throw();
    virtual void a();
    int x;
    int y;
    int z;
};
class SnapToGroundTrack : public BaseTrack {
  public:
    SnapToGroundTrack() throw();
    virtual void a();
};
SnapToGroundTrack::SnapToGroundTrack() throw() {
    z = 0;
    y = 1;
}
} // namespace motion
} // namespace hulkfight
void* fight::TrackFactory::vfunc_5() {
    return new hulkfight::motion::SnapToGroundTrack;
}