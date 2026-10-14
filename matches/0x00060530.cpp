extern "C" char DAT_003faa44[];
class Part_60530 {
  public:
    char pad[8];
    void Init();
};
class CMotionTrailTrack {
  public:
    virtual void V();
    char a[0x1c];
    Part_60530 p20;
    char b[8];
    Part_60530 p30;
    char c[0x28];
    Part_60530 p60;
    char d[0x40];
    Part_60530 pa8;
    void Finish();
    void Run();
};
void CMotionTrailTrack::Run() {
    *(int*)this = ((int)DAT_003faa44);
    pa8.Init();
    Part_60530* p = &p60;
    int i = 6;
    do {
        p = (Part_60530*)((char*)p - 8);
        p->Init();
        --i;
    } while (i != 0);
    p20.Init();
    Finish();
}