extern void* g_vftable[];
class Track_16ff30 {
  public:
    Track_16ff30();
    void* vptr;
};
class SnapToGroundTrack : public Track_16ff30 {
  public:
    SnapToGroundTrack();
    char pad[4];
    int m8;
    int mC;
};
SnapToGroundTrack::SnapToGroundTrack() : Track_16ff30() {
    *(void* volatile*)&vptr = (void*)((char*)g_vftable);
    mC = 0;
    m8 = 1;
}
