class Base {
  public:
    virtual ~Base() throw();
};
class CTrack : public Base {
  public:
    virtual ~CTrack() throw();
};
CTrack::~CTrack() throw() {}