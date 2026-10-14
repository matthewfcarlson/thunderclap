struct Obj_1bc510 {
    void DoThing();
    void Finish();
};
Obj_1bc510* __cdecl GetObj();
extern "C" void FUN_001bc510(void) {
    Obj_1bc510* p = GetObj();
    p->DoThing();
    p = GetObj();
    p->Finish();
}
