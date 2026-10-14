extern void* g_vftable[];
class Base {
  public:
    Base();
    void* vptr;
};
class SnapToGroundTrack : public Base {
  public:
    SnapToGroundTrack();
    char pad[4];
    int m8;
    int mC;
};
SnapToGroundTrack::SnapToGroundTrack() : Base() {
    *(void* volatile*)&vptr = (void*)((char*)g_vftable);
    mC = 0;
    m8 = 1;
}
