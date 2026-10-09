// Same code shape as 0x001bc510 (propagated; names are from that function)
struct Obj { void DoThing(); void Finish(); };
Obj* __cdecl GetObj();
extern "C" void FUN_001bc510(void) {
    Obj* p = GetObj();
    p->DoThing();
    p = GetObj();
    p->Finish();
}
