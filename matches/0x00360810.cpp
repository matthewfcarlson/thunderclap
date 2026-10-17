extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int);
struct Registry {
    void FUN_002584d0(const __int64*, const __int64*, int, int);
};
extern "C" int __cdecl _atexit(void(__cdecl*)());
extern "C" void FUN_00364500();
extern "C" Registry DAT_004e6ff0;
void __cdecl FUN_00360810() {
    __int64 action = FUN_002672f0("SeqActionVarPosDist", 0, 0);
    __int64 runtime = FUN_002672f0("Runtime_Sequence", 0, 0);
    DAT_004e6ff0.FUN_002584d0(&runtime, &action, 16, 4);
    _atexit(FUN_00364500);
}