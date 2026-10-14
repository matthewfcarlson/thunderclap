class Base_68e20 {
  public:
    Base_68e20();
    virtual void VFn();
};

class CScrubberTrack : public Base_68e20 {
  public:
    CScrubberTrack();
    virtual void VFn2();
};

CScrubberTrack::CScrubberTrack() : Base_68e20() {}
