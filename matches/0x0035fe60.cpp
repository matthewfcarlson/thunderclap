typedef __int64 I64;
extern "C" I64 __cdecl make(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl cleanup();
extern const char first[];
extern const char second[];
class Registry {
  public:
    void set(I64*, I64*, int, int);
};
extern Registry registry;
void __cdecl target() {
    I64 a = make(first, 0, 0);
    I64 b = make(second, 0, 0);
    registry.set(&b, &a, 16, 4);
    atexit(cleanup);
}