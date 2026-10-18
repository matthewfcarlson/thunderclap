extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int);
struct Registry {
    char space[0x80];
    void FUN_002584d0(const __int64*, const __int64*, int, int);
};
extern Registry DAT_004e5d68;
extern "C" int __cdecl _atexit(void(__cdecl*)());
extern "C" void FUN_00364150();
void __cdecl FUN_0035f320() {
    __int64 mixBuss = FUN_002672f0("MixBuss", 0, 0);
    __int64 dataMix = FUN_002672f0("Data_Mix", 0, 0);
    DAT_004e5d68.FUN_002584d0(&dataMix, &mixBuss, 0x2c, 4);
    _atexit(FUN_00364150);
}
