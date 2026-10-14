// Same code shape as 0x0026d820 (propagated; names are from that function)
typedef void(__stdcall* InitFn)(void*);
extern InitFn gInit_26d840;
void FUN_0026d820(void* param_1) {
    gInit_26d840(param_1);
}