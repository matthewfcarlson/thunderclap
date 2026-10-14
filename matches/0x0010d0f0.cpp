struct Tail_10d0f0 {
    void Init();
};
struct SemaphoreClearTrack {
    void* vptr;
    char pad[0x14];
    void Finish();
    void Run();
};
extern void* vftable_10d0f0;
void SemaphoreClearTrack::Run() {
    vptr = &vftable_10d0f0;
    ((Tail_10d0f0*)((char*)this + 0x18))->Init();
    Finish();
}