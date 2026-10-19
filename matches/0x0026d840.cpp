// Same code shape as 0x0026d820 (propagated; names are from that function)
typedef int(__stdcall* InitFn)(void*);
extern InitFn gInit_26d840;
int FUN_0026d840(void* param_1) {
    return gInit_26d840(param_1);
}