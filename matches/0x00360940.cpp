extern "C" void __cdecl FUN_00364530();
extern "C" int __cdecl _atexit(void (*)(void));
struct SeqEventVarPitchRandType_360940 {
    void Run();
};
extern SeqEventVarPitchRandType_360940 g_cleanup;
void FUN_00360940() {
    g_cleanup.Run();
    _atexit(FUN_00364530);
}
