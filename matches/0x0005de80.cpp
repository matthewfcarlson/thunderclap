class Part_5de80 {
  public:
    void Close();
    char pad[0x20];
};
class CStunAnimationTrack {
  public:
    virtual void V();
    char pad[0xC];
    Part_5de80 p10;
    Part_5de80 p30;
    ~CStunAnimationTrack();
    void Finish();
};
CStunAnimationTrack::~CStunAnimationTrack() {
    p30.Close();
    p10.Close();
    Finish();
}
