extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
class Track_147650 {
  public:
    void* vptr;
    int m4;
    int m8;
    Track_147650();
};
class CivilianAttachTrack_147650 : public Track_147650 {
  public:
    int mc;
    CivilianAttachTrack_147650();
};
CivilianAttachTrack_147650::CivilianAttachTrack_147650() : Track_147650() {
    vptr = g_vftable;
    mc = 0;
}
