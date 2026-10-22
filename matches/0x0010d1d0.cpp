extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
class Track_10d1d0 {
  public:
    Track_10d1d0() throw();
    virtual void F0();
};
class AIHistoryCountTrack : public Track_10d1d0 {
  public:
    AIHistoryCountTrack() throw();
    virtual void F0();
    char pad[8];
    int mField;
};
AIHistoryCountTrack::AIHistoryCountTrack() throw() : Track_10d1d0() {
    mField = 0;
}
