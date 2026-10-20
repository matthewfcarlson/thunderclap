// Same code shape as 0x0010d0f0 (propagated; names are from that function)
struct Tail_170030 {
    void Init();
};
struct JointRelativeTrack_170030 {
    void* vptr;
    char pad[0x14];
    void Finish();
    void Run();
};
extern void* vftable_170030;
void JointRelativeTrack_170030::Run() {
    vptr = &vftable_170030;
    ((Tail_170030*)((char*)this + 0x18))->Init();
    Finish();
}