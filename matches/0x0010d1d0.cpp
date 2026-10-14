extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
class Base_10d1d0 {
  public:
    Base_10d1d0() throw();
    virtual void F0();
};
class AIHistoryCountTrack : public Base_10d1d0 {
  public:
    AIHistoryCountTrack() throw();
    virtual void F0();
    char pad[8];
    int mField;
};
AIHistoryCountTrack::AIHistoryCountTrack() throw() : Base_10d1d0() {
    mField = 0;
}
