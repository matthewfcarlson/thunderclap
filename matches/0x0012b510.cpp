// Same code shape as 0x0010d0f0 (propagated; names are from that function)
struct Tail_12b510 {
    void Init();
};
struct ThreatAngleCondition_12b510 {
    void* vptr;
    char pad[0x14];
    void Finish();
    void Run();
};
extern void* vftable_12b510;
void ThreatAngleCondition_12b510::Run() {
    vptr = &vftable_12b510;
    ((Tail_12b510*)((char*)this + 0x18))->Init();
    Finish();
}