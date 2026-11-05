// Same code shape as 0x0026d820
extern "C" void(__stdcall* DAT_003f2c88)(void*);   // kernel import slot RtlLeaveCriticalSection (the caller reads eax)
extern "C" int FUN_0026d840(void* arg) {
    return ((int(__stdcall*)(void*))DAT_003f2c88)(arg);
}
