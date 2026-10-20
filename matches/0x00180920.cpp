// Same code shape as 0x0010d0f0 (propagated; names are from that function)
struct Tail_180920 {
    void Init();
};
struct PropStateByNameCondition_180920 {
    void* vptr;
    char pad[0x14];
    void Finish();
    void Run();
};
extern void* vftable_180920;
void PropStateByNameCondition_180920::Run() {
    vptr = &vftable_180920;
    ((Tail_180920*)((char*)this + 0x18))->Init();
    Finish();
}