extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
void* __cdecl FUN_00236d40();
class Base {
  public:
    void* vptr;
    Base();
};
class PropActorThinkingTrack : public Base {
  public:
    char pad[8];
    int mC;
    char m10;
    PropActorThinkingTrack();
};
PropActorThinkingTrack::PropActorThinkingTrack() : Base() {
    mC = 0;
    m10 = 0;
    vptr = g_vftable;
}
