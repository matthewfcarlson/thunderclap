extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
void* __cdecl FUN_00236d40();
class Track_180ca0 {
  public:
    void* vptr;
    Track_180ca0();
};
class PropActorThinkingTrack : public Track_180ca0 {
  public:
    char pad[8];
    int mC;
    char m10;
    PropActorThinkingTrack();
};
PropActorThinkingTrack::PropActorThinkingTrack() : Track_180ca0() {
    mC = 0;
    m10 = 0;
    vptr = g_vftable;
}
