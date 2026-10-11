extern "C" char DAT_003f98d0[];
extern "C" char DAT_003fb9c4[];
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
    *(unsigned long*)this = ((int)DAT_003fb9c4);
    part.Init();
    *(unsigned long*)this = ((int)DAT_003f98d0);
    Finish();
}
