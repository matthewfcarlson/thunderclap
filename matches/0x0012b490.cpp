// Same code shape as 0x0010d0f0 (propagated; names are from that function)
struct Tail_12b490 {
    void Init();
};
struct ThreatDistanceCondition_12b490 {
    void* vptr;
    char pad[0x14];
    void Finish();
    void Run();
};
extern void* vftable_12b490;
void ThreatDistanceCondition_12b490::Run() {
    vptr = &vftable_12b490;
    ((Tail_12b490*)((char*)this + 0x18))->Init();
    Finish();
}