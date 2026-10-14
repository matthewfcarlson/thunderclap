extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
void* __cdecl FUN_00236d40();
class Base_180ca0 {
  public:
    void* vptr;
    Base_180ca0();
};
class PropActorThinkingTrack : public Base_180ca0 {
  public:
    char pad[8];
    int mC;
    char m10;
    PropActorThinkingTrack();
};
PropActorThinkingTrack::PropActorThinkingTrack() : Base_180ca0() {
    mC = 0;
    m10 = 0;
    vptr = g_vftable;
}
