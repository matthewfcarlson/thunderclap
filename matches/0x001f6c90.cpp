// Same code shape as 0x001bc510 (propagated; names are from that function)
struct Obj_1f6c90 {
    void DoThing();
    void Finish();
};
Obj_1f6c90* __cdecl GetObj();
extern "C" void FUN_001bc510(void) {
    Obj_1f6c90* p = GetObj();
    p->DoThing();
    p = GetObj();
    p->Finish();
}
