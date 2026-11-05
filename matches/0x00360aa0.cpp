extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
unsigned __int64 FUN_002672f0(const char* s, int a, int b);
class Registry {
  public:
    void FUN_002584d0(__int64*, __int64*, int, int);
};
extern Registry registry;
void __cdecl FUN_00360aa0() {
    __int64 a = FUN_002672f0("SeqActionStream", 0, 0);
    __int64 b = FUN_002672f0("Runtime_Sequence", 0, 0);
    registry.FUN_002584d0(&b, &a, 44, 4);
    atexit(cleanup);
}