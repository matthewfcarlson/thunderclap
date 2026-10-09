class Part { public: char pad[8]; void Init(); };
class CMotionTrailTrack { public: virtual void V(); char a[0x1c]; Part p20; char b[8]; Part p30; char c[0x28]; Part p60; char d[0x40]; Part pa8; void Finish(); void Run(); };
void CMotionTrailTrack::Run() {
    *(int*)this = 0x3faa44;
    pa8.Init();
    Part* p = &p60;
    int i = 6;
    do { p = (Part*)((char*)p - 8); p->Init(); --i; } while (i != 0);
    p20.Init();
    Finish();
}