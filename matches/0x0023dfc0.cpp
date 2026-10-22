extern void* g_vftable[];
class Track_23dfc0 {
  public:
    void* vptr;
    Track_23dfc0() throw();
};
class WaitTrack : public Track_23dfc0 {
  public:
    char pad[8];
    int m0c;
    int m10;
    int m14;
    WaitTrack() throw();
};
WaitTrack::WaitTrack() throw() : Track_23dfc0() {
    m0c = 0;
    m10 = 0;
    m14 = 0;
    vptr = g_vftable;
}
