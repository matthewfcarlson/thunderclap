// Same code shape as 0x0010d0f0 (propagated; names are from that function)
struct Tail_14dd20 {
    void Init();
};
struct SemaphoreClearTrack {
    void* vptr;
    char pad[0x14];
    void Finish();
    void Run();
};
extern void* vftable_14dd20;
void SemaphoreClearTrack::Run() {
    vptr = &vftable_14dd20;
    ((Tail_14dd20*)((char*)this + 0x18))->Init();
    Finish();
}