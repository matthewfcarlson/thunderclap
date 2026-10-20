// Same code shape as 0x0010d0f0 (propagated; names are from that function)
struct Tail_171010 {
    void Init();
};
struct FootPivotTrack_171010 {
    void* vptr;
    char pad[0x14];
    void Finish();
    void Run();
};
extern void* vftable_171010;
void FootPivotTrack_171010::Run() {
    vptr = &vftable_171010;
    ((Tail_171010*)((char*)this + 0x18))->Init();
    Finish();
}