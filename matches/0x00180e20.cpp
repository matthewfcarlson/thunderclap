// Same code shape as 0x0010d0f0 (propagated; names are from that function)
struct Tail_180e20 {
    void Init();
};
struct PropAnimationTrack_180e20 {
    void* vptr;
    char pad[0x14];
    void Finish();
    void Run();
};
extern void* vftable_180e20;
void PropAnimationTrack_180e20::Run() {
    vptr = &vftable_180e20;
    ((Tail_180e20*)((char*)this + 0x18))->Init();
    Finish();
}