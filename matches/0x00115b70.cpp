extern char vftable;
class Helper {
  public:
    void Init();
    void Finish();
};
class MotionLocatorTrack {
  public:
    virtual ~MotionLocatorTrack();
    char pad[0x2c];
};
MotionLocatorTrack::~MotionLocatorTrack() {
    *(void**)this = &vftable;
    ((Helper*)((char*)this + 0x30))->Init();
    ((Helper*)this)->Finish();
}