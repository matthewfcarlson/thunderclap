// Same code shape as 0x0026d820
extern "C" void(__stdcall* DAT_003f2c8c)(void*);   // kernel import slot RtlEnterCriticalSection
extern "C" void FUN_0026d850(void* arg) {
    DAT_003f2c8c(arg);
}
