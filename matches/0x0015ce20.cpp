class Track {
  public:
    ~Track();
};
class Part {
  public:
    ~Part();
};
class LocomotionSteerTrack {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual ~LocomotionSteerTrack();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    char pad[0x50];
};
LocomotionSteerTrack::~LocomotionSteerTrack() {
    ((Part*)((char*)this + 0x50))->~Part();
    ((Part*)((char*)this + 0x40))->~Part();
    ((Part*)((char*)this + 0x38))->~Part();
    ((Part*)((char*)this + 0x30))->~Part();
    ((Part*)((char*)this + 0x28))->~Part();
    ((Track*)this)->~Track();
}
