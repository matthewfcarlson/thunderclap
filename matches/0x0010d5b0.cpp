// Same code shape as 0x0010d0f0 (propagated; names are from that function)
struct Tail_10d5b0 {
    void Init();
};
struct SemaphoreWaitTrack_10d5b0 {
    void* vptr;
    char pad[0x14];
    void Finish();
    void Run();
};
extern void* vftable_10d5b0;
void SemaphoreWaitTrack_10d5b0::Run() {
    vptr = &vftable_10d5b0;
    ((Tail_10d5b0*)((char*)this + 0x18))->Init();
    Finish();
}