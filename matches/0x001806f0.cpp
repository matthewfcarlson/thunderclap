// Same code shape as 0x0010d0f0 (propagated; names are from that function)
struct Tail_1806f0 {
    void Init();
};
struct SemaphoreClearTrack {
    void* vptr;
    char pad[0x14];
    void Finish();
    void Run();
};
extern void* vftable_1806f0;
void SemaphoreClearTrack::Run() {
    vptr = &vftable_1806f0;
    ((Tail_1806f0*)((char*)this + 0x18))->Init();
    Finish();
}