typedef unsigned __int64 U64;
extern U64 __cdecl Make(const char*, int, int);
class Registry {
  public:
    void Add(U64*, U64*, int, int);
};
extern Registry gRegistry;
extern "C" int __cdecl atexit(void(__cdecl*)());
extern void __cdecl Cleanup();
void __cdecl Init() {
    U64 first = Make("SeqCommandLogicOr", 0, 0);
    U64 second = Make("Runtime_Sequence", 0, 0);
    gRegistry.Add(&second, &first, 12, 4);
    atexit(Cleanup);
}