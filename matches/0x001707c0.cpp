// Same code shape as 0x0010d0f0 (propagated; names are from that function)
struct Tail_1707c0 {
    void Init();
};
struct PushOutTrack_1707c0 {
    void* vptr;
    char pad[0x14];
    void Finish();
    void Run();
};
extern void* vftable_1707c0;
void PushOutTrack_1707c0::Run() {
    vptr = &vftable_1707c0;
    ((Tail_1707c0*)((char*)this + 0x18))->Init();
    Finish();
}