extern void* ParamValue_vftable;
extern void __fastcall InitParamValue(void*);
void __fastcall FUN_00234780(void* self) { *(void**)self = &ParamValue_vftable; InitParamValue((char*)self + 8); }