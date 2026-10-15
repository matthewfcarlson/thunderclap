extern "C" __int64 __cdecl Make(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl cleanup();
class Registry {
  public:
    void Register(__int64*, __int64*, int, int);
};
extern Registry registry;
struct Pair {
    __int64 a, b;
};
void __cdecl FUN_003609b0() {
    Pair p;
    p.a = Make("SeqActionVarPitch", 0, 0);
    p.b = Make("Runtime_Sequence", 0, 0);
    registry.Register(&p.b, &p.a, 16, 4);
    atexit(cleanup);
}