typedef __int64 I64;
extern "C" I64 __cdecl lookup(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
class Registry {
  public:
    void registerThings(I64*, I64*, int, int);
};
extern Registry registry;
void __cdecl FUN_003601e0() {
    I64 first = lookup("SeqActionExpression", 0, 0);
    I64 second = lookup("Runtime_Sequence", 0, 0);
    registry.registerThings(&second, &first, 16, 4);
    atexit(cleanup);
}