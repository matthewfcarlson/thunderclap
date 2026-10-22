class Track_16ff70 {
  public:
    virtual void f();
    virtual ~Track_16ff70() throw();
};
class SnapToGroundTrack : public Track_16ff70 {
  public:
    virtual ~SnapToGroundTrack() throw();
};
SnapToGroundTrack::~SnapToGroundTrack() throw() {}