extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
class Track_14e110 {
  public:
    Track_14e110();
    void* vptr;
};
class ClearFightParamsHitRecordTrack_14e110 : public Track_14e110 {
  public:
    ClearFightParamsHitRecordTrack_14e110();
    char pad[4];
    int mA;
    int mB;
};
ClearFightParamsHitRecordTrack_14e110::ClearFightParamsHitRecordTrack_14e110() {
    vptr = g_vftable;
    _ReadWriteBarrier();
    mB = 0;
    mA = 1;
}
