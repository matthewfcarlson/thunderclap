extern char vftable_115b70;
class MotionTargetTrack_115b70 {
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
    *(void**)this = &vftable_115b70;
    ((MotionTargetTrack_115b70*)((char*)this + 0x30))->Init();
    ((MotionTargetTrack_115b70*)this)->Finish();
}