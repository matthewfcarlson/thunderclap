class Track {
  public:
    ~Track();
};
class Part_15ce20 {
  public:
    ~Part_15ce20();
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
    ((Part_15ce20*)((char*)this + 0x50))->~Part_15ce20();
    ((Part_15ce20*)((char*)this + 0x40))->~Part_15ce20();
    ((Part_15ce20*)((char*)this + 0x38))->~Part_15ce20();
    ((Part_15ce20*)((char*)this + 0x30))->~Part_15ce20();
    ((Part_15ce20*)((char*)this + 0x28))->~Part_15ce20();
    ((Track*)this)->~Track();
}
