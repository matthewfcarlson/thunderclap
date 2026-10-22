class CTrack_68e20 {
  public:
    CTrack_68e20();
    virtual void VFn();
};

class CScrubberTrack : public CTrack_68e20 {
  public:
    CScrubberTrack();
    virtual void VFn2();
};

CScrubberTrack::CScrubberTrack() : CTrack_68e20() {}
