class Track_6b1e0 {
  public:
    virtual ~Track_6b1e0() throw();
};
class CTrack : public Track_6b1e0 {
  public:
    virtual ~CTrack() throw();
};
CTrack::~CTrack() throw() {}