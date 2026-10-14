extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
class Base {
  public:
    Base() throw();
    virtual void F0();
};
class AIHistoryCountTrack : public Base {
  public:
    AIHistoryCountTrack() throw();
    virtual void F0();
    char pad[8];
    int mField;
};
AIHistoryCountTrack::AIHistoryCountTrack() throw() : Base() {
    mField = 0;
}
