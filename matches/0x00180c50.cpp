// Same code shape as 0x0010d0f0 (propagated; names are from that function)
struct Tail_180c50 {
    void Init();
};
struct PropSetStateByNameTrack_180c50 {
    void* vptr;
    char pad[0x14];
    void Finish();
    void Run();
};
extern void* vftable_180c50;
void PropSetStateByNameTrack_180c50::Run() {
    vptr = &vftable_180c50;
    ((Tail_180c50*)((char*)this + 0x18))->Init();
    Finish();
}