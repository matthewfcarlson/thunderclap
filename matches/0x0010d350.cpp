// Same code shape as 0x0010d0f0 (propagated; names are from that function)
struct Tail_10d350 {
    void Init();
};
struct KeywordWaitTrack_10d350 {
    void* vptr;
    char pad[0x14];
    void Finish();
    void Run();
};
extern void* vftable_10d350;
void KeywordWaitTrack_10d350::Run() {
    vptr = &vftable_10d350;
    ((Tail_10d350*)((char*)this + 0x18))->Init();
    Finish();
}