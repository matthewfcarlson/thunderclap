extern void* g_vftable[];
class Base {
  public:
    void* vptr;
    Base() throw();
};
class WaitTrack : public Base {
  public:
    char pad[8];
    int m0c;
    int m10;
    int m14;
    WaitTrack() throw();
};
WaitTrack::WaitTrack() throw() : Base() {
    m0c = 0;
    m10 = 0;
    m14 = 0;
    vptr = g_vftable;
}
