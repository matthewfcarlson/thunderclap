// Same code shape as 0x0010d0f0 (propagated; names are from that function)
struct Tail_16fee0 {
    void Init();
};
struct RestPoseTrack_16fee0 {
    void* vptr;
    char pad[0x14];
    void Finish();
    void Run();
};
extern void* vftable_16fee0;
void RestPoseTrack_16fee0::Run() {
    vptr = &vftable_16fee0;
    ((Tail_16fee0*)((char*)this + 0x18))->Init();
    Finish();
}