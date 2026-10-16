class Base {
  public:
    virtual void f();
    virtual ~Base() throw();
};
class SnapToGroundTrack : public Base {
  public:
    virtual ~SnapToGroundTrack() throw();
};
SnapToGroundTrack::~SnapToGroundTrack() throw() {}