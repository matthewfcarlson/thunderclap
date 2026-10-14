class Base {
  public:
    Base();
    virtual void VFn();
};

class CScrubberTrack : public Base {
  public:
    CScrubberTrack();
    virtual void VFn2();
};

CScrubberTrack::CScrubberTrack() : Base() {}
