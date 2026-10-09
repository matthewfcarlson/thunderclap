class Part {
  public:
    void Init();
};
class CJointTrack {
  public:
    char pad[0x18];
    Part part;
    void Finish();
    void Init();
};
void CJointTrack::Init() {
    *(unsigned long*)this = 0x3fb9c4;
    part.Init();
    *(unsigned long*)this = 0x3f98d0;
    Finish();
}
