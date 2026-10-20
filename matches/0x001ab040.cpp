// Same code shape as 0x0010d0f0 (propagated; names are from that function)
struct Tail_1ab040 {
    void Init();
};
struct Event_CharacterTemplateVariationCondition_1ab040 {
    void* vptr;
    char pad[0x14];
    void Finish();
    void Run();
};
extern void* vftable_1ab040;
void Event_CharacterTemplateVariationCondition_1ab040::Run() {
    vptr = &vftable_1ab040;
    ((Tail_1ab040*)((char*)this + 0x18))->Init();
    Finish();
}