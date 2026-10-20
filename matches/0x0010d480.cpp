// Same code shape as 0x0010d0f0 (propagated; names are from that function)
struct Tail_10d480 {
    void Init();
};
struct AIHistorySetTrack_10d480 {
    void* vptr;
    char pad[0x14];
    void Finish();
    void Run();
};
extern void* vftable_10d480;
void AIHistorySetTrack_10d480::Run() {
    vptr = &vftable_10d480;
    ((Tail_10d480*)((char*)this + 0x18))->Init();
    Finish();
}