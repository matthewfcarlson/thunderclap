extern void* ParamValue_vftable;
extern "C" void __fastcall FUN_0027af50(void*);
void __fastcall FUN_00234780(void* self) {
    *(void**)self = &ParamValue_vftable;
    FUN_0027af50((char*)self + 8);
}