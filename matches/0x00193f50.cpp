// Same code shape as 0x0010d0f0 (propagated; names are from that function)
struct Tail_193f50 {
    void Init();
};
struct MissilePunchTrack_193f50 {
    void* vptr;
    char pad[0x14];
    void Finish();
    void Run();
};
extern void* vftable_193f50;
void MissilePunchTrack_193f50::Run() {
    vptr = &vftable_193f50;
    ((Tail_193f50*)((char*)this + 0x18))->Init();
    Finish();
}