class Part { public: void Close(); char pad[0x20]; };
class CStunAnimationTrack {
public:
  virtual void V();
  char pad[0xC];
  Part p10;
  Part p30;
  ~CStunAnimationTrack();
  void Finish();
};
CStunAnimationTrack::~CStunAnimationTrack() {
  p30.Close();
  p10.Close();
  Finish();
}
